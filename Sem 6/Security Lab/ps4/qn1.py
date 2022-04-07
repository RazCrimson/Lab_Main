from hashlib import sha256
from random import randint
from string import ascii_letters

all_hashes = []  # For randomly selecting a hash
NO_OF_ENTRIES = 10
PASSWORD_LENGTH = 10
NO_OF_ITERMEDIATE_HASHES = 10


def reduce_hash(hashed_password: int, length: int) -> str:
    reduced_hash = ""
    for _ in range(length):
        reduced_hash += ascii_letters[hashed_password % len(ascii_letters)]
        hashed_password = int(hashed_password / len(ascii_letters))
    return reduced_hash


def hash(password: str) -> int:
    return int((sha256(password.encode())).hexdigest(), 16)


def print_table(table: list[tuple]) -> None:
    for i, row in enumerate(table):
        print(i + 1, row)
    print()


def construct_rainbow_table(password_length: int, no_of_entries: int, table_width: int):
    passwords = []

    for _ in range(no_of_entries):
        password = "".join([ascii_letters[randint(0, 25)] for _ in range(password_length)])
        passwords.append(password)

    hashed_passwords = [(password, hash(password)) for password in passwords]

    print("Rainbow Table Contents:")
    print_table(hashed_passwords)

    for i in range(table_width):
        reduced_hashes = [reduce_hash(hashed_password, password_length) for _, hashed_password in hashed_passwords]
        hashed_passwords = [(reduced_password, hash(reduced_password)) for reduced_password in reduced_hashes]

        hashes = [hashed_password for _, hashed_password in hashed_passwords]
        print("Iteration", i + 1)
        print_table(hashed_passwords)
        all_hashes.extend(hashes)

    return passwords, hashes


def crack(selected_hash: int, passwords: list[str], hashes: list[str]) -> str:

    hash_iter = selected_hash
    while hash_iter not in hashes:
        hash_iter = hash(reduce_hash(hash_iter, PASSWORD_LENGTH))

    password = passwords[hashes.index(hash_iter)]
    while hash(password) != selected_hash:
        password = reduce_hash(hash(password), PASSWORD_LENGTH)

    return password


if __name__ == "__main__":
    initial_passwords, final_hashes = construct_rainbow_table(PASSWORD_LENGTH, NO_OF_ENTRIES, NO_OF_ITERMEDIATE_HASHES)

    random_hash = all_hashes[randint(0, len(all_hashes) - 1)]
    print("Randomly selected Hash:", random_hash)

    cracked = crack(random_hash, initial_passwords, final_hashes)
    print("Cracked Password:", cracked)
