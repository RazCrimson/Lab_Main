import socket
import subprocess

from threading import Thread


class TCPServer(object):
    BUFFER_SIZE = 2048

    def __init__(self, ip_address: str, port: int) -> None:
        self.ip_address = ip_address
        self.port = port
        self.socket = socket.socket(family=socket.AF_INET, type=socket.SOCK_STREAM)
        self.socket.bind((self.ip_address, self.port))
        self.connections = {}
        super().__init__()
        print('Server Started!') 

    def wait_for_client(self):
        self.socket.listen()
        while self.socket.fileno != -1:
            conn, addr = self.socket.accept()
            print(f'New client - {addr}')
            self.connections[addr] = conn
            thread = Thread(target=self.handle_client, args=(conn, addr))
            thread.start()
                        
    def handle_client(self, conn, addr):
        while True:
            msg_bytes = conn.recv(TCPServer.BUFFER_SIZE)
            if msg_bytes != b'':
                self.broadcast_message(msg_bytes, addr)
            else:
                conn.close()
                del self.connections[addr]
                exit(0)
        
    def broadcast_message(self, msg: bytes, addr):
        for key in self.connections:
            if key is not addr:
                self.connections[key].sendall(msg)
                self.connections[key].sendall(str(addr).encode('utf-8'))
                


        