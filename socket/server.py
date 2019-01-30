#!/usr/bin/env python

import socket
import time
import base64
import json

TCP_IP = '10.42.0.1'
TCP_PORT = 5005
BUFFER_SIZE = 2**20 # Normally 1024, but we want fast response



def main():
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.bind((TCP_IP, TCP_PORT))
    s.listen(1)
    conn, addr = s.accept()
    print 'Connection address:', addr
    while 1:
        data = conn.recv(BUFFER_SIZE)
        if not data: break
        j = json.loads(data)
        print "received data:", data
        print j[0]
        #conn.send(data)  # echo
     
    conn.close()



if __name__ == "__main__": main()