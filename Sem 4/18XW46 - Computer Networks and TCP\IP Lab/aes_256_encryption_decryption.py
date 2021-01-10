import base64
from Crypto import Random
from Crypto.Cipher import AES

class AESCipher(object):

    def __init__(self, key): 
        self.key = key
        # Use 

    def encrypt(self, raw):
        raw = self._pad(raw)
        iv = Random.new().read(AES.block_size)
        cipher = AES.new(self.key, AES.MODE_CBC, iv)
        return base64.b64encode(iv + cipher.encrypt(raw))

    def decrypt(self, enc):
        enc = base64.b64decode(enc)
        iv = enc[:AES.block_size]
        cipher = AES.new(self.key, AES.MODE_CBC, iv)
        return self._unpad(cipher.decrypt(enc[AES.block_size:]))

    def _pad(self, s):
        return s + (AES.block_size - len(s) % AES.block_size) * chr(AES.block_size - len(s) % AES.block_size)

    @staticmethod
    def _unpad(s):
        return s[:-ord(s[len(s)-1:])]


if __name__ == '__main__':
    f = open('input.txt', 'rb')
    data = f.read()
    f.close()

    aes_cipher = AESCipher(b'12345678901234567890123456789012')
    encrypted_result = aes_cipher.encrypt(data)

    f = open('output.txt', 'wb+')
    data = f.write(encrypted_result)
    f.close()

    f = open('output.txt', 'wb+')
    data = f.read()
    f.close()

    decrypted_result = aes_cipher.decrypt(data)
    
    print(data)
