# -*- coding: utf-8 -*-
"""
Spyder Editor

Dies ist eine temporäre Skriptdatei.
"""
import select
import socket               
 
sock = socket.socket()
#sock.setblocking(0) 

host = "192.168.0.18" #ESP32 IP in local network
port = 80             #ESP32 Server Port    
 
sock.connect((host, port))
 

sock.send(b'Hallo Svenja')

data=""

ready = select.select([sock], [], [], 10)
if ready[0]:
    data += (sock.recv(1024)).decode("utf-8")
if ready[0]:
    data += (sock.recv(1024)).decode("utf-8")
        
sock.close()

print(data)
    

print("Ende.")