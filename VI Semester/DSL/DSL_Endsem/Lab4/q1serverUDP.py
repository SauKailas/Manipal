import socket
import time

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
host = socket.gethostname()
port = 9999
s.bind((host, port))

while True:
	data, addr = s.recvfrom(1024)
	print("Received Message : ", data.decode())
	tm = time.ctime(time.time()) + "\r\n"
	s.sendto(tm.encode('ascii'), addr)