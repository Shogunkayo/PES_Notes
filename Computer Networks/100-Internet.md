# Nuts and Bolts Description
----
- Description of the basic hardware and software components that make up the internet 

The internet is a computer network that interconnects billions of computing devices throughout the world. These devices can be traditional (pc, workstations) or non-traditional (laptops, smart phones, tvs). All of these devices are called **hosts** or **end systems**
![[nutsbolts1.png]]
![nutsbolts1.png](https://github.com/Shogunkayo/PES_Notes/blob/main/Computer%20Networks/Images/nutsbolts1.png)

![[nutsbolts2.png]]
![nutsbolts2.png](https://github.com/Shogunkayo/PES_Notes/blob/main/Computer%20Networks/Images/nutsbolts2.png)

End systems are connected together by a network of **communication links** and **packet switches**
- Different links are made up of different physical media and can transmit data at different rates (measured in bits/second)
- When one end system sends a message to another, it segments the data and adds header bytes to each segment -> **Packet**

## Packet Switch
- Takes a packet arriving on one of its incomming communication links and forwards the packet on one of its outgoing communication links
- Two prominent types: Routers and Link-Layer Switches
- Routers are typically used in the network core and link-layer switches in access networks
- The sequence of communication links and packet switches traversed by a packet from the sending end system to the recieving end system is called the route or path

## Internet Service Providers
- End systems access the internet through ISPs including residential ISPs, university ISPs and cellular data ISPs
- Each ISP is a network of packet switches and communication links
- ISPs are also interconnected. The lower-tier ISPs are interconnected through national and internation upper-tier ISPs such as Level 3 Communications, AT&T
- An upper-tier ISP consists of high speed routers interconnected with high speed fiber-optic links
- Each ISP network is managed independently

## Protocols
- End systems, packet switches and other pieces of internet run protocols that control the sending and recieving of information within the Internet
- **Transmission Control Protocol** and **Internet Protocol** are two of the most important protocols in the Internet
- **Internet Standards** are developed by the Internet Engineering Task Force. The documents are called **Requests for comments**
- RFCs define protocols such as TCP, IP, HTTP, SMTP

# Services Description
----
- The Internet can also be described as an infrastructure that provides services to applications
- Internett applications include e-mail, web surfing, mobile and tablet applications, online messaging, multiplayer games
- The applications are said to be distributed applications as they involve multiple end systems that exchange data with each other
- Applications run on end systems, not on packet switches
- Packet switches are not concerned with the application that is the source or sink of data

End systems attached to the Internet provide a **socket interface** that specifies how a program running on one end system asks the Internet infrastructure to deliver data to a specific destination program running on another end system
- The Internet socket interface is a set of rules that the sending program must follow so that the Internet can deliver the data to the destination program

# Protocol
---
![[protocol.png]]
![protocol.png](https://github.com/Shogunkayo/PES_Notes/blob/main/Computer%20Networks/Images/protocol.png)

A protocol defines the format and the order of messages exchanged between two or more communicatinf entities, as well as the actions taken on the transmission and/or receipt of a message or other event
- Different protocols are used to accomplish different communication tasks
