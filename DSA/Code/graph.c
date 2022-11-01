#include<stdio.h>
#include<stdlib.h>

// ADJACENCY MATRIX FOR UNDIRECTED GRAPH

// N vertices and M edges
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

void check_connected(int visited[]){
    int disconnected = 0;
    for(int i=0; i<N; i++){
        if(!visited[i]){    
            disconnected = 1;
            break;
        }
    }

    if(disconnected){
        printf("Graph is not connected \n");
    }
    else{
        printf("Graph is connected \n");
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


// ADJACENCY LIST FOR DIRECTED GRAPH

// N vertices and M edges
/*
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
*/