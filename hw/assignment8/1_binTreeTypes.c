#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <week8.h>
// #include "week8.h"

#define MAX_LENGHT 1000

#ifndef __bin_tree__

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node_t;
typedef node_t tree_t;

#endif

// ========================
// Write your code here
// ** Note that the attach() function has
// been implemented already and included
// in the week8.h header
// ...


int is_full(tree_t *t){

    tree_t *current = t;

    //recursive 
    if (current == NULL){
        return 1;
    }
    if  ((current->left != NULL && current->right != NULL) || 
    (current->left == NULL && current->right == NULL)){
        return is_full(current->left) && is_full(current->right);
    }else{
        return 0;
    }

    return 0;

}

int is_perfect(tree_t *t){

    int most_depth = 0;
    int count_node = 0;
    tree_t *current = t;
    int current_level = 0;

    tree_t* queue[MAX_LENGHT];
    int level[MAX_LENGHT];
    int queue_start_idx = 0;
    int queue_end_idx = 0;

    queue[queue_end_idx] = t;
    level[queue_end_idx] = 0;
    queue_end_idx++;


    while(queue_start_idx < queue_end_idx){

        current = queue[queue_start_idx];
        current_level = level[queue_start_idx];
        queue_start_idx++;

        count_node ++;
        if (current_level > most_depth){
            most_depth = current_level;
        }

        if (current->left != NULL){

            //enqueue 
            queue[queue_end_idx] = current->left;
            level[queue_end_idx] = current_level + 1;
            queue_end_idx++;

        }
        
        if (current->right != NULL){

            //enqueue 
            queue[queue_end_idx] = current->right;
            level[queue_end_idx] = current_level + 1;
            queue_end_idx++;

        }
    }

    int expected = (1 << (most_depth + 1)) - 1;//2^(h+1) - 1.
    // printf("Expected : %d | Count : %d\n", expected ,count_node);
    if (count_node == expected){
        return 1; 
    } 

    return 0;

}

//case 4,5,6
int is_complete(tree_t *t){
    //using queue + BFS

    tree_t* queue[MAX_LENGHT];
    int level[MAX_LENGHT];
    int queue_start_idx = 0;
    int queue_end_idx = 0;

    int gap = 0;

    queue[queue_end_idx] = t;
    queue_end_idx++;


    while(queue_start_idx < queue_end_idx){

        tree_t *current = queue[queue_start_idx];
        queue_start_idx++;

        if (current == NULL){
            gap = 1;
        }else{
            if(gap){
                return 0;
            }

            
            queue[queue_end_idx] = current->left;
            queue_end_idx++;

            queue[queue_end_idx] = current->right;
            queue_end_idx++;

            }

        }

        
    return 1;
}

int is_degenerate(tree_t *t){

    tree_t *current = t; 

    if (current == NULL){
        return 1;
    }
    
    //when left and right is the same 
    if ((current->left != NULL && current->right != NULL) || (current->left == NULL && current->right == NULL)){
        return 0;
    }else{
        return 1;
    }
    return is_degenerate(current->left) && is_degenerate(current->right);

}

int is_skewed(tree_t *t){

    int is_left = 0;

    tree_t *current = t;
    
    if (current->left != NULL && current->right != NULL){
        return 0;
    }

    if (current->left != NULL){
        is_left = 1;
    }else{
        is_left = 0;
    }

    while(current != NULL){

        if (current->left != NULL && current->right != NULL){
            return 0;
        }
        if ((is_left && current->right != NULL) || (!is_left && current->left != NULL)){
            return 0;
        }


        if (is_left){
            current = current->left;
        }else{
            current = current->right;
        }
    }

    


    return 1;

}

// ========================

int main(void) {
tree_t *t = NULL;
int n, i;
int parent, child;
int branch; // 0 root, 1 left, 2 right
scanf("%d", &n);
for (i=0; i<n; i++) {
    scanf("%d %d %d", &parent, &child,
    &branch);
    t = attach(t, parent, child, branch);
}
printf("%d %d %d %d %d\n", is_full(t), is_perfect(t), is_complete(t), is_degenerate(t), is_skewed(t));
return 0;
}