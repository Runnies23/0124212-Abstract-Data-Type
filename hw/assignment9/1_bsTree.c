#include <stdio.h>
#include <stdlib.h>
typedef struct node {
int data;
struct node *left;
struct node *right;
} node_t;
typedef node_t bst_t;

#define MAX_LENGTH 100


// Write your code here
// ...
bst_t *insert(bst_t *t, int data){

    //init node
    if (t == NULL){
        bst_t *new_node = (bst_t*)malloc(sizeof(bst_t));
        new_node->data = data;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }

    if (t->data > data){
        t->left = insert(t->left, data);
    }else if(t->data < data){
        t->right = insert(t->right, data);
    }

    return t;

}

bst_t *delete(bst_t *t, int data){

    bst_t *previous = NULL;
    bst_t *current = t;

    while(current != NULL && current->data != data){
        // printf("%d ", current->data);

        previous = current;

        if(data > current->data){
            current = current->right;
        }else{
            current = current->left;
        }

    }

    if(current == NULL){
        return t;
    }

    //3case 
    //direct leaf node
    if(current->left == NULL && current->right == NULL){
        
        if(previous == NULL){
        free(current);
        return NULL;
    }

        if(previous->left == current){
            previous->left = NULL;
        }else{
            previous->right = NULL;
        }

        free(current);
    }else if(current->left != NULL && current->right != NULL){

        //have 2 child 
        bst_t *previous_new_node = current;
        bst_t *new_node = current->right;
        while(new_node->left != NULL){
            previous_new_node = new_node;
            new_node = new_node->left;
        }

        // replace current data with newnode data
        current->data = new_node->data;

       if(previous_new_node->left == new_node){
            previous_new_node->left = new_node->right;
        }else{
            previous_new_node->right = new_node->right;
        }
        free(new_node);


    }else{
        //have 1 child
        bst_t *child;

        if(current->left != NULL){
            child = current->left;
        }else{
            child = current->right;
        }



        if(previous == NULL){
            free(current);
            return child;
        }

        if(previous->left == current){
            previous->left = child;
        }else{
            previous->right = child;
        }

        free(current);
    }
    

    return t;
}

int find(bst_t *t, int data){

    bst_t *current = t;
    while(current != NULL){

        // printf("%d ", current->data);
        if (current->data == data){
            return 1;
        }

        if(data > current->data){
            current = current->right;
        }else{
            current = current->left;
        }

    }

    return 0;
}

int find_min(bst_t *t){

    bst_t *current = t;
    while(current->left != NULL){
        current = current->left;
    }


    return current->data;
}

int find_max(bst_t *t){

    bst_t *current = t;
    while(current->right != NULL){
        current = current->right;
    }


    return current->data;
}

int find_k_th(bst_t *t, int k){

    bst_t *stack[MAX_LENGTH];
    int stack_idx = 0;

    bst_t *current = t;
    int k_idx = 1;

    while (current != NULL || stack_idx > 0) {

        // leftest
        while (current != NULL) {
            stack[stack_idx] = current;
            stack_idx++;

            current = current->left;
        }

        stack_idx--;
        current = stack[stack_idx];

        if (k_idx == k) {
            return current->data;
        }

        k_idx++;

        current = current->right;
    }

    return 0;  // k is out of range
}


int main(void) {
    bst_t *t = NULL;
    int n, i;
    int command, data, k;
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d", &command);
        switch (command) {
            case 1:
                scanf("%d", &data);
                t = insert(t, data);
                break;
            case 2:
                scanf("%d", &data);
                t = delete(t, data);
                break;
            case 3:
                scanf("%d", &data);
                printf("%d\n", find(t, data));
                break;
            case 4:
                printf("%d\n", find_min(t));
                break;
            case 5:
                printf("%d\n", find_max(t));
                break;
            case 6:
                scanf("%d", &k);
                printf("%d\n", find_k_th(t, k));
                break;
        }
    }
    return 0;
}