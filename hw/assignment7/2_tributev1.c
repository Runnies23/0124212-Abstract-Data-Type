#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 10000000

typedef struct node {
    
    int value;
    int is_pay; 
    struct node *next_sibling;
    struct node *first_child;

} node_t;
typedef node_t tree_t; 

tree_t *attach(tree_t *tree, int parent, int child, int boolean_val);
int dfs(tree_t *tree, int m);

int main(){

    tree_t *t = NULL;
    int n,m, boolean_val;
    int parent, child;

    int most_visit = 0;

    scanf("%d %d", &n, &m);

    t = attach(t, -1, 0, 0);

    for (int i = 0; i < n; i++){
        scanf("%d %d %d", &parent, &child, &boolean_val);
        t = attach(t, parent, child, boolean_val);
    }

    most_visit = dfs(t, m);
    printf("%d", most_visit);

    return 1;
}


tree_t *attach(tree_t *tree, int parent, int child, int boolean_val){

    tree_t *new_node = (tree_t*)malloc(sizeof(tree_t));
    new_node->first_child = NULL;
    new_node->next_sibling = NULL;
    new_node->value = child;
    new_node->is_pay = 0;
    if (boolean_val){
        new_node->is_pay = boolean_val;
    }
    
    //search parent 
    tree_t *pos = tree;
    tree_t *queue[MAX_LEN];
    int queue_start_idx = 0;
    int queue_end_idx = 1;

    //NULL tree => parent = -1
    if (parent == -1){
        tree = new_node;
        
    }else{
        //queue 
        while (queue_start_idx < queue_end_idx){
            tree_t *current = pos;
            while(current != NULL){

                if(current->value == parent){
                    if (current->first_child != NULL){
                        current = current->first_child;
                        while(current->next_sibling != NULL){
                            current = current->next_sibling;
                        }
                        current->next_sibling = new_node;
                    }else{
                        current->first_child = new_node;
                    }
                    return tree;
                }

                if (current->first_child != NULL){
                    //enqueue if have a child 
                        queue[queue_end_idx-1] = current->first_child;
                        queue_end_idx += 1; 
                }

                current = current->next_sibling;
            }

            //dequeue when finding next queue 
            pos = queue[queue_start_idx];
            queue_start_idx += 1;
        }
    }
    return tree;
}


int dfs(tree_t *tree, int m){

    int total_visit = 0;
    tree_t *order[MAX_LEN];
    int remain_m = m;
    int backtrack_m[MAX_LEN];
    int order_idx = 0;
    int force_backtracking = 0;

    tree_t *pos = tree;
    
    //while 
    while (pos != NULL){
        tree_t *current = pos;
        

        if (current->next_sibling != NULL){
            backtrack_m[order_idx] = remain_m; 
            order[order_idx] = current->next_sibling;
            order_idx++;
        }

        if (current->value != 0){

            // printf("%d | %d | %d\n", current->value, remain_m, current->is_pay);
            if (!current->is_pay){
                total_visit += 1;
            }else if(current->is_pay){
                if (remain_m > 0){
                    total_visit += 1;
                    remain_m -= 1;
                }else{
                    force_backtracking = 1;
                    // printf("Force back tracking\n");
                }
            }

        }

        
        if (pos->first_child != NULL && !force_backtracking){
            pos = pos->first_child;
        }else{ 
            if (order_idx > 0){
                order_idx--;
                pos = order[order_idx];
                remain_m = backtrack_m[order_idx];
                if (force_backtracking){
                    force_backtracking = 0;
                }

            }else{
                pos = NULL;
            }
        }
    }
    
    return total_visit;
}

