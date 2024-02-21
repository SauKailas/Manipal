import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host = socket.gethostname()
port = 9999

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
	print("Client sent: ", num)

	palin = s.recv(1024).decode()
	if palin == "YES":
		print("Server sent: PALINDROME!")
	else:
		print("Server sent: NOT PALINDROME!")