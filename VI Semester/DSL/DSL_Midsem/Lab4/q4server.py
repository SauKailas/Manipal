import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host = socket.gethostname()
port = 9997

s.bind((host, port))
s.listen(5)
conn, addr = s.accept()

data = conn.recv(1024)
print("Connected with: ", data.decode())

name = str(input("Enter name: "))
conn.send(name.encode())

while True:
	num = conn.recv(1024).decode()
	num = int(num)
	print("Client Sent: ", num)

	digits = []
	digsum = 0

	while num > 0:
		dig = num % 10
		num /= 10
		digits.append(dig)

	for ele in digits:
		digsum += ele

	digsum = str(digsum)

	conn.send(digsum.encode())
	print("Server Sent: ", str(digsum))