import rsa

if __name__ == "__main__":
    pub_key, priv_key = rsa.newkeys(16)
    n = pub_key.n
    e = pub_key.e
    d = priv_key.d

    plain_text = 3333

    cipher_text = pow(plain_text, e, n)

    victim_msg = cipher_text * pow(2, e, n)

    victim_response = pow(victim_msg, d, n)

    decrypted_plain_text = (victim_response * pow(2, -1, n)) % n
    print(f"Decrypted Plain Text : {decrypted_plain_text}")
