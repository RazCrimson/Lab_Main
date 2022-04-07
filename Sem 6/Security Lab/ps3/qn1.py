import rsa

if __name__ == "__main__":
    pub_key, priv_key = rsa.newkeys(16)
    e = pub_key.e
    n = pub_key.n

    i = 0
    message = 1245
    cipher_text = pow(message, e, n)
    while cipher_text != message:
        i += 1
        print(f"Iteration: {i} | Plain Text: {message} | Cipher Text : {cipher_text}")
        cipher_text = pow(cipher_text, e, n)
    print(f"Plain Text: {message} | Cipher Text : {cipher_text}")
