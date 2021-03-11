import socket
import random


def hamming_code_encode(data):
    print(f'Original Data :', data)
    data = data[::-1]
    message = [int(bit) for bit in data]

    m = len(data)
    r = 1
    while 2 ** r < r + m + 1:
        r += 1

    for i in range(r):
        message.insert((2 ** i) - 1, 0)

    for i in range(r):
        parity = message[(2 ** i) - 1]
        count = 1
        j = (2**i) - 1
        while j < m+r:
            if count <= (2**i):
                parity = parity ^ message[j]
                count = count + 1
                j += 1
            else:
                count = 1
                j = j + (2**i)

        message[(2 ** i) - 1] = parity

    print('Add a bit flip for testing')
    index = random.randint(0,len(message))
    message[index] = int(not bool(message[index]))

    message = ''.join(str(bit) for bit in message)
    reverted_message = message[::-1]
    print(f"Hammed Code : {reverted_message}")

    return reverted_message


HOST = '127.0.0.1'
PORT = 65431

try:
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((HOST, PORT))
    message = '1101001100110101'
    encoded_message = hamming_code_encode(message)
    s.sendall(encoded_message.encode('utf-8'))
    response = s.recv(1024)
    if response:
        print('Recieved Data : ', response.decode('utf-8'))
    else:
        print('Server Closed')

except KeyboardInterrupt:
    s.close()
