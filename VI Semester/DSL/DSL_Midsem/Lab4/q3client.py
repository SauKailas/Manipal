import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host = socket.gethostname()
port = 9999

s.connect((host, port))

while True:
	msg = str(input("Enter a message: "))
	s.send(msg.encode())
	print("Client Sent: ", msg)
	data = s.recv(1024).decode()
	print("Server Sent: ", data)