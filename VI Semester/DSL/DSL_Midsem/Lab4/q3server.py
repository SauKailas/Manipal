import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host = socket.gethostname()
port = 9999
s.bind((host, port))

s.listen(5)
conn, addr = s.accept()

while True:
	msg = conn.recv(1024).decode()
	print("Client Sent: ", msg)
	msg = str(input("Enter a message: "))
	conn.send(msg.encode())
	print("Server Sent: ", msg)