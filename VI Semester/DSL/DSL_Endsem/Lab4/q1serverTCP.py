import socket
import time

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host = socket.gethostname()
port = 9999

s.bind((host, port))
s.listen(5)

sock, addr = s.accept()
print("Connected To : ", addr)

msg = sock.recv(1024).decode()
print("Received : ", msg)

tm = time.ctime(time.time()) + "\r\n"
sock.send(tm.encode())

print("Sent : ", tm)

sock.close()