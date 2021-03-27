'''
A program that performs ICMP tracerouting

Author: Raz Crimson
'''
import time
import sys

from scapy.layers.inet import IP, ICMP
from scapy.sendrecv import AsyncSniffer, send


PING_REQUEST_COUNT = 30
TIME_INTERVAL = 1


class ClientPayload:

    def __init__(self, message, seq_number):
        self.message = message
        self.icmp_seq = seq_number
        self.created_at = time.time()

    def __repr__(self) -> str:
        return f'<"{self.message}", {self.icmp_seq}, {self.created_at}>'
        
class PingClient:

    def __init__(self, dst: str):
        self.dst = dst
        self.__last_received_sequence_number = -1
        self.__last_generated_sequence_number = -1
        self.__sniffer = AsyncSniffer(
            prn=self.__handle_filtered_pkts, filter=f'src {self.dst} and icmp')

    def __generate_next_packet(self):
        self.__last_generated_sequence_number += 1
        payload = ClientPayload("MY_PING", self.__last_generated_sequence_number)
        pkt = IP(dst=self.dst)/ICMP()/str(payload)
        return pkt

    def __handle_filtered_pkts(self, pkt):
        # TODO: crappy improve later - raz
        received_time = time.time()
        
        ping_string = pkt[3].load.decode('utf-8')
        if ping_string.startswith('<"MY_PING", '):
            _, seq_no, sent_time = ping_string.strip('>').split(',')

            rtt = round((received_time - float(sent_time)) * 1000, 4)
            if rtt > 1000:
                return

            if self.__last_received_sequence_number + 1 == int(seq_no):
                print(f'<{self.__last_generated_sequence_number}, {received_time}, {ping_string}, "Successfully_Received", {rtt} ms >')
            elif self.__last_received_sequence_number + 1 < int(seq_no):
                print(f'<{self.__last_generated_sequence_number}, {ping_string}, "Received_out_of_order">')
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



if __name__ == '__main__':
    if len(sys.argv) < 2:
        print('ERROR: No destination to Ping')
        exit(1)
    else:
        print(f'Using {sys.argv[1]} as the destination...\nPress Ctrl + C To Terminate')

    if len(sys.argv) >= 3 and isinstance(int(sys.argv[3]), int):
        print(f'Setting {sys.argv[3]} as the ping count...(Negative indicated infinite requests)')
        PING_REQUEST_COUNT = int(sys.argv[3])

    try:
        pg = PingClient(sys.argv[1])
        pg.start_transmission(PING_REQUEST_COUNT)
    except PermissionError:
        print('ERROR: Please run it as root user.')
