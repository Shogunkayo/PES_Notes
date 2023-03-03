# Principles of Reliable Data Transfer
---
- The problem of implementing reliable data transfer occurs not only at the transport layer, but also at the link layer and the application layer

![[reliabledata.png]]
![reliabledata](https://github.com/Shogunkayo/PES_Notes/blob/main/Computer%20Networks/Images/reliabledata.png)

- It is the responsibility of a reliable data transfer protocol to implement the service abstraction. Problem is that the layer below the reliable data transfer protocol may be unreliable
- TCP is a reliable data transfer protocol that is implemented on top of an unreliable end-to-end network layer (IP)

The sending side of the data transfer protocol will be invoked from above by a call to `rdt_sned()`. It will pass the data to be delivered to the upper layer at the receiving side. On the receiving side, `rdt_rcv()` will be called when a packet arrives from the receiving side of the channel. To deliver data to the upper layer, the `rdt` protocol will call `deliver_data()`. Both the send and receive sides of `rdt` send packets to the other side by a call to `udt_send()`

The arrows in the FSM indicate the transition of the protocol from one state to another. The event causing the transition is shown above the horizontal line labeling the transition, and the actions taken when the event occurs are shown below the horizontal line. The symbol `A` is used below or above the horizontal, respectively, to explicitly denote the lack of an action or event. The initial state of the FSM is indicated by the dashed arrow.

## rdt1.0
- Case where the underlying channel is completely reliable. The protocol `rdt1.0` is trivial
- The sender and receiver FSMs each have just one state

![[rdt10.png]]
![rdt10](https://github.com/Shogunkayo/PES_Notes/blob/main/Computer%20Networks/Images/rdt10.png)

- The sending side of `rdt` accepts data from the upper layer via `rdt_send(data)` event. It creates a packet containing the data via `make_pkt(data)` and sends the packet into the channel.
- In practice, the `rdt_send(data)` event would result from a procedure call by the upper-layer application
- On the receiving side, `rdt` receives a packet from the underlying channel via `rdt_rcv(packet)` event. It removes the data from the packet via `extract(packet, data)` and passes the data up to the upper layer via `deliver_data(data)`
- In practice, the `rdt_rcv(packet)` event would result from a procedure call from the lower-layer protocol

## rdt2.0
- Model where underlying channel is one in which bits in a packet may become corrupted typically in the physical components of a network
- Positive acknowledgements `ACK` and negative acknowledgements `NAK` are used to let the sender know what has been received correctly, and what has been received in error and thus requires repeating
- Reliable data transfer protocols based on such retransmission are known as Automatic Repeat reQuest protocols `ARQ`
- Three additional protocol capabilities are required in ARQ protocols to handle the presence of bit errors

### Error detection
- UDP uses Internet checksum field
- There are many techniques which require extra bits to be sent from the sender to the receiver; these bits will be gathered into the packet checksum field of `rdt2.0` data packet

### Receiver feedback
- The positive `ACK` and negative `NAK` acknowledgement replies in the message need to be only 1 bit long: 0 could indicate `NAK` and 1 could indicate `ACK`

### Retransmission
- A packet that is received in error at the receiver will be retransmitted by the sender

![[rdt20.png]]
![rdt20](https://github.com/Shogunkayo/PES_Notes/blob/main/Computer%20Networks/Images/rdt20.png)

The send side of rdt2.0 has two states
- In the leftmost state, the send side protocol is waiting for data to be passed down from the upper layer. 
- When `rdt_send()` event occurs, the sender will create a packet containing the data to be sent using `make_pkt()`, along with a packet checksum, and then send the packet via `udt_send()` operation.
- In the righmost state, the sender protocol is waiting for an `ACK` or `NAK` packet from the receiver. 
- If an `ACK` packet is received (`rdt_rcv(rcvpkt) && isAck(rcvpkt)`), the sender knows that the most recently transmitted packet has been received correctly and thus the protocol returns to the state of waiting for data from the upper layer
- If a `NAK` is received, the protocol retransmits the last packet and waits for an `ACK` or `NAK` to be returned by the receiver in response to the retransmitted data packet
- When the sender is in the state of waiting for a reply, it cannot get more data from the upper layer (`rdt_send()` cannot occur)
- The sender will not send a new piece of data until it is sure that the receiver has correctly received the current packet. `rdt2.0` is also called stop-and-wait protocol

The receiver side has a single state
- On the packet arrival, the receiver replies with either an `ACK` or `NAK`, depending on whether or not the received packet is corrupted

### Flaw
- `rdt2.0` does not account for the possibility that the `ACK` or `NAK` packet could be corrupted
- If an `ACK` or `NAK` is corrupted, the sender has no way of knowing whether or not the receiver has correctly received the last piece of transmitted data
- Three possibilites for handling this problem
1. Introducing a new type of sender-to-receiver packet to the protocol. But if this packet too can get corrupted
2. Add enough checksum bits to allow the sender to also recover from bit errors. This solves the problem for a channel that can corrupt packets but not lose them
3. Resend the current data packet when the sender receives a garbled `ACK` or `NAK` packet. This introduces duplicate packets into the channel. The receiver doesn't know whether the `ACK` or `NAK` it last sent was received correctly at the sender

## rdt2.1
- A simple solution to the problem in `rdt2.0` is to add a new field to the data packet and have the sender number its data packets by putting a sequence number into this field
- The receiver needs to check this sequence number to determine whether packet is a retransmission (the sequence number of the received packet has the same sequence number as the most recently received packet) or a new packet (the sequence number changes, moving forward in modulo-2 arithmetic)

![[rdt21s.png]]
![rdt21s](https://github.com/Shogunkayo/PES_Notes/blob/main/Computer%20Networks/Images/rdt21s.png)

![[rdt21r.png]]
![rdt21r](https://github.com/Shogunkayo/PES_Notes/blob/main/Computer%20Networks/Images/rdt21r.png)

When an out of order packet is received, the receiver sends a positive acknowledgement for the packet it has received. When a corrupted packet is received, the receiver sends a negative acknowledgement

## rdt2.2
- Instead of sending a `NAK`, an `ACK` is sent for the last correctly received packet
- A sender that receives two `ACK`s for the same packet knows that the receiver did not correctly receiver did not correctly receive the packet following the packet that is being `ACK`ed twice
- The receiver must include the sequence number of the packet being acknowledged (including the `ACK, 0` or `ACK, 1` argument in `make_pkt()` in the receiver FSM)
- The sender must check the sequence number of the packet being acknowledged by a received `ACK` message (including the `0` or `1` argument in `isACK()` in the sender FSM)

![[rdt22s.png]]
![rdt22s](https://github.com/Shogunkayo/PES_Notes/blob/main/Computer%20Networks/Images/rdt22s.png)

![[rdt22r.png]]
![rdt22r](https://github.com/Shogunkayo/PES_Notes/blob/main/Computer%20Networks/Images/rdt22r.png)

## rdt3.0
- In addition to corrupting bits, the underlying channel can lose packets as well
- Two additional concerns: how to detect packet loss and what to do when packet loss occurs
- The use of checksum, sequence numbers, `ACK` packets and retransmissions allow us to answer the latter concern
- If a packet is lost, the sender does not receive a reply. If the sender is willing to wait long enough so that it is certain that a packet has been lost, it can simply retransmit the data packet
- The sender must wait at least as long as a round-trip delay between the sender and the receiver plus the amount of time needed to process a packet at the receiver
- In many networks, the worst case maximum delay is very difficult to even estimate. Moreover, the protocol should ideally recover from packet loss as soon as possible
- The approach thus adopted in practice is for the sender to judiciously choose a time value such that packet loss is likely, although not guranteed, to have happened
- Although this introduces the possibility of duplicate data packets, `rdt2.2` already has enough functionality to handle it
- The sender does not know whether a data packet was lost, an `ACK` was lost, or if either of them were overly delayed. In all cases, the action is the same: retransmit
- Implementing a time-based retransmission mechanism requires a countdown timer that can interrupt the sender after a given amount of time has expired
- The sender needs to be able to start the timer each time a packet is sent, respond to a timer interrupt, and stop the timer
- Because packet sequence numbers alternate between 0 and 1, protocol `rdt3.0` is sometimes known as the alternating bit protocol

![[rdt30.png]]
![rdt30](https://github.com/Shogunkayo/PES_Notes/blob/main/Computer%20Networks/Images/rdt30.png)

![[rdt30w.png]]
![rdt30w](https://github.com/Shogunkayo/PES_Notes/blob/main/Computer%20Networks/Images/rdt30w.png)