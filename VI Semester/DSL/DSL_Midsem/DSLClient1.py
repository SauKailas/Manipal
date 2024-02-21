import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

host = socket.gethostname()
port = 9998

s.connect((host, port))

data = "CLINAME"
s.send(data.encode())

sername = s.recv(1024).decode()
print("Connected with: ", sername)

while True:
	num = int(input("Enter a number (-1 to exit): "))

	if num == -1:
		s.close()
		break

	s.send(str(num).encode())

	digsum = s.recv(1024).decode()
	print("Received from Server: ", digsum)