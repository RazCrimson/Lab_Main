import socket
import select
import random
import time


class TCPServer(object):
    BUFFER_SIZE = 2048

    def __init__(self, ip_address: str, port: int) -> None:
        self.ip_address = ip_address
        self.port = port
        self.socket = socket.socket(
            family=socket.AF_INET, type=socket.SOCK_STREAM)
        self.socket.bind((self.ip_address, self.port))
        super().__init__()
        print('Server Started!')

    def handle_client(self, window_size, no_of_frames, frame_drop_list):
        data = [x for x in range(2 * window_size)] * 100
        data = data[:no_of_frames]
        window_start_index = 0
        window_end_index = 0
        counter = 0
        timestamp = time.time()

        print('Press Ctrl + C Terminate')
        self.socket.listen()
        conn, addr = self.socket.accept()
        conn.setblocking(0)
        print(f'Connection from {addr}')

        try:

            while self.socket.fileno() != -1 and conn.fileno() != -1:

                # Checking for Timeout
                if time.time() - timestamp > 20:
                    timestamp = time.time()
                    window_end_index = window_start_index

                # Trasmitting frame if window is not full
                if window_end_index - window_start_index < window_size:
                    if window_end_index >= len(data):
                        conn.sendall(b'')
                        print('Data Transmission completed!')
                        raise KeyboardInterrupt
                    frame = data[window_end_index]
                    window_end_index += 1
                    if counter not in frame_drop_list:
                        conn.sendall(f'F{frame}'.encode('utf-8'))
                    counter += 1

                time.sleep(0.5)

                r, _, _ = select.select([conn], [], [], 0)
                if len(r) != 0:
                    msg_bytes = conn.recv(TCPServer.BUFFER_SIZE)
                    msg_string = msg_bytes.decode(
                        'utf-8').removesuffix('\n')
                    print(f'From Receiver : {msg_string}')

                    if msg_string == '':
                        raise KeyboardInterrupt

                    elif msg_string.startswith('NAK '):
                        msg_string = msg_string.removeprefix('NAK ')
                        nak_num = int(msg_string)
                        frame_index = (nak_num + 1 // window_size) + int(window_start_index % window_size) * window_size
                        frame = data[frame_index]
                        conn.sendall(f'F{frame}'.encode('utf-8'))                      
                        
                    elif msg_string.startswith('ACK '):
                        msg_string = msg_string.removeprefix('ACK ')
                        # Handling Acknowledgements
                        try:
                            ack_num = int(msg_string)
                            if ack_num == 0:
                                window_end_index = window_start_index
                            else:
                                window_start_index = ack_num + int(window_start_index / (2 * window_size)) * (2 * window_size) 
                                timestamp = time.time()
                        except ValueError:
                            pass

        except (KeyboardInterrupt, BrokenPipeError):
            conn.close()
            self.socket.close()


if __name__ == '__main__':
    port = int(input("Enter a port number(empty for default) : "))
    window_size = int(input("Enter a window size(empty for default) : "))
    frame_count = int(input("Enter a frames count(empty for default) : "))
    frames_to_drop = input("Enter the frames to drop seperated by commas : ")
    frame_drop_list = [int(num) for num in frames_to_drop.split(',')]

    server = TCPServer('127.0.0.1', port)
    server.handle_client(window_size, frame_count, frame_drop_list)