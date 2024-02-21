import socket

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
host = socket.gethostname()
port = 9998

while True:
	num = str(input("Enter a number: "))
	s.sendto(num.encode(), (host, port))
	print("Client Sent: ", num)

	data, addr = s.recvfrom(1024)
	print("Server Sent: ", data.decode())