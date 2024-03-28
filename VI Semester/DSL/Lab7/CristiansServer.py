import socket
import datetime
import time 

def initiateClockServer():
	s = socket.socket()
	print("Socket Created Successfully!")
	port = 9999
	s.bind(('', port))
	s.listen(5)
	print("Socket is Listening...")

	while True:
		conn, addr = s.accept()
		print("Server Connected to: ", addr)
		conn.send(str(datetime.datetime.now()).encode())
	conn.close()

initiateClockServer()