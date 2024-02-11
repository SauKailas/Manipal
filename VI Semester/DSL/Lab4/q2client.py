import socket

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
host = socket.gethostname()
port = 9990

while True:
	message = str(input("Enter a message: "))
	s.sendto(message.encode(), (port, host))
	print("Client Sent: ", message)
	data, addr = s.recvfrom(1024)
	print("Client Received: ", data.decode())