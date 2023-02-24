# Transport Layer
---
- A transport layer protocol provides for logical communication between application processes running on different hosts
- Logical -> from an application's perspective, it is as if the hosts running the processes are directly connected; in reality, the hosts may be on the opposite sides of the planet, connected via numerous routers a wide range of link types
- Transport layer protocols are implemented in the end systems, not in the network routers

On the sending side, the transport layer converts the application layer messages it receives into segments by breaking the application messages into smaller chunks and adding a transport layer header to each chunk. The transport layer passes the segment to the network layer where the segment is encapsulated within a datagram and sent to the destination. On the receiving side, the network layer extracts the segment from the datagram and passes it up to the transport layer, where it is processes and the data is made available to the receiving application

- A transport layer protocol provides logical communication between processes running on different hosts, a network layer protocol provides logical communication between hosts
- Within an end system, a transport protocol moves messages from application processes to the network edge and vice versa, but it doesn't have any say about how the messages are moved within the network core

## Services
- Network layer's IP service model is a best-effort delivery service: the IP makes its best effort to deliver segments between communicating hosts, but it makes no gurantees => IP is said to be an unreliable service
- UDP provides only two services => process-to-process data delivery and error checking. It is also an unreliable service
- TCP provides reliable data transfer and congestion control, along with process-to-process data delivery and error checking