import sys

args = sys.argv
host = "127.0.0.1"
port = 8013

if len(args) == 2 and args[1][0] == 's':
    from module.server import TCPServer

    server = TCPServer(host, port)
    server.wait_for_client()

else:
    from module.client import run

    run(host, port)