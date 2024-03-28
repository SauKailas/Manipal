import socket
import datetime
from dateutil import parser
from timeit import default_timer as timer

def synchronizeTime():
	s = socket.socket()
	port = 9999
	s.connect(('127.0.0.1', port))

	request_time = timer()
	server_time = parser.parse(s.recv(1024).decode())
	response_time = timer()
	actual_time = datetime.datetime.now()

	print("Time Returned by Server: ", str(server_time))
	process_delay_latency = response_time - request_time
	print("Actual Clock Time at Client Side: ", str(actual_time))

	client_time = server_time + datetime.timedelta(seconds = (process_delay_latency) / 2)
	print("Synchronized Process Client Time: ", str(client_time))

	error = actual_time - client_time
	print("Synchronization Error: ", str(error.total_seconds()) + " seconds")

	s.close()

synchronizeTime()