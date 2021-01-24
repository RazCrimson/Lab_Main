import socket


def run(host, port, phase_1, phase_2):
    print('Running Server')
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
        sock.bind((host, port))
        sock.listen()
        print(f"Listening to port {port}")
        conn, addr = sock.accept()
        with conn:
            print("Connected by ", addr)
            data = conn.recv(1024)
            print(f'Data Received from Client : {data}')
            result_ph2 = phase_2.decrypt(data)
            print(f'Decrypted Phase 1 : {result_ph2}')
            result_ph1 = phase_1.decrypt(result_ph2)
            print(f'Decrypted Phase 2 : {result_ph1}')
            return result_ph1
