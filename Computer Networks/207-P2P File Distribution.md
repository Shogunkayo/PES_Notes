# Peer to Peer Architecture
---
![[p2p.png]]
![p2p](https://github.com/Shogunkayo/PES_Notes/blob/main/Computer%20Networks/Images/p2p.png)

- Distribution time is the time it takes get a copy of the file to all N peers

Distribution time in client-server architecture
- The server must transmit one copy of the file to each of the N peers => server must transmit `NF` bits
- Since the server's upload rate is `u(s)`, the time to distribute the file mustt be atleast `NF/u(s)`
- `d(min)` is the download rate of the peer with the lowest download rate `d(min) = min{d(1), d(2), ..., d(N)}` 

```
D(cs) >= max{NF/u(s), F/d(min)}
```

Distribution time in p2p architecture
- The server must send each bit of the file at least once into its access link. The minimum distribution time is at least `F/u(s)`. A bit sent once by the server may not have to be sent by the server again, as the peers may redistribute the bit among themselves
- The peer with the lowest download rate cannot obtain all `F` bits of the file in less than `F/d(min)` seconds
- The total upload capacity of the system as a whole is equal to the upload rate of the server plus the upload rates of the individual peers `u(total) = u(s) + u(1) + u(2) + ... + u(N)`. The system must deliver `F` bits to each of the `N` peers thus delivering a total of `NF` bits
```
D(p2p) >= max{F/u(s), F/d(min), NF/u(total)}
```

![[p2pg.png]]
![p2pg](https://github.com/Shogunkayo/PES_Notes/blob/main/Computer%20Networks/Images/p2pg.png)

## BitTorrent
- Collection of all peers participating in the distribution of a particular file is called a torrent
- Peers in a torrent download equal size chunks of the file from one another, with a typical chunk size of 256 kbytes
- While a peer downloads a chunk, it also uploads chunks to other peers
![[bittorrent.png]]
![bittorrent](https://github.com/Shogunkayo/PES_Notes/blob/main/Computer%20Networks/Images/bittorrent.png)

- Each torrent has an infrastructure node called a tracker
- When a peer joins a torrent, it registers itself with the tracker and periodically informs the tracker that it is still in the torrent
- At any given time, each peer will have a subset of chunks from the file, with different peers having different subsets
- Periodically, the user will ask each of their neighbouring peers (over TCP connections) for the list of chunks they have
- The user issues requests (over TCP) for chunks they currently do not have
- Rarest first technique => determine from among the chunks a user does not have, the chunks that are the rarest among the neighbours and then request those rarest chunks first -> aiming to equalize the number of copeis of each chunk in the torrent
- The user gives priority to the neighbours that are currently supplying them data at the highest rate
- Such neighbours are said to be unchoked and every 10 seconds the rates are recalculated
- Every 30 seconds, the user picks an additional neighbour at random and sends it chunks. Such neighbour is said to be optimistically unchoked
