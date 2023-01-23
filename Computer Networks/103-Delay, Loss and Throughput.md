# PACKET DELAY
---
- As a packet travels from one node to the subsequent node along its path, it suffers from several types of delays at each node along the path
- 4 types of Nodal delays:
	- Nodal Processing delay
	- Queueing delay
	- Transmission delay
	- Propogation delay
- Total nodal delay `d(nodal) = d(proc) + d(queue) + d(trans) + d(prop)`
![delay.png](https://github.com/Shogunkayo/PES_Notes/blob/main/Computer%20Networks/Images/delay.png)

### Processing Delay
- Time required to examine the packet's header and determine where to direct the packet 
- Also includes other factors like time needed to check for bit-level errors in the packet that occured in transmitting the packet's bits from the upstream node to a router
- Typically in order of microseconds

### Queuing Delay
- At the queue, the packet experiences a queuing delay as it waits to be transmitted onto the link
- Traffic intensity is given by `La/R` where
	- `R` is the link bandwidth (bps)
	- `L` packet length (bits)
	- `a` is the average packet arrival rate (packets per second)
	- `La` is the average rate at which bits arrive at the queue
- If
	- `La/R` > 1 : average delay is infinite
	- `La/R` <= 1: nature of arriving traffic
	- `La/R` ~ 0: average queueing delay is small 

- Queuing delay is also calculated as `I*(L/R)*(1-I)` for `I < 1` where `I` is traffic intensity

![trafficdelay.png](https://github.com/Shogunkayo/PES_Notes/blob/main/Computer%20Networks/Images/trafficdelay.png)

### Transmission Delay
- The amount of time required to push all of the packet's bits into the link
- Delay is given by `L/R`
- It is a function of the packet's length and the transmission rate of the link
- Generally in order of microseconds to milliseconds

### Propogation Delay
- The time required to propogate from one router to the next
- Delay is given by `d/s` where `d` is the distance and `s` is the propogation speed which is approximated as `2 x 10^8` to `3 x 10^8`
- It is a function of the distance between the two routers

## Packet Loss
- A queue preceding a link has finite capacity
- A router will drop a packet if the queue is full
- Fraction of lost packets incerases as the traffic intensity increases
- Packets left in the buffer is given by `a - floor(1000/queuing delay)`
- Packets dropped = `packets - buffer size`

## End-to-End Delay
Suppose there are `N-1` routers between the source and destination, the network is uncongested (queuing delays are negligible)

`d(end-end) = N*(d(proc) + d(trans) + d(prop))`

### Traceroute
- When a router receives one of the special packets, it sends back to the source a short message that contains the name and address of the router
- For `N-1` routers between the source and the destination, the source will send `N` special packets into the network
- When the `nth` router receives the `nth` packet, it does not forward  it but instead sends a message back to the source
- The source records the time that elapses between when it sends a packet and when it receives the corresponding return message
- Traceroute repeats the above experiment three times so that total of `3N` packets are sent

![traceroute.png](https://github.com/Shogunkayo/PES_Notes/blob/main/Computer%20Networks/Images/traceroute.png)
- The output has six columns:
	- The first column is the `n` value ie the number of routers along the route
	- The second column is the name of the router
	- The third column is the address of the router
	- The last three columns are the round-trip delays for each experiment

### Other delays
- VoIP - Voice over IP - the sending side must first fill a packet with encoded digitized speech before passing the packet to the Internet. Time to fill is called packetization delay
- Some protocols might purposefully delay the transmissions for sharing the medium with other end systems

## Throughput
- Rate at which bits are being sent from sender to receiver 
- Depends on the rate of the link. Genrally, link from server to router is denoted as `Rs` and router to client as `Rc`
- Throughput = `min(Rs, Rc)`

![trhoughput.png](https://github.com/Shogunkayo/PES_Notes/blob/main/Computer%20Networks/Images/trhoughput.png)

- For `n`  connections, Throughput = `min(Rs,Rc,R/10)`
- Server or Client Utilization = `R(bottleneck)/R(server or client)`

184166