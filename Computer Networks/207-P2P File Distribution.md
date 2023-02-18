# Peer to Peer architecture
---
- No centralized server
- Peers request service from other peers, provide service in return to other peers

Server transmission: must sequentially sends `N` file copies
Time to send one copy: F/u
Min client download time: F/dmin
Client => aggregate must download NF bits 
max upload rate: us + summation(ui)

Time to distribute F to N clients using P2P approach
```
D(P2P) > max{F/u, F/dmin, NF/(us + summation(ui))}
```
