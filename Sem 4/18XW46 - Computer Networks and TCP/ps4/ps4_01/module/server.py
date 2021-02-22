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
        super().__init__()
        print('Server Started!') 

    def wait_for_client(self):
        self.socket.listen()
        while self.socket.fileno != -1:
            conn, addr = self.socket.accept()
            print(f'New client - {addr}')
            thread = Thread(target=self.handle_client, args=(conn, addr))
            thread.start()
                        
    def handle_client(self, conn, addr):
        while True:
            msg_bytes = conn.recv(TCPServer.BUFFER_SIZE)
            print(msg_bytes)
            if msg_bytes == b'Option R':
                data = subprocess.check_output('ip route', shell=True)
            elif msg_bytes == b'Option S':
                data = subprocess.check_output('ss -HA tcp,udp | wc -l', shell=True)
            elif msg_bytes == b'Option A':
                data = subprocess.check_output('ip neigh show nud reachable', shell=True)
            elif msg_bytes == b'Stop':
                data = b'Stopping server!'
            else:
                data = b'Invalid Option'
            conn.sendall(data)

            if msg_bytes == b'Stop':
                conn.close()
                self.socket.close()
                exit(0)
        