#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;


// ============
// Write your code here
// ...
// ============

node_t *append(node_t *l, int value){

    node_t *node = (node_t *)malloc(sizeof (node_t));

    node->data = value;
    node->next = NULL;

    if (l == NULL){
        return node;
    }

    node_t *current = l;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = node;

    return l;
}

int get(node_t *l, int index){
    node_t *p = l;
    for (int i = 0; i < index; i++){
        p = p->next;
    }
    printf("%d\n", p->data);

    return 1;
}

int show(node_t *l){

    node_t *p = l;

    while(1 == 1){

        if (p == NULL){
            break;
        }
        printf("%d ", p->data);
        p = p->next;
        
    }
    printf("\n");

    return 1;
}

node_t *reverse(node_t *l){
    node_t *prev = NULL;
    node_t *current = l;
    

    while (current != NULL){
        node_t *next_node = current->next;
        current->next = prev;
        prev = current;
        current = next_node;
    }

    return prev;
}

node_t *cut(node_t *l, int idx_1, int idx_2){

    int count_idx = 0;

    node_t *start = l;


    while (start != NULL && count_idx < idx_1){
        start = start->next;
        count_idx++;
    }

    if (start == NULL){
        printf("NOthing");
        return start;
    }

    node_t *end = start;
    while(end != NULL && count_idx < idx_2){
        end = end->next;
        count_idx++;
    }

    end->next = NULL;


    return start;
}


int main(void) {
    node_t *startNode;
    int n,i;
    char command;
    startNode = NULL;
    scanf("%d", &n);
    int value, idx_1, idx_2;
    for (i=0; i<n; i++) {
        scanf(" %c", &command);
        switch (command) {
            case 'A':
                scanf("%d", &value);
                startNode = append(startNode, value);
                break;
            case 'G':
                scanf("%d", &value);
                get(startNode, value);
                break;
            case 'S':
                show(startNode);
                break;
            case 'R':
                startNode = reverse(startNode);
                break;
            case 'C':
                scanf("%d", &idx_1);
                scanf("%d", &idx_2);
                startNode = cut(startNode, idx_1, idx_2);
                break;
            default:
                break;
        }
    }
    return 0;
}
