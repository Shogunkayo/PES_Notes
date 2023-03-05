# Pipelined Reliable Data Transfer Protocols
---
- Protocol `rdt3.0` is a functionally correct protocol, but lacks in performance

![[pipelined.png]]
![pipelined](https://github.com/Shogunkayo/PES_Notes/blob/main/Computer%20Networks/Images/pipelined.png)

- In stop and wait operation, majority of time is spent waiting for ACK
- Utilization = `(L/R)/(RTT + L/R)`
- With pipeline, the sender is allowed to send multiple packets without waiting for acknowledgements
- The range of sequence numbers must be increased as each in-transit packet must have a unique sequence number and there may be multiple, in-transit, unacknowledged packets
- The sender and receiver sides of the protocols may have to buffer more than one packet

![[pipelined2.png]]
![pipelined2](https://github.com/Shogunkayo/PES_Notes/blob/main/Computer%20Networks/Images/pipelined2.png)

## Go-Back-N (GBN)
- The sender is allowed to transmite multiple packets without waiting for an acknowledgement, but is constrained to have no more than `N` unacknowledged packets in the pipeline
- The sequence number of the oldest unacknowledged packet is called `base` and the smallest unused sequence number (the sequence number of the next packet to be sent) is called `nextseqsum`

![[gbn.png]]
![gbn](https://github.com/Shogunkayo/PES_Notes/blob/main/Computer%20Networks/Images/gbn.png)

- Sequence numbers `[0, base-1]` correspond to packets that have already been transmitted and acknowledged
- `[base, nextseqsum-1]` correspond to packets that have been sent but not yet acknowledged
- `[nextseqsum, base+N-1]` correspond to packets that can be sent immediately, should data arrive from the upper layer
- Sequence numbers greater than or equal to `base + N` cannot be used until an unacknowledged packet currently in the pipeline (the packet with sequence number `base`) has been acknowledged
- The range of permissible sequence numbers for transmitted but not yet acknowledged packets can be viewed as a window of size `N`
- `N` is called the window size and the GBN protocol is called sliding-window protocol
- Flow control is one reason to impose a limit on the sender
- A packet's sequence number is carried in a fixed-length field in the packet header. If `k` is the number of bits in the packet sequence number field, the range of sequence numbers is `[0, 2^k - 1]`. All arithmetic involving sequence numbers must be done using modulo `2^k`

![[gbnfsm.png]]
![gbnfsm](https://github.com/Shogunkayo/PES_Notes/blob/main/Computer%20Networks/Images/gbnfsm.png)

### GBN sender
- The GBN sender must respond to three types of events

#### Invocation from above
- When `rdt_send()` is called from above, the sender first checks to see if the window is full
- If the window is not full, a packet is created and sent, and variables are appropriately updated
- If the window is full, the sender simply returns the data back to the upper layer. The upper layer presumably then have to try again later
- In a real implementation, the sender would more likely have either buffered the data, or would have a synchronization mechanism that would allow the upper layer to call `rdt_send ` only when the window is not full

#### Receipt of an ACK
- An acknowledgement for a packet with a sequence number `n` will be taken to be a cumulative acknowledgement, indicating that all packets with a sequence number up to and including `n` have been correctly received at the receiver

#### Timeout event
- Sender uses only a single timer, which is used for the `base`
- If an ACK is received but there are still additional transmitted but not yet acknowledged packets, the timer is restarted
- If there are no outstanding, unacknowledged packets, the timer is stopped

### GBN receiver
- If a packet with sequnce number `n` is received correctly and is in order, the receiver sends an ACK for packet `n` and delivers the data portion of the packet to the upper layer
- In all othere cases, the receiver discards the packet and resends an ACK for the most recently received in-order packet
- The receiver need not buffer any out-of-order packets
- While the sender must maintain the upper and lower bounds of its window and the position of `nextseqnum` within this window, the receiver only needs to maintain the sequence number of the next in-order packet, which is held in `expectedseqnum`

![[gbnop.png]]
![gbnop](https://github.com/Shogunkayo/PES_Notes/blob/main/Computer%20Networks/Images/gbnop.png)

## Selective Repeat (SR)
- There are scenarios in which GBN itself suffers from performance problems. When the window size and bandwidth delay product are both large, many packets can be in the pipeline. A single packet error can thus cause GBN to retransmit a large number of packets, many unnecessarily
- Selective repeat protocols avoid unnecessary retransmission by having the sender retransmit only those packets that it suspects were received in error at the receiver
- This individual retransmission will require that the receiver individually acknowledge correctly received packets
- Unlike GBN, the sender will have already received ACKs for some of the packets in the window 
- The SR receiver will acknowledge a correctly received packet whether or not it is in order. Out-of-order packets are buffered until any missing packets are received, after which a batch of packets can be delivered in order to the upper layer

![[sr.png]]
![sr](https://github.com/Shogunkayo/PES_Notes/blob/main/Computer%20Networks/Images/sr.png)

### SR Sender
#### Data received from above
- When data is received from above, the SR sender checks the next available sequence number for the packet
- If the sequence number is within the sender's window, the data is packetized and snet
- Otherwise it is either buffered or returned to the upper layer for later transmission

#### Timeout
- Timers are used to protect against lost packets
- Each packet must have its own logical timer, since only a single packet will be transmitted on timeout
- A single hardware timer can be used to mimic the operation of multiple logical timers

#### ACK received
- If an ACK is received, the SR sender marks that packet as having been received, provided it is in the window
- If the packet's sequence number is equal to `send_base`, the window base is moved forward to the unacknowledged packet with the smallest sequence number
- If the window moves and there are untransmitted packets with sequence numbers that now fall within the window, these packets are transmitted

### SR Receiver
#### Packet with sequence number in `[rvc_base, rcv_base + N - 1]` is correctly received
- The received packet falls within the receiver's window and a selective ACK packet is returned to the sender
- If the packet was not previously received, it is buffered
- If this packet has a sequence number equal to the base of the receive window, then this packet and any previously buffered and consecutively numbered packets are delivered to the upper layer
- The receive window is then moved forward by the number of packets delivered to the upper layer

#### Packet with sequence number in `[rcv_base - N, rcv_base - 1]` is correctly received
- An ACK must be generated, even though this is a packet that the receiver has previously acknowledged
- If there is no ACK for packet `send_base` propagating from the receiver to the sender, the sender will eventually retransmit packet `send_base` even though the receiver has alreadt received that packet
- If the receiver were not to acknowledge this packet, the sender's window would never move forward
- The sender and receiver will not always have an identical view of what has been received correctly and what has not

#### Otherwise
- Ignored

![[srop.png]]
![srop](https://github.com/Shogunkayo/PES_Notes/blob/main/Computer%20Networks/Images/srop.png)

### Window size
- The window size must be less than or equal to half the size of the sequence number space for SR protocols

![[srwin.png]]
![srwin](https://github.com/Shogunkayo/PES_Notes/blob/main/Computer%20Networks/Images/srwin.png)