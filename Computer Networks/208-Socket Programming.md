# Socket Programming 
---
- A typical network application consists of a client program and a server program residing in two different end systems
- When these two programs are executed, a client process and a server process are created, and these processes communicate with each other by reading from, and writing to, sockets
- Two types of network applications:
	1. implementation whose operation is specified in a protocol standard such as an RFC
	2. proprietary network application
- The developer needs to decide whether the application is to run over TCP or over UDP

## Socket Programming with UDP
Before the sending process can push a packet of data
out the socket, when using UDP, it must first attach a destination address to the packet. After the packet passes through the sender' s socket, the Internet will use this destination address to route the packet through the Internet to the socket in the receiving process. When the packet arrives at the receiving socket, the receiving process will retrieve the packet through the socket, and then inspect the packet' s contents and take appropriate action

Our application will perform the following tasks over both TCP and UDP
1. The client reads a line of characters (data) from its keyboard and sends the data to the server.
2. The server receives the data and converts the characters to uppercase.
3. The server sends the modified data to the client.
4. The client receives the modified data and displays the line on its screen.

### Python UDPClient
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
- The `socket` module forms the basis of all network communications in Python
- `socket(AF_INET, SOCK_DGRAM)` creates the client's socket. The first parameter indicates the address family, `AF_INET` indicates that the underlying network is using IPv4. The second parameter indicates that it is a UDP socket
- We are not specifying the port number of the client socket when we create it, we are instead letting the operating system do it for us
- We first convert the message from string type to byte type using `.encode()` method. `sendto()`method attaches the destination address to the message and sends the resulting packet into the process's socket
- `recvfrom(2048)` recevies data on a socket and stores it in a buffer of size 2048

### Python UDPServer
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
- `bind()` method binds the port number `server_port` to the server's socket

![[udpsocket.png]]
![udpsocket](https://github.com/Shogunkayo/PES_Notes/blob/main/Computer%20Networks/Images/udpsocket.png)

## Socket Programming with TCP
- The client and server first need to handshake and establish a TCP connection before they can start to send data to each other
- The three way handshake which takes place within the transport layer is completely invisible to the client and server programs
- The server creates a new socket dedicated to the particular client

![[tcpsocket.png]]
![tcpsocket](https://github.com/Shogunkayo/PES_Notes/blob/main/Computer%20Networks/Images/tcpsocket.png)

### Python TCPClient
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
- The second parameter in `socket()` method indicates that it is a TCP socket
- The `connect()` method initiates the TCP connection between the client and server
- The program does not explicitly create a packet and attach the destination address to the packet, instead it simply drops the bytes in the string `sentence` into the TCP connection

### Python TCPServer
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
- `accept()` method creates a new socket in the server called `connection_socket`

![[tcpsocket2.png]]
![tcpsocket2](https://github.com/Shogunkayo/PES_Notes/blob/main/Computer%20Networks/Images/tcpsocket2.png)