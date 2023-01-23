# Principles 
---
- The core of network application development is writing programs that run on different end systems and communicate with each other over the network
- Application software cannot be written for network-core devices
- Applications run in the Application Layer

## Architectures
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