import socket 

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
host = socket.gethostname()
port = 9999

while True:
	msg = str(input("Enter a message : "))
	s.sendto(msg.encode(), (host, port))
	if msg == "-1":
		s.close()
		break
	print("Sent : ", msg)
	data, addr = s.recvfrom(1024)
	print("Received : ", data.decode())