import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

host = socket.gethostname()
port = 9998
s.bind((host, port))

s.listen()
conn, addr = s.accept()
cliname = conn.recv(1024).decode()
print("Connected with: ", cliname)

data = "SERVNAME"
conn.send(data.encode())

while True:
	num = conn.recv(1024).decode()
	num = int(num)

	if num == '-1':
		s.close()
		break
	print("Client sent: ", num)

	digits = []
	while num > 0:
		temp = num % 10
		digits.append(temp)
		num = num // 10

	digsum = 0
	for ele in digits:
		digsum += ele

	conn.send(str(digsum).encode())
	print("Sent to Client: ", digsum)
