import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host = socket.gethostname()
port = 9997

s.connect((host, port))

name = str(input("Enter name: "))
s.send(name.encode())

data = s.recv(1024)
print("Connected with: ", data.decode())

while True:
	num = str(input("Enter a number: "))
	s.send(num.encode())
	print("Client Sent: ", num)

	digsum = s.recv(1024)
	print("Server Sent: ", digsum.decode())