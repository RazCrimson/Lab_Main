'''
A simple HTTP file server client

Author: Raz Crimson(19PW08)
'''

import sys

from http.client import HTTPConnection
from typing import Optional, Tuple


class CustomHTTPClient(HTTPConnection):

    def __init__(self, host: str, port: Optional[int] = 80) -> None:
        super().__init__(host, port=port)

    def get_request(self, path):
        print(f'Sending a GET request at {path}')
        self.request("GET", path)
        res = self.getresponse()
        print(
            f'Response: {res.read()} Status : {res.status} Reason : {res.reason}')

    def post_request(self, path, data):
        print(f'Sending a POST request at {path}')
        headers = {'Content-type': 'text/plain',
                   'Content-length': len(data)
                   }
        # json_data = json.dumps(data)
        self.request('POST', path, data.encode('utf-8'), headers)
        res = self.getresponse()
        print(
            f'Response: {res.read()} Status : {res.status} Reason : {res.reason}')

    def put_request(self, path, data):
        print(f'Sending a PUT request at {path}')
        headers = {'Content-type': 'text/plain',
                   'Content-length': len(data)
                   }
        self.request('PUT', path, data, headers)
        res = self.getresponse()
        print(
            f'Response: {res.read()} Status : {res.status} Reason : {res.reason}')

    def delete_request(self, path):
        self.request('DELETE', path)
        res = self.getresponse()
        print(
            f'Response: {res.read()} Status : {res.status} Reason : {res.reason}')


if __name__ == '__main__':
    if len(sys.argv) < 2:
        print('ERROR: Not enough Arguments')
        exit(1)
    else:
        client = CustomHTTPClient(sys.argv[1], sys.argv[2])
        try:
            print(
                f'Press Ctrl + C To Terminate\nDestination: {sys.argv[1]}:{sys.argv[2]}')
            REQUEST_METHOD = True
            PATH = input('Enter the URI for the request : ')
            if PATH == '' or PATH[0] != '/':
                PATH = '/' + PATH

            REQUEST_METHOD = input(
                'Enter the request type (GET/POST/PUT/DELETE): ')
            if REQUEST_METHOD.upper() == 'GET':
                client.get_request(PATH)
            elif REQUEST_METHOD.upper() == 'POST':
                data = input('Enter the data sent : ')
                client.post_request(PATH, data)
            elif REQUEST_METHOD.upper() == 'PUT':
                data = input('Enter the data sent : ')
                client.put_request(PATH, data)
            if REQUEST_METHOD.upper() == 'DELETE':
                client.delete_request(PATH)

        except KeyboardInterrupt:
            pass
        finally:
            client.close()
