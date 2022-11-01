# Graph
----
- Non linear data structure where elements are represented as a node or vertex
- Nodes are connected with edges or arcs
- A graph is represented by G(V,E) -> an ordered pair of vertices and edges

| Tree                                       | Graph                                               |
| ------------------------------------------ | --------------------------------------------------- |
| Has a root node                            | No root node                                        |
| Traversal: preorder, inorder and postorder | Traversal: breadth first search, depth first search |
| Acyclic, hierarchical                      | Can be either cyclic or acyclic                     |
| Directed: root node to leaf                | Can be either directed or undirected                |

### Applications
1. Computer networks: [[E4-Network_Topologies]]
2. Finding shortest path
3. Social networks
4. Neural networks
5. Artificial Intelligence
6. Pathfinding algorithms
7. Resource allocation

### Types
1. Directed graph (Digraph) and Undirected graph
2. Weighted graph and Unweighted graph
3. Cyclic graph: a graph with atleast one path where the source and destination nodes are the same; Acyclic graph: a grahp with no cycles, for example a tree
4. Connected graph and Disconnected graph

### Terminologies
| Name          | Definition                                                                 |
| ------------- | -------------------------------------------------------------------------- |
| Vertex        | A node which holds the data element                                        |
| Edge          | Path between a pair of vertices                                            |
| Adjacency     | Two nodes are adjacent to each other if they are connected through an edge |
| Path          | Sequence of edges between the nodes                                        |
| Weighted edge | An edge which has a cost or a value associated with it                     |
| Degree        | Total number of edges connected to a vertex                                |
| In-degree     | Total number of incomming edges connected to a node                        |
| Out-degree    | Total number of outgoing edges connected to a node                         |
| Self loop     | A node which points to itself with a directed edge                                                                           |

## Properties
1. Undirected graph
   - The number of possible pairs in a `m` vertex graph is `m*(m-1)`
   - The number of edges is `m*(m-1)/2`
2. Directed graph
   - The number of possible pairs in a `m` vertext graph is `m*(m-1)`
   - The number of edges is less than or equal to`m*(m-1)`

## Representation
1. Adjacency matrix (2D array)
   - Mark 1 if there is a path between the two nodes, else 0
   - For a weighted graph, mark the weight instead of 1
   - The matrix is symmetric for an undirected graph and may be asymmetric for a directed graph
2. Adjacency List
   - A linked list of all the nodes
   - Each node has a list of its adjacent nodes

## [[E1-Implementation || Implementation]]

## [[E2-Traversal | Traversal]]

## [[E3-Connectivity | Connectivity of Graphs]]




