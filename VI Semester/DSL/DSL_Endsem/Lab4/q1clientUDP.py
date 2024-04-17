import socket 

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
host = socket.gethostname()
port = 9999

msg = "Hi, Can You Tell Me The Time Please?"
s.sendto(msg.encode(), (host, port))
data, addr = s.recvfrom(1024)
print("Current Time : ", data.decode())
s.close()