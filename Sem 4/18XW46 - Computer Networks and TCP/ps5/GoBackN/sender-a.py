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

    def handle_client(self, window_size):
        data = [f'F{x}'.encode('utf-8') for x in range(random.randint(50, 70))]
        window_start_index = 0
        window_end_index = -1
        timestamp = time.time()

        try:
            print('Press Ctrl + C Terminate')
            self.socket.listen()
            conn, addr = self.socket.accept()
            conn.setblocking(0)
            print(f'Connection from {addr}')

            while self.socket.fileno() != -1 and conn.fileno() != -1:

                # Checking for Timeout
                if time.time() - timestamp > 1000:
                    timestamp = time.time()
                    window_end_index = window_start_index

                # Trasmitting frame if window is not full
                if window_end_index - window_start_index + 1 < window_size:
                    window_end_index += 1
                    if window_end_index >= len(data):
                        conn.sendall(b'')
                        print('Data Transmission completed!')
                        raise KeyboardInterrupt
                    frame_to_send = data[window_end_index]
                    conn.sendall(frame_to_send)

                time.sleep(0.5)

                r, _, _ = select.select([conn], [], [], 0)
                if len(r) != 0:
                    msg_bytes = conn.recv(TCPServer.BUFFER_SIZE)
                    msg_string = msg_bytes.decode(
                        'utf-8').removesuffix('\n').removeprefix('ACK ')
                    print(f'Message from Receiver : {msg_string}')

                    if msg_string == '':
                        raise KeyboardInterrupt

                    # Handling Acknowledgements
                    try:
                        ack_num = int(msg_string)
                        if ack_num == 0:
                            window_end_index = window_start_index
                        elif abs(window_start_index) % window_size <= ack_num:
                            window_start_index = ack_num + \
                                int(window_start_index /
                                    window_size)*window_size
                        elif (window_end_index + 1) == ack_num:
                            window_start_index = ack_num + \
                                int(window_end_index / window_size)*window_size
                            window_end_index = ack_num + \
                                int(window_end_index / window_size)*window_size
                            timestamp = time.time()
                    except ValueError:
                        pass

        except KeyboardInterrupt:
            conn.close()
            self.socket.close()


server = TCPServer('127.0.0.1', 10030)
server.handle_client(3)
