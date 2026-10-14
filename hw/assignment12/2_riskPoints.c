#include <stdio.h>
#include <stdlib.h>

#define MAXN 100000

typedef struct{
    int to;
    int next;
}Edge;

int head[MAXN];
Edge edges[200000];
int edgeCount = 0;

int tin[MAXN], low[MAXN], parent[MAXN];
int childCount[MAXN], isAP[MAXN];
int iter[MAXN], timer = 0;
int stack[MAXN];

void dfs(int root, int n) {
    int top = 0;
    stack[top++] = root;
    parent[root] = -1;
    tin[root] = low[root] = ++timer;
    iter[root] = head[root];

    while (top > 0) {
        int u = stack[top - 1];
        int e = iter[u];

        if (e != -1) {
            iter[u] = edges[e].next;
            int v = edges[e].to;

            if (v == parent[u])
                continue;

            if (tin[v] == 0) {
                parent[v] = u;
                childCount[u]++;
                tin[v] = low[v] = ++timer;
                iter[v] = head[v];
                stack[top++] = v;
            } else {
                if (tin[v] < low[u])
                    low[u] = tin[v];
            }
        } else {
            top--;

            if (parent[u] != -1) {
                int p = parent[u];

                if (low[u] < low[p])
                    low[p] = low[u];

                if (parent[p] != -1 && low[u] >= tin[p])
                    isAP[p] = 1;
            } else {
                if (childCount[u] >= 2)
                    isAP[u] = 1;
            }
        }
    }
}


int main(){ 
    int n, m;

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        head[i] = -1;
        parent[i] = -1;
    }


    int u, v;
    for(int i = 0; i < m;i++){
        scanf("%d %d", &u , &v);

        edges[edgeCount] = (Edge){v, head[u]};
        head[u] = edgeCount++;

        edges[edgeCount] = (Edge){u, head[v]};
        head[v] = edgeCount++;
    }
    for (int i = 0; i < n; i++) {
        if (tin[i] == 0)
            dfs(i, n);
    }

    int first = 1;
    for (int i = 0; i < n; i++) {
        if (isAP[i]) {
            if (!first)
                printf(" ");
            printf("%d", i);
            first = 0;
        }
    }


    return 1;
}