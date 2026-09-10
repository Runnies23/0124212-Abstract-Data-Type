#include <stdio.h>
#include <stdlib.h>
#include <week8.h>
// #include "week8.h"
#define MAX_LENGHT 10
#ifndef __bin_tree__
typedef struct node {
int data;
struct node *left;
struct node *right;
} node_t;
typedef node_t tree_t;
#endif


// Write your code here
// ** Note that the attach() function has
// been implemented already and included
// in the week8.h header
// ...

void printVerticalSum(tree_t *t){
    int left_idx = 0;
    int right_idx = 0;
    int arr[MAX_LENGHT];

    for(int i = 0; i < MAX_LENGHT; i++){
        arr[i] = 0;
    }

    tree_t *queue[MAX_LENGHT];
    int position[MAX_LENGHT];
    int queue_start_idx = 0;
    int queue_end_idx = 0;

    queue[queue_end_idx] = t;
    position[queue_end_idx] = 0;
    queue_end_idx++;

    while(queue_start_idx < queue_end_idx){

        tree_t *current = queue[queue_start_idx];
        int current_position = position[queue_start_idx];
        queue_start_idx++;

        if (current_position > right_idx){
            right_idx = current_position;
        }
        if (current_position < left_idx){
            left_idx = current_position;
        }

        if(current_position < 0){
            arr[MAX_LENGHT+current_position] += current->data;
        }else{
            arr[current_position] += current->data;
        }

        if (current->left != NULL){

            //enqueue 
            queue[queue_end_idx] = current->left;
            position[queue_end_idx] = current_position + -1;
            queue_end_idx++;

        }
        
        if (current->right != NULL){

            //enqueue 
            queue[queue_end_idx] = current->right;
            position[queue_end_idx] = current_position + 1;
            queue_end_idx++;

        }

    }

    // printf("left : %d | right : %d\n",left_idx, right_idx);
    for(int i = MAX_LENGHT+left_idx; i < MAX_LENGHT;i++){
        printf("%d ", arr[i]);
    }
    for(int i = 0; i <= right_idx; i++){
        printf("%d ", arr[i]);
    }

    return;
}


int main(void) {
    tree_t *t = NULL;
    int n, i;
    int parent, child;
    int branch; // 0 root, 1 left, 2 right
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d %d %d", &parent, &child,&branch);
        t = attach(t, parent, child, branch);
    }
    printVerticalSum(t);
    return 0;
}