# Protocol Layers
----
- A layered architecture breaks a large and complex system into well-defined specific parts
- The implementation of a service can be changed without affecting other components of the system
- Each layer provides its service by 
	- performing certain actions within that layer
	- using the services of the layer directly below it
- OSI (Open Systems Interconnect) reference model 
	- 7 stack layer
	- Application, Presentation, Session -> User support layers
	- Transport -> Heart
	- Network, Data Link, Physical -> Network support layers
	- Theoretical, never implemented
	- Presentation and Session layers are not present in the 5 stack TCP/IP model
	- Presentation layer provides services that allow communicating applications to interpret the meaning of data exchanged. The session layer provides for delimiting and synchronization of data exchange, including the means to build a checkpointing and recovery scheme

## Application Layer
- Layer where network applications and thier application-layer protocols reside

| Protocols | Description                                                                       |
| --------- | --------------------------------------------------------------------------------- |
| HTTP      | web document request and transfer                                                 |
| SMTP      | transfer of email messages                                                        |
| FTP       | transfer of files                                                                 |
| DNS       | Domain Name System, translation of human friendly names to 32-bit network address |
| IMAP      | used by email clients to to retrieve email messages from a mail server                                                                                  |

- Protocols are distributed over multiple end systems
- Packets are referred as **messages**

## Transport Layer
- Transports application-layer messages between application endpoints
- TCP provides a connection-oriented service to its applications. This service includes guranteed delivery of application-layer messages to the destination and flow control. TCP also breaks long messages into shorter segments and provides a congestion-control mechanism
- UDP provides a connectionless service to its applications. Provides no reliability, no flow control and no congestion control, but is faster than TCP. Generally used in live streaming applications
- Transport-layer packets are called **segments**

## Network Layer
- Layer responsible for moving network-layer packets known as **datagrams** from one host to another
- The transport layer provides a segment and a destination address to the network layer
- IP defines the fields in the datagram as well as how the end systems and routers act on these fields. 
- Also contains routing protocols
- Network layer is also called IP layer

## Link Layer
- Network layer passes the datagram to the link layer which delivers the datagram to the next node along the route. At the next node, the link layer passes the datagram up to the network layer
- Some protocols are Ethernet, WiFi and DOCSIS(cable access network)
- Link layer packets are called **frames**

## Physical Layer
- Moves the individual bits within the frame from one node to the next
- Protocols are link dependent and further depend on the actual transmission medium of the link

![[protlay.png]]

At the sending host, an application-layer message is passed to the transport layer. The transport layer takes the message and appends additional information that will be used by the receiver-side transport layer. The application-layer and the transport-layer header information together constitute the transport-layer segment. The added information might include error-detection bits. The transport layer then passes the segment to the network layer, which adds network-layer header information such as source and destination end system addresses, creating a network-layer datagram. The datagram is then passed to the link layer, which will add its own link-layer header information and create a link-layer frame. At each layer, a packet has two types of fields: **header fields** and **payload field**. The payload is typically a packet from the layer above