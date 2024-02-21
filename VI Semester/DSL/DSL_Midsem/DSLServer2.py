import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host = socket.gethostname()
port = 9999
s.bind((host, port))

s.listen()
conn, addr = s.accept()
cliname = conn.recv(1024).decode()
print("Connected with: ", cliname)

data = "SERVNAME"
conn.send(data.encode())

while True:
	num = conn.recv(1024).decode()

	if num == "-1":
		s.close()
		break
	print("Client sent: ", num)

	if num == num[::-1]:
		ans = "YES"
	else:
		ans = "NO"

	conn.send(ans.encode())
	print("Server sent: ", ans)