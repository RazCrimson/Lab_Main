import string
import random

def password_generator(length):
    password = ''
    for _ in range(int(length/3)): 
        password += password+ random.choice(string.ascii_uppercase) + random.choice(string.ascii_lowercase) + random.choice(string.digits) + random.choice(string.punctuation)
    return password[:int(length)]

length = input('Enter password length : ')
new_pass = password_generator(length)
print(new_pass)