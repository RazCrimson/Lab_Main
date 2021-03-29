import socket
import select
import time

from threading import Thread


class TCPClient(object):
    BUFFER_SIZE = 2048

    def __init__(self, ip_address: str, port: int) -> None:
        self.ip_address = ip_address
        self.port = port
        self.socket = socket.socket(
            family=socket.AF_INET, type=socket.SOCK_STREAM)
        self.socket.connect((self.ip_address, self.port))
        print(f'Connected to server - {ip_address}:{port}')

    @staticmethod
    def next_n_frame_indices(counter, window_size):
        return [x % (2*window_size) for x in range(counter, counter + window_size)]

    def ack_manager(self, window_size, send_ack: bool = False):
        counter = 0
        data = []
        left_over_frames = []
        timestamp = time.time()

        while self.socket.fileno() != -1:
            try:
                frames_to_check = []
                r, _, _ = select.select([self.socket], [], [], 0)
                if len(r) != 0:
                    msg_bytes = self.socket.recv(TCPClient.BUFFER_SIZE)
                    msg = msg_bytes.decode('utf-8')
                    if msg == '':
                        print("Data Received!")
                        exit()
                    msgs = msg.split('F')
                    for frame_num in msgs:
                        if frame_num != '':
                            frames_to_check.append(int(frame_num))

                frames_to_check.extend(left_over_frames)
                frames_to_check = list(set(frames_to_check))
                frames_to_check.sort()
                left_over_frames = []
                
                for frame_num in frames_to_check:

                    if frame_num == counter % (2 * window_size):
                        reply = f'ACK {(counter % (2 * window_size)) + 1}'
                        data.append(frame_num)
                        print(data)
                        timestamp = time.time()
                        counter += 1
                        if send_ack:
                            self.socket.sendall(reply.encode('utf-8'))
                            time.sleep(0.6)


                    elif frame_num in self.next_n_frame_indices(counter,window_size):
                        left_over_frames.append(frame_num)

                if time.time() - timestamp > 200:
                    timestamp = time.time()
                    reply = f'NAK {counter % (2 * window_size)}'
                    self.socket.sendall(reply.encode('utf-8'))
                
            except ValueError:
                pass
            except BrokenPipeError:
                self.socket.close()
                print('Connection closed!')
                break

    def start_interactive_mode(self, window_size, send_ack: bool = False):
        '''runs the client prog'''
        thread = Thread(target=self.ack_manager,
                        args=(window_size, send_ack))
        thread.start()

        print('Press Ctrl + C or a empty message to terminate connection)')
        print('Enter your message  : ')
        try:
            while self.socket.fileno() != -1:
                message = input('')
                msg = message.encode('utf-8')
                self.socket.sendall(msg)
                if msg == b'':
                    raise KeyboardInterrupt

                msg_bytes = self.socket.recv(TCPClient.BUFFER_SIZE)
                print(msg_bytes.decode('utf-8'))

        except KeyboardInterrupt:
            print("Client Terminated")
        except Exception as e:
            print(type(e), e)
        finally:
            self.socket.close()
            exit()


client = TCPClient('127.0.0.1', 10030)
client.start_interactive_mode(4, True)  # Switch to False for sender-a
