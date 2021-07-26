'''
A program that performs ICMP ping

Author: Raz Crimson(19PW08)
'''
import time
import sys

from scapy.layers.inet import IP, ICMP
from scapy.sendrecv import AsyncSniffer, send


PING_REQUEST_COUNT = 30
TIME_INTERVAL = 1


class ClientPayload:
    '''A class denoting the Client payload'''

    def __init__(self, message, seq_number):
        self.message = message
        self.icmp_seq = seq_number
        self.created_at = time.time()

    def __repr__(self) -> str:
        return f'<"{self.message}", {self.icmp_seq}, {self.created_at}>'
        
class PingClient:
    '''Class representing the client'''
    def __init__(self, dst: str):
        self.dst = dst
        self.__last_received_sequence_number = -1
        self.__last_generated_sequence_number = -1
        self.__sniffer = AsyncSniffer(
            prn=self.__handle_filtered_pkts, filter=f'src {self.dst} and icmp')
        self.__received_count = 0

    def __generate_next_packet(self):
        '''function to generate the next pkt to transmit'''
        self.__last_generated_sequence_number += 1
        payload = ClientPayload("MY_PING", self.__last_generated_sequence_number)
        pkt = IP(dst=self.dst)/ICMP()/str(payload)
        return pkt

    def __handle_filtered_pkts(self, pkt):
        '''captured pkts handler'''
        received_time = time.time()
        
        payload = pkt[ICMP].load.decode('utf-8')
        if payload.startswith('<"MY_PING", '):
            _, seq_no, sent_time = payload.strip('>').split(',')

            rtt = round((received_time - float(sent_time)) * 1000, 4)
            if rtt > 1000:
                return

            if self.__last_received_sequence_number + 1 == int(seq_no):
                print(f'<{self.__last_generated_sequence_number}, {received_time}, {payload}, "Successfully_Received", {rtt} ms>')
                self.__received_count += 1
            elif self.__last_received_sequence_number + 1 < int(seq_no):
                print(f'<{self.__last_generated_sequence_number}, {payload}, "Received_out_of_order">')
            else:
                return

        self.__last_received_sequence_number += 1

    def start_transmission(self, count):
        self.__sniffer.start()
        time.sleep(1)
        try:
            while count != 0:
                count -= 1
                pkt = self.__generate_next_packet()
                pkt_sent_time = time.time()
                send(pkt, verbose=False)

                if time.time() - pkt_sent_time < 1:
                    time.sleep(TIME_INTERVAL - time.time() + pkt_sent_time)

                if self.__last_received_sequence_number != self.__last_generated_sequence_number:
                    print(
                        f'<{self.__last_generated_sequence_number}, "Timed_Out">')
                    self.__last_received_sequence_number += 1

        except KeyboardInterrupt:
            print('\nPacket Transmission Terminated!')
        self.__sniffer.stop()
        packet_loss = round(((self.__last_generated_sequence_number + 1 - self.__received_count)/(self.__last_generated_sequence_number+1))*100,2)    
        print(f'Packet Loss: {packet_loss}% \t | Packets Sent : {self.__last_generated_sequence_number + 1} \t | Packets Received : {self.__received_count}')



if __name__ == '__main__':
    if len(sys.argv) < 2:
        print('ERROR: No destination to Ping')
        exit(1)
    else:
        print(f'Press Ctrl + C To Terminate\nDestination: {sys.argv[1]}')

        if sys.argv[1] in ['localhost', '127.0.0.1']:
            from scapy.config import conf
            conf.iface = 'lo'

    if len(sys.argv) >= 3 and isinstance(int(sys.argv[3]), int):
        print(f'Setting {sys.argv[3]} as the ping count...(Negative indicated infinite requests)')
        PING_REQUEST_COUNT = int(sys.argv[3])

    try:
        pg = PingClient(sys.argv[1])
        pg.start_transmission(PING_REQUEST_COUNT)
    except PermissionError:
        print('ERROR: Please run it as root user.')


