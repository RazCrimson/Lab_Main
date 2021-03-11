import socket
import select

from threading import Thread
from typing import Coroutine


class TCPClient(object):
    BUFFER_SIZE = 2048

    def __init__(self, ip_address: str, port: int) -> None:
        self.ip_address = ip_address
        self.port = port
        self.socket = socket.socket(family=socket.AF_INET, type=socket.SOCK_STREAM)
        self.socket.connect((self.ip_address, self.port))
        print(f'Connected to server - {ip_address}:{port}')


    def print_messages(self, window_size, send_ack: bool = False):
        counter = 0
        while self.socket.fileno() != -1:
            try:
                r,_,_ = select.select([self.socket],[],[],0)
                if len(r) != 0:
                    msg_bytes = self.socket.recv(TCPClient.BUFFER_SIZE)
                    msg = msg_bytes.decode('utf-8')
                    print(msg)
                    msgs = msg.split('F')
                    
                    for msg_ in msgs:
                        if msg_ == '':
                            continue
                        if int(msg_) == counter:
                            reply = f'ACK {(counter % window_size) + 1}'
                            counter += 1
                        else:
                            reply = f'ACK {counter % window_size}'
                            
                        if send_ack:                                           
                            print(f'Sending : {reply}')
                            self.socket.sendall(reply.encode('utf-8'))                           

            except ValueError:
                pass


    def start_interactive_mode(self, window_size, send_ack: bool = False):
        '''runs the client prog'''
        thread = Thread(target=self.print_messages, args=(window_size, send_ack))
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
client.start_interactive_mode(3, True)
