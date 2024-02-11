import socket
import time

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
host = socket.gethostname()
port = 9991
s.bind((host, port))
while True:
	data, addr = s.recvfrom(1024)
	print("Got a connection from: ", str(addr))
	time = time.ctime(time.time()) + "\r\n"
	s.sendto(time.encode('ascii'), addr)