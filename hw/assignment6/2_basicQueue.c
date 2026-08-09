#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

typedef node_t queue_t;

// ===========================
// Write your code here
queue_t *enqueue(queue_t *s, int value){

    queue_t *current = s;
    queue_t *new_queue = (queue_t*)malloc(sizeof(new_queue));
    new_queue->data = value;
    new_queue->next = NULL;

    if (current == NULL){
        return new_queue;
    }

    while(current->next != NULL){
        current = current->next;
    }
    current->next = new_queue;


    return s;
}

queue_t *dequeue(queue_t *s){

    if (s == NULL){
        printf("Queue is empty.\n");
        return s;
    }

    queue_t *remove_node = s;
    queue_t *current_node = remove_node->next;
    printf("%d\n", remove_node->data);
    free(remove_node);

    return current_node;
}

void show(queue_t *s){

    if (s == NULL){
        printf("Queue is empty.\n");
        return;
    }

    queue_t *current = s;
    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");


    return;
}

void empty(queue_t *s){


    if (s == NULL){
        printf("Queue is empty.\n");
    }else{
        printf("Queue is not empty.\n");
    }


    return;
}

void size(queue_t *s){

    int size = 0;

    queue_t *current = s;

    while (current != NULL){
        current = current->next;
        size += 1;
    } 

    printf("%d\n" ,size);

    return;
}
// ===========================


int main(void) {
    queue_t *q = NULL;
    int n, i, command, value;
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d", &command);
        switch(command) {
            case 1:
                scanf("%d", &value);
                q = enqueue(q, value);
                break;
            case 2:
                q = dequeue(q);
                break;
            case 3:
                show(q);
                break;
            case 4:
                empty(q);
                break;
            case 5:
                size(q);
                break;
        }
    }
    return 0;
}