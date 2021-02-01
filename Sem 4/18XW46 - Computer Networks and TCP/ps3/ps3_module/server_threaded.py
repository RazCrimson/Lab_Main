import socket

from threading import Thread

from .server_loop import UDPServer

class UDPServerMultiClient(UDPServer):
    
    def __init__(self, ip_address: str, port: int) -> None:
        super().__init__(ip_address, port)

    def wait_for_client(self):
        while True:
            message, ip_address = self.socket.recvfrom(UDPServer.BUFFER_SIZE)
            print(f'Message from client - {ip_address} : {message}')
            thread = Thread(target=self.send_echo, args=(message, ip_address))
            thread.start()
            # sockets are not thread-safe. Better option would be use a loop or use TCP with threads
            # !! Never use for prod
            
    def send_echo(self, message: bytes, ip_address: str):
        print('Thread Started!')
        self.socket.sendto(message, ip_address)
        print('Thread Died!')


