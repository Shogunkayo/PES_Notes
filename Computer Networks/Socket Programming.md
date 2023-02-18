# Socket Programming 
---
- Python UDPClient
```
from socket import *
server_name = 'hostname'
server_port = 12000
client_socket = socket(AF_INET, SOCK_DGRAM)

message = raw_input('Input lowercase sentence')
client_socket.sendto(message.encode(), (server_name, server_port))

modified_message, server_address = client_socket.recvfrom(2048)
print(modified_message.decode())
client_socket.close()
```

- Python UDPServer
```
from socket import *
server_port = 12000
server_socket = socket(AF_INET, SOCK_DGRAM)
server_socket.bind(("", server_port))
print("The server is ready to receive")

while True:
	message, client_address = server_socket.recvfrom(2048)
	modified_message = message.decode().upper()
	server_socket.sendto(modified_mesasge.encode(), client_address)
```

- Python TCPClient
```
from socket import *
server_name = 'server_name'
server_port = 12000

client_socket = socket(AF_INET, SOCK_STREAM)
client_socket.connect((server_name, server_port))
sentence = raw_input('Input lowercase sentence')
client_socket.send(sentence.encode())

modified_sentence = client_socket.recv(1024)
print('From server: ', modified_sentence.decode())
client_socket.close()
```

- Python TCPServer
```
from socket import *
server_port = 12000
server_socket = socket(AF_INET, SOCK_STREAM)
server_socket.listen(1)

print(" The server is ready to receive")
while True:
	connection_socket, addr = server_socket.accept()
	sentence = connection_socket.recv(1024).decode()
	capitalized_sentence = sentence.upper()

	connection_socket.send(capitalized_sentence.encode())
	connection_socket.close()
```