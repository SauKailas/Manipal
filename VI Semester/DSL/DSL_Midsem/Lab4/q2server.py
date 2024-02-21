import socket

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
host = socket.gethostname()
port = 9999
s.bind((host, port))

while True:
	data, addr = s.recvfrom(1024)
	print("Client Sent: ", data.decode())
	msg = str(input("Enter a message: "))
	s.sendto(msg.encode(), addr)