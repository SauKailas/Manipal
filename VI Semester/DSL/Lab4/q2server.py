import socket

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
host = socket.gethostname()
port = 9990
s.bind((host, port))

while True:
	data, addr = s.recvfrom(1024)
	print("Server Received: ", data.decode())
	message = str(input("Enter a message: "))
	s.sendto(message.encode(), (port, host))
	print("Server Sent: ", message)