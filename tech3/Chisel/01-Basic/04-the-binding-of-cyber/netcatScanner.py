

#!/usr/bin/env python3

from sys import argv, exit
import socket

HOST = "10.10.41.86"
PORT_MIN = 100
PORT_MAX = 65535

def netcat(hostname, port, content):
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((hostname, port))
    s.sendall(content)
    s.shutdown(socket.SHUT_WR)
    while 1:
        data = s.recv(4096)
        if len(data) == 0:
            print(f"## {port}\n```\nNothing\n```\n\n")
            with open("./Port_Info.md", "a+") as f:
                f.write(f"## {port}\n```\nNothing\n```\n\n")
            break
        else:
            print(f"## {port}\n```\n{data}\n```\n\n")
            with open("./Port_Info.md", "a+") as f:
                f.write(f"## {port}\n```\n{data}\n```\n\n")
    s.close()

def main():
    print("# Ports\n\n")
    for i in range(PORT_MIN, PORT_MAX):
        try:
            netcat(HOST, i, b"0")
        except:
            pass
    return 0

if __name__ == '__main__':
    main()
