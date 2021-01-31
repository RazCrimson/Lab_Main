import sys

from .ps1_module.aes_256_encryption_decryption import AESCipher
from .ps1_module.caesar_cipher import CaesarCipher

args = sys.argv
host = "127.0.0.1"
port = 8013

phase_1_cipher = CaesarCipher(5)
phase_2_cipher = AESCipher(b'12345678901234567890123456789012')

if len(args) == 2 and args[1][0] == 'c':
    from .ps1_module.client import run

    with open('FileA.txt', 'rb') as f:
        data = f.read()
    run(host, port, phase_1_cipher, phase_2_cipher, data)
else:
    from .ps1_module.server import run
    result = run(host, port, phase_1_cipher, phase_2_cipher)
    with open('FileB.txt', 'wb') as f:
        data = f.write(result)
