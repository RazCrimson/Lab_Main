import json
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

        messsages = {
            "1": {"Operation": "Deposit"},
            "2": {"Operation": "Withdraw"},
            "3": {"Operation": "Balance"},
        }

        print("Press Ctrl + C or enter to terminate connection)")
        print("Enter 1 to deposit")
        print("Enter 2 to withdraw")
        print("Enter 3 to deposit")
        try:
            while self.socket.fileno() != -1:
                choice = input("Enter your choice : ")
                if choice == "":
                    raise KeyboardInterrupt
                if choice not in messsages:
                    continue
                msg = messsages[choice].copy()
                if choice in ["1", "2"]:
                    amount = int(input("Enter the amount (as a number): "))
                    msg["Amount"] = amount
                msg = json.dumps(msg)
                msg = msg.encode("utf-8")
                self.socket.sendall(msg)

        except KeyboardInterrupt:
            print("Client Terminated")
        except Exception as e:
            print(type(e), e)
        finally:
            self.socket.close()
            exit()
