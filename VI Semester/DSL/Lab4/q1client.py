import socket

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
udp_host = socket.gethostname()
udp_port = 9991
message = "Hi, I am Saurabh Kailas"
s.sendto(message.encode(), (udp_host, udp_port))
time = s.recvfrom(1024)
print("Current time from server: ", time.decode())
s.close()