# Network Core
---
- The mesh of packet switches and links that interconnects the Internet's end systems

# Packet Switching
----
To send a message from a source end system to a destination end system, the source breaks long messages into smaller chunks of data known as packets

- Transmission rate -> capacity of a link
- Transmission delay takes L/R seconds to transmit
- End-end delay : N -> No of links P -> No of packets
`(N+P-1)*L/R`

### Store-and-Forward Transmission
- Most packet switches use store-and-forward transmission at the inputs to the links
- The packet switch must receive the entire packet before it can begin to transmit the first bit of packet onto the outbound link
- A router first buffers the packet's bits. Only after it has received all of the packet's bits can it begin to transmit the packet onto the outbound link

### Packet Loss and Queuing Delay
- If arrival rate to a link exceeds transmission rate of link for a period of time, 
	- packets will queue, waiting to be transmitted on output link
	- packets can be dropped if memory buffer in router fills up

## Two Key Network
- Multiple links from a router
- Routers have a routing table or forwarding table that maps destination addresses to that router's outbound links
- Routing table is filled using a routing algorithms and routing protocols

# Circuit Switching
---
- The resources needed along a path to provide for communication between the end systems are reserved for the duration of the communication session between the end systems
- Traditional telephone networks are examples of circuit-switched networks
- The sender can transfer the data to the receiver at the guranteed constant rate
![ciruit.png](https://github.com/Shogunkayo/PES_Notes/blob/main/Computer%20Networks/Images/ciruit.png)

A circuit in a link is implemented with either Frequency Division Multiplexing or Time Division Multiplexing. In FDM, the frequency spectrum of a link is divided up among the connections established across the link. 
In TDM, time is divided into frames of fixed duration, and each frame in divided into a fixed number of time slots. When the network establishes a connection across a link, the network dedicates one time slot in every frame to this connection 
![multiplexing.png](https://github.com/Shogunkayo/PES_Notes/blob/main/Computer%20Networks/Images/multiplexing.png)

Circuit switching is wasteful because the dedicated circuits are idle during silent periods

# Packet Switching vs Circuit Switching
----
- Packet switching is not suitable for real-time services (telephone calls, video conference calls) because of its variable and unpredictable end-to-end delays
- Circuit switching is wasteful because the dedicated circuits are idle during silent periods
- Packet switching offers better sharing of transmission capacity than circuit switching and is simple, more efficient and less expensive to implement
- [Differences](https://www.geeksforgeeks.org/difference-between-circuit-switching-and-packet-switching/)

# Network of Networks
---
An  access ISP connecting to end systems is a small piece of a large puzzle -> the access ISPs themselves must be interconnected. This is done by creating a network of networks

- The naive idea of connecting each ISP directly to every other access ISP is too expensive

## Network Structure 1
- Interconnects all of the access ISPs with a single global transit ISP
- The global transit ISP is a network of routers and communication links that not only spans the globe, but also has at least one router near each of the hundreds of thousands of access ISPs
- Still too expensive
- The access ISP is called the customer and the global ISP the provider

## Network Structure 2
- Consists of hundreds of thousands of access ISPs and multiple global transit ISPs
- Access ISPs can choose among the competing global transit providers as a function of their pricing and services
- The global transit ISPs themselves must interconnect

## Network Structure 3
Not only are there multiple competing tier-1 ISPs, there may be multiple competing regional ISPs in a region. In such a heirarchy, each access ISP pays the regional ISP to which it connects, and each regional ISP pays the tier-1 ISP to which it connects (the access ISP can connect to the tier-1 ISP as well). Thus there is customer-provider relationship at each level of the heirarchy

## Network Structure 4
Adding Points of Presence, multi-homing, peering and Internet Exchange Points to structure 3 makes it resemble 
the real-world Internet more closely
- PoP is a group of one or more routers(at the same location)  in the provider's network where customer ISPs can connect into the provider ISP
- Multi-home is to connect to two or more provider ISPs
  - A pair of nearby ISPs at the same level of the heirarchy can peer, that is, they can directly connect their networks together so that all the traffic between them passes over the direct connection rather than through upstream intermediaries. Neither ISP pays the other when two ISPs peer. Tier-1 ISPs peer with each other, settlement-free
  - A third-party company can create an IXP which is a meeting point where multiple ISPs can peer together

## Network Structure 5
- Describes today's Internet
- Builds on top of structure 4  by adding content-provider networks
- Google is currently one of the leading examples of such a content-provider network. It has 50-100 data centers distributed accross the world. The data centres are interconnected via Google's private TCP/IP network which is seperate from the public Internet
- By creating its own network, a content-provider not only reduces its payments to upper-tier ISPs, but also has greater control of how its services are ultimately delivered to end users
![isp.png](https://github.com/Shogunkayo/PES_Notes/blob/main/Computer%20Networks/Images/isp.png)
