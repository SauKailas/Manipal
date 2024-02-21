import socket
import datetime

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
host = socket.gethostname()
port = 9999
s.bind((host, port))

while True:
	data, addr = s.recvfrom(1024)
	print("Client Sent: ", data.decode())
	time = str(datetime.datetime.now())
	s.sendto(time.encode(), addr)