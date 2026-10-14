#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_QUEUE 1000

typedef struct Node
{
    int key;
    int weight;
    struct Node *next;
}node_t;


long long dijkstra(node_t **adj, int n, int s, int t) {
    long long *dist = malloc(n * sizeof(long long));
    int *visited = calloc(n, sizeof(int));

    if (dist == NULL || visited == NULL) {
        free(dist);
        free(visited);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++) {
        dist[i] = LLONG_MAX;
    }

    dist[s] = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;

        for (int j = 0; j < n; j++) {
            if (!visited[j] &&
                dist[j] != LLONG_MAX &&
                (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }

        if (u == -1) {
            break;
        }

        if (u == t) {
            break;
        }

        visited[u] = 1;

        node_t *current = adj[u];

        while (current != NULL) {
            int v = current->key;
            int w = current->weight;

            if (!visited[v] &&
                dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }

            current = current->next;
        }
    }

    long long answer = dist[t];

    free(dist);
    free(visited);

    return answer == LLONG_MAX ? -1 : answer;
}


int main(){ 
    int n, m, p;

    scanf("%d %d %d", &n, &m, &p);
    node_t **adjacencyList = (node_t**)malloc(sizeof(node_t) * n);
    int adjacencyIdx[n];
    for (int i = 0; i < n; i++){
        adjacencyIdx[i] = 0;
    }

    int u, v, w;
    for(int i = 0; i < m;i++){
        scanf("%d %d %d", &u , &v, &w);
        //logic of adding a vertex and node
        int idx = adjacencyIdx[n];
        
        //create a new node 
        node_t *newNode = (node_t*)malloc(sizeof(node_t));
        newNode->key = v;
        newNode->weight = w;
        newNode->next = adjacencyList[u];
        adjacencyList[u] = newNode;

        node_t *newNode_2 = (node_t*)malloc(sizeof(node_t));
        newNode_2->key = u;
        newNode_2->weight = w;
        newNode_2->next = adjacencyList[v];
        adjacencyList[v] = newNode_2;
    }
    // adacency matrix

    //debug 
    // for (int i = 0; i < n; i++){
    //     printf("%d ===> \n", i);
    //     node_t *current_node = adjacencyList[i];

    //     while(current_node != NULL){
    //         printf("%d, %d\n", current_node->key, current_node->weight);
    //         current_node = current_node->next;
    //     }
    //     printf("====\n");
    // }

    int s, t;
    for(int i = 0; i < p;i++){
        scanf("%d %d", &s, &t);
        
        //function of shortest 
        // node_t *current_node = adjacencyList[i];
        
        //traversal
        printf("%lld\n", dijkstra(adjacencyList, n, s, t));

        //return value if not return -1


    }



    return 1;
}