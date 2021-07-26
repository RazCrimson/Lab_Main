'''
A program that performs ICMP tracerouting

Author: Raz Crimson(19PW08)
'''
from os import times
import time
import sys

from scapy.layers.inet import IP, ICMP, raw
from scapy.sendrecv import sr1


TIMEOUT = 10
TTL_MAX = 64


class PingClient:

    def __init__(self, dst: str):
        self.dst = dst
        self.__ttl_counter = 0
        
    def __generate_next_packet(self):
        '''function to generate the next pkt to transmit'''
        self.__ttl_counter += 1
        sent_time = time.time()
        pkt = IP(dst=self.dst, ttl=self.__ttl_counter)/ICMP()/str(sent_time)
        return pkt

    def start_tracing(self):
        try:
            while self.__ttl_counter < TTL_MAX:
                pkt = self.__generate_next_packet()

                ans = sr1(pkt, verbose=False, timeout=TIMEOUT)

                if ans is None:
                    print(f'{self.__ttl_counter}: Reply timed out!\nMoving on to next client')
                    continue

                rtt = "Not Applicable"    
                if hasattr(ans[ICMP], 'load'):
                    rtt = round((time.time() - float(ans[ICMP].load)) * 1000, 4)
                
                print(f'{self.__ttl_counter}: {ans[0].src} | RTT: {rtt}')           

                # Terminating if we reach destination
                if ans[ICMP].type == 0:
                    print(f"Destination Reached!")
                    break

        except KeyboardInterrupt:
            pass


if __name__ == '__main__':
    if len(sys.argv) < 2:
        print('ERROR: No destination to To trace')
        exit(1)
    else:
        print(f'Press Ctrl + C To Terminate\nDestination: {sys.argv[1]}')

    if len(sys.argv) >= 3 and isinstance(int(sys.argv[3]), int):
        print(f'Setting {sys.argv[3]} as the max ttl...')
        TTL_MAX = int(sys.argv[3])

    try:
        pg = PingClient(sys.argv[1])
        pg.start_tracing()
    except PermissionError:
        print('ERROR: Please run it as root user.')
