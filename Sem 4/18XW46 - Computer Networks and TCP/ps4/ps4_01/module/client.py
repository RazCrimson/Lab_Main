import socket

BUFFER_SIZE = 2048

def get_choice():
    print('1. Option R\n'
          '2. Option S\n'
          '3. Option A\n'
          '0. Stop\n'
          )
    return input('Enter your choice: ')



def run(host, port):
    '''runs the client prog'''
    print('Running Client')

    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.connect((host, port))
    print(f'Connected to server - {host}:{port}')
    while True:
        choice = int(get_choice())
        if choice not in [0, 1, 2, 3]: 
            print('Invalid Choice')
            exit(0)
        if choice == 1:
            send_data = b'Option R'
        elif choice == 2:
            send_data = b'Option S'
        elif choice == 3:
            send_data = b'Option A'
        else:
            send_data = b'Stop'
           
        sock.sendall(send_data)
        msg = sock.recv(BUFFER_SIZE)
        print('\nMessage from server:\n')
        print(msg.decode('utf-8'))
        
        if choice == 0:
            break
    print("Client Terminated")
