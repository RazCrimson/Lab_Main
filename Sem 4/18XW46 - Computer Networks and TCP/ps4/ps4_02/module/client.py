import socket

from threading import Thread


class TCPClient(object):
    BUFFER_SIZE = 2048

    def __init__(self, ip_address: str, port: int) -> None:
        self.ip_address = ip_address
        self.port = port
        self.socket = socket.socket(family=socket.AF_INET, type=socket.SOCK_STREAM)
        self.socket.connect((self.ip_address, self.port))
        print(f'Connected to server - {ip_address}:{port}')


    def print_messages(self):
        while self.socket.fileno != -1:
            msg_bytes = self.socket.recv(TCPClient.BUFFER_SIZE)
            print(msg_bytes.decode('utf-8'))

    def start_interactive_mode(self):
        '''runs the client prog'''
        thread = Thread(target=self.print_messages)
        thread.start()

        print('Enter your message(Empty string to terminate connection) : ')
        while True:
            message = input('')
            msg = message.encode('utf-8')
            self.socket.sendall(msg)
            if msg == b'':
                self.socket.close()
                print("Client Terminated")
                exit()
                
