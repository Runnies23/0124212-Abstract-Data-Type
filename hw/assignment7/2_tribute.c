#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 10000000


typedef struct node {
    int value;
    int is_pay;

    struct node *first_child;
    struct node *next_sibling;
    struct node *last_child;
} node_t;

typedef node_t tree_t;

tree_t *attach(tree_t **nodes, tree_t *tree, int parent, int child, int boolean_val);
int dfs(tree_t *tree, int m);


int main(){

    int n, m;
    int parent, child, boolean_val;

    scanf("%d %d", &n, &m);

    tree_t **nodes = malloc((n + 1) * sizeof(tree_t *));

    if (nodes == NULL){
        return 1;
    }

    tree_t *t = NULL;

    
    t = attach(nodes, t, -1, 0, 0);

    
    for (int i = 0; i < n; i++){

        scanf("%d %d %d", &parent, &child, &boolean_val);

        t = attach(nodes, t, parent, child, boolean_val);
    }

    
    int most_visit = dfs(t, m);

    printf("%d\n", most_visit);

    
    for (int i = 0; i <= n; i++){
        free(nodes[i]);
    }

    free(nodes);

    return 0;
}


tree_t *attach(
    tree_t **nodes,
    tree_t *tree,
    int parent,
    int child,
    int boolean_val
){

    
    tree_t *new_node = malloc(sizeof(tree_t));

    if (new_node == NULL){
        return tree;
    }

    new_node->value = child;
    new_node->is_pay = boolean_val;

    new_node->first_child = NULL;
    new_node->next_sibling = NULL;
    new_node->last_child = NULL;

    nodes[child] = new_node;
    
    if (parent == -1){
        return new_node;
    }

    tree_t *parent_node = nodes[parent];


    
    if (parent_node->first_child == NULL){

        parent_node->first_child = new_node;
        parent_node->last_child = new_node;

    }

    
    else{

        parent_node->last_child->next_sibling = new_node;
        parent_node->last_child = new_node;

    }

    return tree;
}


int dfs(tree_t *tree, int m){

    int total_visit = 0;

    
    tree_t **order = malloc(sizeof(tree_t *) * MAX_LEN);

    int *backtrack_m = malloc(sizeof(int) * MAX_LEN);

    if (order == NULL || backtrack_m == NULL){
        free(order);
        free(backtrack_m);
        return 0;
    }

    int order_idx = 0;

    int remain_m = m;

    int force_backtracking = 0;

    tree_t *pos = tree;


    while (pos != NULL){

        tree_t *current = pos;

        if (current->next_sibling != NULL){

            backtrack_m[order_idx] = remain_m;

            order[order_idx] = current->next_sibling;

            order_idx++;
        }


        
        if (current->value != 0){

            
            if (!current->is_pay){

                total_visit++;
            }

            
            else{

                if (remain_m > 0){

                    total_visit++;

                    remain_m--;
                }

                else{

                    
                    force_backtracking = 1;
                }
            }
        }


        
        if (current->first_child != NULL && !force_backtracking){

            pos = current->first_child;
        }

        
        else{

            if (order_idx > 0){

                order_idx--;

                pos = order[order_idx];

                remain_m = backtrack_m[order_idx];

                if (force_backtracking){

                    force_backtracking = 0;
                }
            }

            else{

                pos = NULL;
            }
        }
    }


    free(order);
    free(backtrack_m);

    return total_visit;
}