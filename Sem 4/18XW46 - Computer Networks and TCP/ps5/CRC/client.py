import socket


def crc_encode(data):
    g = [1, 0, 1, 1]
    message = [int(bit) for bit in data]
    m = len(data)
    # Append redundant bits
    for i in range(len(g) - 1):
        message.append(0)

    # Dividing
    while 1 in message[:m]:
        cur_shift = message.index(1)
        for i in range(len(g)):
            message[cur_shift + i] = g[i] ^ message[cur_shift + i]

    remainder = ''.join(str(e) for e in message[m:])
    message = data + remainder
    print(f'Encoded Data : {message}')
    return message


HOST = '127.0.0.1'
PORT = 65431

try:
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((HOST, PORT))
    message = '1101001100110101'
    encoded_message = crc_encode(message)
    s.sendall(encoded_message.encode('utf-8'))
    response = s.recv(1024)
    if response:
        print('Recieved Data :', response.decode('utf-8'))
    else:
        print('Server Stopped')

except KeyboardInterrupt:
    s.close()
