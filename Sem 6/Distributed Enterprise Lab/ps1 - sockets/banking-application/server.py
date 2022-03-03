from json.decoder import JSONDecodeError
import socket
import select
import json


class TCPServer:
    BUFFER_SIZE = 2048
    DEFAULT_ACCOUNT_BALANCE = 1000

    def __init__(self, ip_address: str, port: int) -> None:
        self.ip_address = ip_address
        self.port = port
        self.socket = socket.socket(family=socket.AF_INET, type=socket.SOCK_STREAM)
        self.socket.bind((self.ip_address, self.port))
        self.socket.setblocking(0)
        self.connections = {}
        self.store = {}
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
                        self.store[conn] = self.DEFAULT_ACCOUNT_BALANCE
                        print(f"New client - {addr}")
                        conn.setblocking(0)
                    else:
                        msg_bytes = conn.recv(TCPServer.BUFFER_SIZE)
                        if msg_bytes != b"":
                            self.handle_message(msg_bytes, conn)
                        else:
                            conn.close()
                            del self.connections[conn]
                            print(f"Closed connection - {addr}")
        except KeyboardInterrupt:
            [conn.close() for conn in self.connections]
            self.socket.close()

    def handle_message(self, msg: bytes, conn):
        try:
            msg_string = msg.decode("utf-8")
            msg_dict = json.loads(msg_string)
            print(conn, " ", msg_dict)
            operation = msg_dict["Operation"]
            if operation not in ["Withdraw", "Deposit", "Balance"]:
                return

            if operation == "Balance":
                conn.sendall(b"Balance : " + str(self.store[conn]).encode("utf-8") + b"\n")
                return

            amount = msg_dict["Amount"]
            if type(amount) is not int or int(amount) < 0:
                conn.sendall(b"Invalid Amount\n")
                return
            amount = int(amount)

            if operation == "Withdraw":
                if self.store[conn] >= amount:
                    self.store[conn] -= amount
                    conn.sendall(b"Withdrawn : " + str(amount).encode("utf-8") + b"\n")
                else:
                    conn.sendall(b"Not enough Balance\n")
            elif operation == "Deposit":
                self.store[conn] += amount
                conn.sendall(b"Deposited : " + str(amount).encode("utf-8") + b"\n")
            conn.sendall(b"Balance : " + str(self.store[conn]).encode("utf-8") + b"\n")

        except (JSONDecodeError, KeyError):
            pass
