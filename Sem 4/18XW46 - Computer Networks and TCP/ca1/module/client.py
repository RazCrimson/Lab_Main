import socket


class TCPClient(object):
    BUFFER_SIZE = 2048

    def __init__(self, ip_address: str, port: int) -> None:
        self.ip_address = ip_address
        self.port = port
        self.socket = socket.socket(
            family=socket.AF_INET, type=socket.SOCK_STREAM)
        self.socket.connect((self.ip_address, self.port))
        self.socket.setblocking(30) # Blockin got 30 secs
        print(f'Connected to server - {ip_address}:{port}')

    def start_interactive_mode(self):
        '''runs the client prog'''

        print('Press Ctrl + C or a empty message to terminate connection)')
        try:
            while self.socket.fileno() != -1:
                message = get_message_from_choice()
                msg = message.encode('utf-8')
                self.socket.sendall(msg)
                if msg == b'':
                    raise KeyboardInterrupt

                msg_bytes = self.socket.recv(TCPClient.BUFFER_SIZE)
                print(msg_bytes.decode('utf-8'))

        except KeyboardInterrupt:
            pass
        except (BlockingIOError, BrokenPipeError): # Treating connection error as server not responding
            print("Server not responding!")
        except Exception as e:
            print(type(e), e)
        finally:
            print("Client Terminated")
            self.socket.close()
            exit()


def get_message_from_choice():  # Getting user input
    while True:
        try:
            choice = input('1 - DOMAIN NAME RESOLUTION\n'
                           '2 - MAC-IP TABLE UPDATE\n'
                           '3 - GET MAC-IP TABLE\n'
                           '0 - Terminate client\n'
                           'Enter your Choice : '
                           )
            option = int(choice)
            if option == 0:
                return ''
            elif option == 1:
                domain_name = input("Enter the Domain name : ")
                return f'DOMAIN_NAME {domain_name}'
            elif option == 2:
                mac_address = input("Enter the MAC address : ")
                return f'MAC {mac_address}'
            elif option == 3:
                return f'MAC-IP Table'
            raise ValueError("Invalid Option")
        except ValueError:
            print('Invalid Choice!')


if __name__ == '__main__':
    client = TCPClient('127.0.0.1', 24000)
    client.start_interactive_mode()
