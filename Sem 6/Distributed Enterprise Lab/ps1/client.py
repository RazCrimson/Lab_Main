import socket
import select

from threading import Thread


class TCPClient(object):
    BUFFER_SIZE = 2048

    def __init__(self, ip_address: str, port: int) -> None:
        self.ip_address = ip_address
        self.port = port
        self.socket = socket.socket(family=socket.AF_INET, type=socket.SOCK_STREAM)
        self.socket.connect((self.ip_address, self.port))
        self.socket.setblocking(0)
        print(f"Connected to server - {ip_address}:{port}")

    def print_messages(self):
        while self.socket.fileno() != -1:
            try:
                r, _, _ = select.select([self.socket], [], [], 0)
                for conn in r:
                    msg_bytes = conn.recv(TCPClient.BUFFER_SIZE)
                    print(msg_bytes.decode("utf-8"))
            except ValueError:
                pass

    def start_interactive_mode(self):
        """runs the client prog"""
        thread = Thread(target=self.print_messages)
        thread.start()

        print("Press Ctrl + C or a empty message to terminate connection)")
        print("Enter your message  : ")
        try:
            while self.socket.fileno() != -1:
                message = input("")
                msg = message.encode("utf-8")
                self.socket.sendall(msg)
                if msg == b"":
                    raise KeyboardInterrupt

        except KeyboardInterrupt:
            print("Client Terminated")
        except Exception as e:
            print(type(e), e)
        finally:
            self.socket.close()
            exit()
