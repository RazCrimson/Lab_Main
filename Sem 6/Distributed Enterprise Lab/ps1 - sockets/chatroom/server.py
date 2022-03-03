import socket
import select


class TCPServer:
    BUFFER_SIZE = 2048

    def __init__(self, ip_address: str, port: int) -> None:
        self.ip_address = ip_address
        self.port = port
        self.socket = socket.socket(family=socket.AF_INET, type=socket.SOCK_STREAM)
        self.socket.bind((self.ip_address, self.port))
        self.socket.setblocking(0)
        self.connections = {}
        super().__init__()
        print("Server Started!")

    def handle_clients(self):
        try:
            print("Press Ctrl + C Terminate")
            self.socket.listen()
            while self.socket.fileno != -1:
                readable_sockets = [conn for conn in self.connections]
                readable_sockets.append(self.socket)
                r, _, _ = select.select(readable_sockets, [], [], 0)
                for conn in r:
                    if conn is self.socket:
                        conn, addr = self.socket.accept()
                        self.connections[conn] = addr
                        print(f"New client - {addr}")
                        conn.setblocking(0)
                    else:
                        msg_bytes = conn.recv(TCPServer.BUFFER_SIZE)
                        if msg_bytes != b"":
                            self.broadcast_message(msg_bytes, conn)
                        else:
                            conn.close()
                            del self.connections[conn]
                            print(f"Closed connection - {addr}")
        except KeyboardInterrupt:
            [conn.close() for conn in self.connections]
            self.socket.close()

    def broadcast_message(self, msg: bytes, message_conn):
        for conn in self.connections:
            if conn is not message_conn:
                data = bytearray((str(self.connections[message_conn]) + ": ").encode("utf-8")) + bytearray(msg)
                conn.sendall(data)
