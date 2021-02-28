import socket
import select   # For non blocking IO
import subprocess


class TCPServer(object):
    BUFFER_SIZE = 2048

    def __init__(self, ip_address: str, port: int) -> None:
        self.ip_address = ip_address
        self.port = port
        self.socket = socket.socket(
            family=socket.AF_INET, type=socket.SOCK_STREAM)
        self.socket.bind((self.ip_address, self.port))
        self.socket.setblocking(0)  # For non-blocking IO
        self.connections = {}
        self.MAC_IP_table = {}
        super().__init__()
        print('Server Started!')

    def handle_clients(self):
        try:
            print('Press Ctrl + C Terminate')
            self.socket.listen()
            while self.socket.fileno != -1: # Checking for readable sockets
                readable_sockets = [conn for conn in self.connections]
                readable_sockets.append(self.socket)
                r, _, _ = select.select(readable_sockets, [], [], 0)
                for conn in r:
                    if conn is self.socket:
                        conn, addr = self.socket.accept()
                        self.connections[conn] = addr
                        print(f'New client - {addr}')
                        conn.setblocking(0)
                    else:
                        msg_bytes = conn.recv(TCPServer.BUFFER_SIZE)
                        if msg_bytes not in [b'', b'END']:
                            self.send_response(conn, msg_bytes)
                        else:
                            conn.close()
                            del self.connections[conn]
                            print(f'Closed connection - {addr}')
        except KeyboardInterrupt:
            (conn.close() for conn in self.connections)
            self.socket.close()

    def send_response(self, conn, msg_bytes: bytes):
        msg = msg_bytes.decode('utf-8')
        if msg.startswith('DOMAIN_NAME '):
            domain = msg[len('DOMAIN_NAME '):]
            try:
                response = str(subprocess.check_output(
                    f'nslookup {domain}', shell=True))
            except:
                response = "Can't find a valid IP address for a given domain"
        elif msg.startswith("MAC "):
            client_mac = msg[len("MAC "):]
            self.MAC_IP_table[client_mac] = self.connections[conn][0]
            response = "MAC-IP Table updated."
        elif msg == 'MAC-IP Table':
            response = str(self.MAC_IP_table)
        else:
            response = "Invalid Request!"
        print(response)
        conn.sendall(bytes(response, 'utf-8'))


if __name__ == '__main__':
    server = TCPServer("0.0.0.0", 24000)
    server.handle_clients()
