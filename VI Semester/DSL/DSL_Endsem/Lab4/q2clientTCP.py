import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host = socket.gethostname()
port = 9999

s.connect((host, port))

while True:
	msg = str(input("Enter a message : "))
	s.send(msg.encode())
	if msg == "-1":
		s.close()
		break
	print("Sent : ", msg)
	msg = s.recv(1024).decode()
	print("Received : ", msg)