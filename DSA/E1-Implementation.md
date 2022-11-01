# IMPLEMENTATION OF GRAPH
---
## Using Adjacency Matrix
1. For a graph of `N` nodes, create a 2D array of dimensions `NxN` and initialize all values to 0
2. For each edge in the `arr[X][Y]`, update `adj[X][Y]` and `adj[Y][X]` to 1 which will denote that there is a edge between `X` and `Y`
3. If it is a directed graph, update only `adj[X][Y]` to 1. If it is a weighted graph, update `adj[X][Y]` to the weight of the edge

```
#include<stdio.h>

// N nodes and M edges
int N, M; 

void adjacency_matrix(int adj[][N], int arr[][2]){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            adj[i][j] = 0;
        }
    }

    for(int i=0; i<M; i++){
        int x = arr[i][0];
        int y = arr[i][1];

        adj[x][y] = 1;
        adj[y][x] = 1;
    }
}

void display(int adj[][N]){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

int main(){
    N = 5;
    int arr[][2] = {{1,2}, {2,3}, {4,2}, {1,4}};
    M = sizeof(arr)/sizeof(arr[0]);
    int adj[N][N];

    adjacency_matrix(adj, arr);
    display(adj);
}
```
The array `arr[][2]` contains the nodes which have edges between them

- Adding and removing edges
```
void add_edge(int adj[][N], int x, int y){
    if(x<N && x>=0 && y<N && y>=0){
        adj[x][y] = 1;
        adj[y][x] = 1;
    }
}

void remove_edge(int adj[][N], int x, int y){
    if(x<N && x>=0 && y<N && y>=0){
        adj[x][y] = 0;
        adj[y][x] = 0;
    }
}
```

## Using Adjacency List
```
// N vertices and M edges
int N, M;

typedef struct Node{
    int data;
    struct Node* link;
}node;

void insert_node(node** graph, int x, int y){
    // x is current node and y is the adjacent node
    node* current = graph[x];
    node* temp = (node*)malloc(sizeof(node));
    temp->data = y;
    temp->link = NULL;

    
    if(current == NULL){
        graph[x] = temp;
    }
    else{
        while(current->link != NULL){
            current = current->link;
        }
        current->link = temp;
    }
}

void adjacency_list(node** graph, int arr[][2]){
    for(int i=0; i<N; i++){
        graph[i] = NULL;
    }

    for(int i=0; i<M; i++){
        insert_node(graph, arr[i][0], arr[i][1]);
    }
}

void display(node** graph){
    node* current;

    for(int i=0; i<N; i++){
        current = graph[i];
        
        printf("Adjacent nodes of %d: ", i);
        while(current != NULL){
            printf("%d ", current->data);
            current = current->link;
        }

        printf("\n");
    }
}

int main(){
    N = 5;
    int arr[][2] = {{1,2}, {1,3}, {2,1}, {2,4}, {3,1}, {3,4}, {4,2}, {4,3}};
    M = sizeof(arr)/sizeof(arr[0]);

    node* graph[N];
    
    adjacency_list(graph, arr);
    display(graph);
}
```