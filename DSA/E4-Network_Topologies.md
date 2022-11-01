# TOPOLOGIES
----
- Graphs are mainly used in telecommunication and computer networks
- Networking uses the notation `G(N,L)` where `N` is the set of nodes and `L` is the set of links
- Topology is the orded in which nodes and edges are arranged in a network

## 1. Ring Topology
- Also called cycle graph
- Each vertex has a degree of 2 and the vertices are connected such that the graph forms a circle 
![ring1.png](https://github.com/Shogunkayo/PES_Notes/blob/main/DSA/Images/ring1.png)
![ring2.png](https://github.com/Shogunkayo/PES_Notes/blob/main/DSA/Images/ring2.png)
![ring3.png](https://github.com/Shogunkayo/PES_Notes/blob/main/DSA/Images/ring3.png)

## 2. Star Topology
- Consists of a central vertex which has links to other vertices
- The central vertex has a degree `n-1` where `n` is the total number of nodes. Other vertices have a degree of 1
![star1.png](https://github.com/Shogunkayo/PES_Notes/blob/main/DSA/Images/star1.png)
![star2.png](https://github.com/Shogunkayo/PES_Notes/blob/main/DSA/Images/start2.png)

## 3. Mesh Topology
- A complete graph where each node is connected to all the other nodes
- Each node has a degree `n-1` where `n` is the total number of nodes
![mesh1.png](https://github.com/Shogunkayo/PES_Notes/blob/main/DSA/Images/mesh1.png)
![mesh2.png](https://github.com/Shogunkayo/PES_Notes/blob/main/DSA/Images/mesh2.png)

## 4. Bus Topology
- A graph where starting and ending node have a degree of 1 and other nodes have a degree of 2 such that the graph forms a line

## 5. Hybrid Topology
- Combination of two or more topologies
 ![hybrid.png](https://github.com/Shogunkayo/PES_Notes/blob/main/DSA/Images/hybrid.png)

  
