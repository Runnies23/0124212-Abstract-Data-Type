#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;


typedef node_t stack_t;

// Write your code here
// ...

stack_t *push(stack_t *s, int value){ 
    
    if (s == NULL){
        s = (stack_t*)malloc(sizeof(stack_t));
        s->next = NULL;
        s->data = value;
        return s;
    }
    
    stack_t *current = s;
    // while (current->next != NULL){
    //     current = current->next;
    // }

    stack_t *newnode = (stack_t*)malloc(sizeof(stack_t));
    newnode->data = value;
    newnode->next = s;

    return newnode;
}

void top(stack_t *s){
    stack_t *current = s;
    if (current != NULL){
        printf("%d\n",current->data);
    }else{
        printf("Stack is empty.\n");
    }

    return ;
}

stack_t *pop(stack_t *s){
    stack_t *current = s;
    
    if (current != NULL){
        stack_t *return_node = current->next;
        free(current);
        return return_node;
    }

    return s;
}

void empty(stack_t *s){

    stack_t *current = s;
    if (current == NULL){
        printf("Stack is empty.\n");
    }else{ 
        printf("Stack is not empty.\n");
    }

    return;
}

void size(stack_t *s){

    int size = 0;

    stack_t *current = s;
    while (current != NULL){
        current = current->next;
        size += 1;
    }

    printf("%d\n", size);


    return ;
}



int main(void) {
    stack_t *s = NULL;
    int n, i, command, value;
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d", &command);
        switch(command) {
            case 1:
                scanf("%d", &value);
                s = push(s, value);
                break;
            case 2:
                top(s);
                break;
            case 3:
                s = pop(s);
                break;
            case 4:
                empty(s);
                break;
            case 5:
                size(s);
                break;
        }
    }
    return 0;
}