import socket 

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host = socket.gethostname()
port = 9999

s.bind((host, port))
s.listen(5)
sock, addr = s.accept()
print("Connected To : ", addr)

while True:
	msg = sock.recv(1024).decode()
	print("Received : ", msg)
	if msg == "-1":
		sock.close()
		break
	msg = str(input("Enter a Message : "))
	sock.send(msg.encode())
	print("Sent : ", msg)