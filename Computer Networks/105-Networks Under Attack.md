# Networks Under Attack
---
## Attack on host
- Malware: malicious software, many of which are self-replicating
- Botnet: network of thousands of compromised devices, mainly used for spam email distribution or distributed denial of service attacks
- Viruses: malware that require some form of user interaction to infect the user's device
- Worms: malware that can enter a device without explicit user interaction

## Attack on Servers and Network Infrastructure
### Denial-of-Service
- Attack that renders a network, host, or other piece of infrastructure unusable by legitimate users
- Most Internet DoS attacks fall into one of three categories:
	- Vulnerability attack: If the right sequence of packets is sent to a vulnerable application or operating system, the service can stop or the host can crash
	- Bandwidth flooding: The attacker sends a deluge of packets to the targeted host, clogging the target's access link and preventing legitimate packets from reaching the server
	- Connection flooding: The attacker establishes a large number of half-open or fully open TCP connections to make the host bogged down with bogus connections

#### Bandwidth flooding
If the server has an access rate of `R` bps, then the attack will need to send traffic at a rate of approximately `R` bps to cause damage. If `R` is very large, a single attack source may not be able to generate enough traffic to harm the server. If all the traffic emanates from a single source, an upstream router may be able to detect the attack and block all the traffic from that source before the traffic gets near the server.
In a Distributed DoS attack, the attacker controls multiple sources and has each source blast traffic at the target. DDoS attacks leverage botnets with thousands of compromised hosts
![ddos](https://github.com/Shogunkayo/PES_Notes/blob/main/Computer%20Networks/Images/ddos.png)
![[ddos.png]]
## Packet Sniffing
- Packets can contain all kinds of sensitive information, including passwords and private messages
- A passive receiver that records a copy of every packet that flies is called a packet sniffer
- Sniffers can be deployed in both wired and wireless environments
- Sniffers are difficult to detect as they do not inject packets into the channel (they are passive)
- Some of the best defenses against packet sniffing involve cryptography

## Identity Theft
- It is surprisingly easy to create a packet with an arbitrary source addres, packet content and destination address, and then transmit this hand-crafted packet into the Internet. This is known as IP spoofing
- End-point authentication is a mechanism that will allow us to determine with certainity if a message originates from where we think it does
