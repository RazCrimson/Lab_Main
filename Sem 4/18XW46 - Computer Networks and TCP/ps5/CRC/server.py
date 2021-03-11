import socket


def crc_decode(data):
    # x4 + x2 + x1 + 1  # take any polynomial you wish and just fill coeff
    g = [1, 0, 1, 1]
    print(f"Original Data : ", data)
    message = [int(bit) for bit in data]
    m = len(data) - len(g) + 1
    # perform division
    while 1 in message[:m]:
        cur_shift = message.index(1)
        for i in range(len(g)):
            message[cur_shift + i] = g[i] ^ message[cur_shift + i]

    is_corrupted = 1 in message[m:]

    if is_corrupted:
        print('Corrupted')
    else:
        print(f'No error, Data recieved : {data[:m]}')


HOST = '127.0.0.1'
PORT = 65431

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST, PORT))
    s.listen()

    while True:
        print("\n\nListening for client...")
        conn, addr = s.accept()

        with conn:
            print('Connection from ', addr)

            while True:
                data = conn.recv(1024)
                data = data.decode('utf-8')
                response = 'OK'.encode('utf-8')
                if data:
                    crc_decode(data)
                    conn.sendall(response)
                else:
                    print("Client disconnected")
                    conn.close()
