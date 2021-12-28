import sys

args = sys.argv
host = "127.0.0.1"
port = 8014

# Run program with `s` as the first argument to start the server
# Other args start the client

if len(args) == 2 and args[1][0] == "s":
    from server import TCPServer

    server = TCPServer(host, port)
    server.handle_clients()

else:
    from client import TCPClient

    client = TCPClient(host, port)
    client.start_interactive_mode()
