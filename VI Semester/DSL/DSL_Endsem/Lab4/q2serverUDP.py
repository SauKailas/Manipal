import socket

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
host = socket.gethostname()
port = 9999
s.bind((host, port))

while True:
	data, addr = s.recvfrom(1024)
	if data == "-1":
		s.close()
		break;
	print("Received : ", data.decode())
	msg = str(input("Enter a Message : "))
	s.sendto(msg.encode(), addr)
	print("Sent : ", msg)