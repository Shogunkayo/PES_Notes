# BREADTH FIRST SEARCH
---
- Uses a queue data structure
- Level order traversal
- Can get multiple traversals
- Nodes are divided into visited and unvisted to avoid repetition
- For disconnected  and driected graphs, there is a possibility that some nodes cannot be reached

### Algorithm
1. Enqueue the source node
2. Enqueue adjacent unvisited nodes of the source node
3. Dequeue and mark the node as visited by using an array which stores all the visited nodes
4. Repeat the steps untill all the nodes are explored

### Implementation
A secondary array is used to check if a particular node has been visited or not
**Refer E1-Implementation for the functions used below or graph.c to see the entire program for both adjacency list and matrix**
```
typedef struct Queue{
    int data;
    struct Queue* next;
}queue_node;


void enqueue(queue_node** queue, int x){
    queue_node* temp = (queue_node*)malloc(sizeof(queue_node));
    temp->data = x;
    temp->next = NULL;
    
    if((*queue) == NULL){
        *queue = temp;
    }
    else{
        queue_node* present = *queue;
        while(present->next != NULL){
            present = present->next;
        }

        present->next = temp;
    }
}

int dequeue(queue_node** queue){
    if(*queue != NULL){
        queue_node* temp = *queue;
        *queue = (*queue)->next;
        int data = temp->data;
        
        free(temp);
        return data;
    }

    return -1;
}

void bfs(int adj[][N], int visited[], int source, queue_node** queue){
    enqueue(queue, source);
    visited[source] = 1;

    while(*queue != NULL){
        for(int i=0; i<N; i++){
            if(adj[source][i]  && !visited[i]){
                enqueue(queue, i);
                visited[i] = 1;
            }
        }
        printf("%d\n", dequeue(queue));
        if(*queue != NULL){
            source = (*queue)->data;
        }
    }
}

int main(){
    N = 8;
    int arr[][2] = {{1,2}, {1,5}, {4,7}, {2,3}, {5,6}, {5,4}, {6,7}};
    M = sizeof(arr)/sizeof(arr[0]);

    int adj[N][N];
    int visited[N];
    int source = 1;
    queue_node* queue = NULL;
    
    adjacency_matrix(adj, arr);
    display(adj);
    initialize_visited(visited);
    bfs(adj, visited, source, &queue);
}
```

### Advantages
- Always finds optimal solutions

### Disadvantages
- Consumes more memory as all the connected vertices needs to be stored

### Applications
- Finding the shortest path 
- Web crawlers
- GPS navigation system
- Finding a path in a network
- Broadcast packets in a network

# DEPTH FIRST SEARCH
---
- Uses a stack data structure
- Similar to preorder traversal

Let `a` be the source node for the given graph,
![[dfs.png]]

### Algorithm
1. Declare a stack and initialize top to -1
2. Push the source vertex onto the stack and mark it as visited
3. While the stack is not empty, access the topmost element
4. If the stack has unvisited vertex, push the adjacent unvisited vertex and mark it visited. Display the vertex. Else pop from the stack

### Implementation
A secondary array is used to check if a particular node has been visited or not
**Refer E1-Implementation for the functions used below or graph.c to see the entire program for both adjacency list and matrix**

#### Adjacency List
```
void initialize_visited(int visited[]){
    for(int i=0; i<N; i++){
        visited[i] = 0;
    }
}

void dfs(int adj[][N], int visited[], int source){
    visited[source] = 1;
    printf("%d\n", source);

    for(int i=0; i<N; i++){
        if(adj[source][i] && !visited[i]){
            dfs(adj, visited, i);
        }
    }
}

int main(){
    N = 5;
    int arr[][2] = {{1,2}, {1,3}, {2,1}, {2,4}, {3,1}, {3,4}, {4,2}, {4,3}};
    M = sizeof(arr)/sizeof(arr[0]);

    int adj[N][N];
    int visited[N];
    int source = 1;

    adjacency_matrix(adj, arr);
    display(adj);
    initialize_visited(visited);
    dfs(adj, visited, source);
}
```

#### Adjacency Matrix
```
void initialize_visited(int visited[]){
    for(int i=0; i<N; i++){
        visited[i] = 0;
    }
}

void dfs_traversal(node** graph, int visited[], int source){
    visited[source] = 1;
    printf("%d\n", source);

    for(node* i = graph[source]; i!=NULL; i=i->link){
        if(!visited[i->data]){
            dfs_traversal(graph, visited, i->data);
        }
    }
}

void dfs(node** graph, int visited[], int source){
    dfs_traversal(graph, visited, source);

    for(int i=0; i<N; i++){
        if(!visited[i]){
            dfs_traversal(graph, visited, i);
        }
    }
}

int main(){
    N = 5;
    int arr[][2] = {{1,2}, {1,3}, {2,1}, {2,4}, {3,1}, {3,4}, {4,2}, {4,3}};
    M = sizeof(arr)/sizeof(arr[0]);

    node* graph[N];
    int visited[N];
    int source = 1;

    adjacency_list(graph, arr);
    display(graph);
    initialize_visited(visited);
    dfs(graph, visited, source);
}
```

### Advantages
- Consumes less memory
- Finds a vertex which is at a large distance from the source in less time

### Disadvantages
- Can get stuck in an infinite loop if there is no secondary structure to check visited nodes
- Cannot find the shortest path between two nodes

### Applications
- Detecting cycles in a graph
- Finding a path in the network
- Topological sorting 
- Check whether a graph is strongly connected or not: a directed graph is said to be strongly connected if there exists a path between every pair of vertex