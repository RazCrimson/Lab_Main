import socket

class UDPServer(object):
    BUFFER_SIZE = 1024

    def __init__(self, ip_address: str, port: int) -> None:
        self.ip_address = ip_address
        self.port = port
        self.socket = socket.socket(family=socket.AF_INET, type=socket.SOCK_DGRAM)
        self.socket.bind((self.ip_address, self.port))
        super().__init__()
        print('Server Started!') 

    def wait_for_client(self):
        while True:
            message, ip_address = self.socket.recvfrom(UDPServer.BUFFER_SIZE)
            print(f'Message from client - {ip_address} : {message}')
            self.socket.sendto(message, ip_address)

