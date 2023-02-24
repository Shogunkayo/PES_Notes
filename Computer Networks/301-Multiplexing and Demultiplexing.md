# Multiplexing and Demultiplexing
---
- A process can have one or more sockets. The transport layer in the receiving host does not deliver data directly to a process, but instead to an intermediary socket
- Each socket has an unique identifier whose format depends on whether the socket is a UDP or a TCP socket
- Each transport layer segment has a set of fields which are examined by the transport layer to identify the receiving socket, and then directs the segment to that socket
- Delivering the data in a transport layer segment to the correct socket is called demultiplexing
- Gathering data chunks at the source host from different sockets, encapsulating each data chunk with header information to create segments, and passing the segments to the network layer is called multiplexing
- Multiplexing requires
	- that sockets have unique identifiers
	- that each segment has special fields (source port number field and destination port number field) that indicate the destination socket

![[port.png]]
 ![port](https://github.com/Shogunkayo/PES_Notes/blob/main/Computer%20Networks/Images/port.png)

- Each port number is a 16-bit number, ranging from 0 to 65535
- The port numbers ranging from 0 to 1023 are called well-known port numbers and are reserved for use by well known application protocols like HTTP and FTP

## Connectionless Multiplexing and Demultiplexing
- When creating a socket, the transport layer automatically assigns a port number in the range 1024 to 65535 that is currently not being used by any other UDP port in the host
- `bind()` method can be used to bind a specific port number to the socket
- UDP socket is fully identified by a two-tuple consisting of a destination IP address and a destination port number
- If two UDP segments have different source IP addresses or source port numbers, but the same destination IP address and destination port number, then the two segments will be directed to the same destination process via the same destination socket
- `recvfrom()` method is used to extract the source port number from the segment

## Connection Oriented Multiplexing and Demultiplexing
- TCP socket is identified by a four-tuple: source IP address, source port number, destination IP address, destination port number
- Two TCP segments with different source IP addresses or port numbers will be directed to two different sockets (with the exception of a TCP segment carrying the original connection-establishment request)
- The server host may support many simultaneous TCP connection sockets, with each socket attached to a process, and with each socket identified by its own four-tuple

## Web Servers
- When clients send segments to the server, all segments will have the same destination port
- There is not always a one-to-one correspondence between connection sockets and processes. Web servers often use only one process, and create a new thread with a new connection socket for each new client connection
- If the connection is persistent, then throughout the duration the client and server exchange HTTP messages via the same server socket