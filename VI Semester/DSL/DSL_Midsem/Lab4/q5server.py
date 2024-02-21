import socket

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
host = socket.gethostname()
port = 9998
s.bind((host, port))

while True:
	data, addr = s.recvfrom(1024)
	print("Client Sent: ", data.decode())

	if data == data[::-1]:
		ans = "YES"
	else:
		ans = "NO"

	s.sendto(ans.encode(), addr)
	print("Server Sent: ", ans)