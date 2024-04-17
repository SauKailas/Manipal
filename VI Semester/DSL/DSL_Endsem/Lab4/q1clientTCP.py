import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host = socket.gethostname()
port = 9999

s.connect((host, port))

msg = "Hi, Can You Tell The Time Please?"
s.send(msg.encode())
print("Sent : ", msg)

time = s.recv(1024).decode()
print("Received : ", time)
s.close()