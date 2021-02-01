import socket

def run(host, port, data, dest_ip, dest_port):
    '''runs the client prog'''
    print('Running Client')
    
    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as sock:
        sock.bind((host, port))
        sock.sendto(data, (dest_ip,dest_port))
        message, ip_address = sock.recvfrom(1024)
        print(f'Message from server - {ip_address} : {message}')

    print("Client Terminated")