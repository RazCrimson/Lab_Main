import socket


def run(host, port, phase_1, phase_2, data):
    print('Running Client')
    print('Reading FileA')

    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
        sock.connect((host, port))
        print(f'Sending to Server : {data}')
        print("Encrypting Data....")
        result_ph1 = phase_1.encrypt(data)
        print(f'Encrypted Phase 1 : {result_ph1}')
        result_ph2 = phase_2.encrypt(result_ph1)
        print(f'Encrypted Phase 2 : {result_ph2}')
        sock.sendall(result_ph2)

    print("Client Terminated")
