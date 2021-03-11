import socket
from functools import reduce

def hamming_code_decode(data):
    print("Data recieved : ", data)
    data = data[::-1]
    message = [int(bit) for bit in data]


    n = len(data)
    r = 0
    while 2 ** r <= n:
        r += 1

    err_pos = 0
    corrupted = False

    for i in range(r):
        parity = message[(2 ** i) - 1]
        count = 1
        j = (2**i) - 1
        while j < n:
            if count <= (2**i):
                parity = parity ^ message[j]
                count = count + 1
                j += 1
            else:
                count = 1
                j = j + (2**i)
            
        if (parity ^ message[(2 ** i) - 1]) == 1:
            corrupted = True
            err_pos = err_pos + (2 ** i)

    if corrupted:
        message[err_pos - 1] = message[err_pos - 1] ^ 1
        print('Correcting Data...')

    else:
        print('No error')

    mes = []
    power = 0
    for i in range(n):
        if (2 ** power) - 1 == i:
            power = power + 1
        else:
            mes.append(message[i])

    mes = mes[::-1]

    mes = ''.join([str(c) for c in mes])
    print('Original Message :', mes)


HOST = '127.0.0.1'
PORT = 65431 

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST,PORT))
    s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)    
    s.listen()

    while s.fileno() != -1:
        print("\n\nListening for new client..")
        conn, addr = s.accept()
        print("New client connected!")

        with conn:
            print('Connection from ', addr)
        
            while conn.fileno() != -1:
                data = conn.recv(1024)
                data = data.decode('utf-8')
                response = 'OK'.encode('utf-8')
                if data:
                    hamming_code_decode(data)
                    conn.sendall(response)
                
                else:
                    print("Client Disconnected")
                    conn.close()
            