import sys

args = sys.argv
host = "127.0.0.1"
port = 8013

if len(args) == 2 and args[1][0] == 's':
    if len(args[1]) == 2 and args[1][1] == 'm':
        from ps3_module.server_threaded import UDPServerMultiClient as Server
    else: 
        from ps3_module.server_loop import UDPServer as Server

    server = Server(host, port)
    server.wait_for_client()

else:
    from ps3_module.client import run
    
    run(host, port + 5, b'Hello!', host, port)
    
