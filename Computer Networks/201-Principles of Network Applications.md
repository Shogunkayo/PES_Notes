# Principles 
---
- The core of network application development is writing programs that run on different end systems and communicate with each other over the network
- Application software cannot be written for network-core devices
- Applications run in the Application Layer

# Architectures
---
- Application architecture is designed by the application developer and dictates how the application is structured over the various end systems

### Client-Server Architecture
- There is an always-on host called the server, which services requests from many other hosts called clients
- Clients do not directly communicate with each other
- Server has a fixed, well known address
- A single server host is incapable of keeping up with all the requests from the clients. A data center, housing a large number os hosts, is often used to create a powerful virtual server

### P2P Architecture
- There is minimal reliance on dedicated servers in data centers
- Application exploits direct communication between pairs of intermittently connected hosts called peers
- They are self-scalable and cost effective
- They face challenges of security, performance and reliability due to their highly decentralized structure
![[apparch.png]]
![apparch](https://github.com/Shogunkayo/PES_Notes/blob/main/Computer%20Networks/Images/apparch.png)

# Process Communication
----
- A process can be thought of as a program that is running within an end system
- Processes on two different end systems commnicate with each other by exchanging message across the computer network
- Processes lie in the Application Layer

> In the context of a communication session between a pair of processes, the process that initiates the communication (that is, initially contacts the other process at the beginning of the session) is labeled as the client. The process that waits to be contacted to begin the session in the server

### Socket
- A process sends messages into, and receives messages from, the network through a software interface called a socket
- It is the interface between the Application Layer and the Transport layer within a host
- Also referred to as the API between the application and the network
- The application developer has control of everything on the application layer side of the socket
- The only control that the developer has on the transport layer side is
	- the choice of transport protocol
	- the ability to fix a few transport layer parameters such as maximum buffer and maximum segment size

![[socket.png]]
![socket](https://github.com/Shogunkayo/PES_Notes/blob/main/Computer%20Networks/Images/socket.png)

Socket  => IP address + Port number 
To identify the receiving process, the address of the host and an identifier that specifies the receiving process in the destination host need to be specified. The host is identified by its IP address. An IP address is a 32-bit quantity. The sending process must also identify the receiving process running in the host. A destination port number serves this purpose. Popular applications have been assigned specific port numbers.
- Web server is identified by port number 80
- A mail server process using SMTP (Simple Mail Transfer Protocol) is identified by port number 25

# Transport Services
---
## Available to Applications
### Reliable Data Transfer
- A packet can overflow a buffer in a router, or can be discarded by a host or router after having some of its bits corrupted. For many applications like email and financial applications, data loss can have devastating consequences
- If a protocol provides a guranteed data delivery service, it is said to provide reliable data transfer
- Multimedia applications have some amount of loss-tolerance

### Throughput
- As other sessions will be sharing the bandwidth along the network path, the available throughput can fluctuate with time
- A  transport layer protocol can provide guranteed available throughput at some specified rate
- Applications that have throughput requirements are said to be bandwidth-sensitive applications like many current multimedia applications
- Elastic applications can make use of as much or as little throughput as happens to be available

### Timing
- A transport layer protocol can also provide timing guarantees
- Usefull for interactive real-time applications like multiplayer games and teleconferencing

### Security
- A transport protocol can provide an application with one or more security services like encryption, data integrity and end-point authentication

## Provided by the Internet
### TCP
- TCP service model includes a connection-oriented service and a reliable data transfer service
- TCP has the client and server exchange transport-layer control information with each other before the application-level messages begin to flow => TCP handshake
- The connection is a full-duplex connection in that the two processes can send messages to each other over the connection at the same time
- When the application finishes sending messages, it must tear down the connection
- The communicating proesses can rely on TCP to deliver all data sent without error and in proper order

#### Security
- Neither TCP nor UDP provide any encryption
- Internet community developed an enhancement for TCP called Secure Sockets Layer
- SSL provides critical process-to-process security services including encryption, data integrity, and end-point authentication

### UDP
- No-frills, lightweight transport protocol providing minimal services
- UDP is connectionless, so there is no handshaking
- Provides unrealiable data transfer
- Does not include a congestion control mechanism

![[tcpudp.png]]
![tcpudp](https://github.com/Shogunkayo/PES_Notes/blob/main/Computer%20Networks/Images/tcpudp.png)

# Application Layer Protocols
---
- Defines how an application's processes, running on different end systems, pass messages to each other
- An application layer protocol defines:
	- The type of messages exchanged => request and response messages
	- The syntax of the various message types
	- The semantics of the fields
	- Rules for determining when and how a process sends messages and responds to messages

| Application     | Application Protocol |
| --------------- | -------------------- |
| Web application |                      |
