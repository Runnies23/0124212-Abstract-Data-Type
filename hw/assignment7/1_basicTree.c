#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 100

// You can define your own (one or more)
// structures here. However, we eventually
// need the data type "tree_t".
// For example:
typedef struct node {
    
    int value;
    struct node *next_sibling;
    struct node *first_child;

} node_t;
typedef node_t tree_t; 

// Write your code here
// ...

tree_t *attach(tree_t *tree, int parent, int child){

    tree_t *new_node = (tree_t*)malloc(sizeof(tree_t));
    new_node->first_child = NULL;
    new_node->next_sibling = NULL;
    new_node->value = child;
    
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


tree_t *detach(tree_t *tree, int node){

    tree_t *order[MAX_LEN];
    int order_idx = 0;
    tree_t *parent_list[MAX_LEN];
    int parent_idx = 0;

    tree_t *pos = tree;
    tree_t *parent = tree;
    
    //while 

    if (pos->value == node){
        return NULL;
    }

    pos = pos->first_child;
    while (pos != NULL){
        tree_t *current = pos;


        if (current->value == node){
            //removing the node 
            //case when it's a first child 
            if (parent->first_child->value == node){
                parent->first_child = parent->first_child->next_sibling;
            }
            //case when on sibling 
            tree_t *previous = parent->first_child;
            tree_t *current = parent->first_child->next_sibling;
            while(current != NULL){    
                if (current->value == node){
                    previous->next_sibling = current->next_sibling;
                    break;
                }
                current = current->next_sibling;
            }

            return tree;
        }

        if (current->next_sibling != NULL){
            
            parent_list[parent_idx] = parent;
            parent_idx++;

            order[order_idx] = current->next_sibling;
            order_idx++;
            
            current = current->next_sibling;
        }

        if (pos->first_child != NULL){
            parent = pos;
            pos = pos->first_child;
        }else{ 
            if (order_idx > 0){
                order_idx--;
                pos = order[order_idx];

                parent_idx--;
                parent = parent_list[parent_idx];
            }else{
                pos = NULL;
            }
        }
    }
    

    return tree;
}

int search(tree_t *tree, int node){

    tree_t *pos = tree;
    tree_t *queue[MAX_LEN];
    int queue_start_idx = 0;
    int queue_end_idx = 1;
    
    while (queue_start_idx < queue_end_idx){
            tree_t *current = pos;
            while(current != NULL){

                // printf("%d ", current->value);
                if (current->value == node){
                    return 1;
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

    return 0;
}

int degree(tree_t *tree, int node){

    tree_t *pos = tree;
    tree_t *queue[MAX_LEN];
    int queue_start_idx = 0;
    int queue_end_idx = 1;
    
    while (queue_start_idx < queue_end_idx){
            tree_t *current = pos;
            while(current != NULL){

                if(current->value == node){
                    int count = 0;
                    tree_t *child = current->first_child;
                    while(child != NULL){
                        child = child->next_sibling;
                        count++;
                    }
                    return count;
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


    return 0;
}

int is_root(tree_t *tree, int node){
    
    if (tree->value == node){
        return 1;
    }

    return 0;
}

int is_leaf(tree_t *tree, int node){

    tree_t *pos = tree;
    tree_t *queue[MAX_LEN];
    int queue_start_idx = 0;
    int queue_end_idx = 1;
    
    while (queue_start_idx < queue_end_idx){
            tree_t *current = pos;
            while(current != NULL){

                if(current->value == node){
                    if (current->first_child == NULL){
                        return 1;
                    }
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

    return 0;

}

void siblings(tree_t *tree, int node){

    tree_t *pos = tree;
    tree_t *queue[MAX_LEN];
    int queue_start_idx = 0;
    int queue_end_idx = 1;
    
    while (queue_start_idx < queue_end_idx){
            tree_t *current = pos;
            while(current != NULL){

                if(current->value == node){

                    tree_t *running_val = pos;
                    while(running_val != NULL){
                        if (running_val->value != node){
                            printf("%d ", running_val->value);
                        }
                        running_val = running_val->next_sibling;
                    }

                    printf("\n");
                    return;
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

    return;
}

int depth(tree_t *tree, int node){ 

    tree_t *order[MAX_LEN];
    int order_idx = 0;
    int level[MAX_LEN];
    int space_bar = 0;

    tree_t *pos = tree;
    
    while (pos != NULL){

        tree_t *current = pos;
        if (current->value == node){
            return space_bar;
        }

        if (current->next_sibling != NULL){
            level[order_idx] = space_bar;
            order[order_idx] = current->next_sibling;
            order_idx += 1;
            
            current = current->next_sibling;
        }

        if (pos->first_child != NULL){
            pos = pos->first_child;
            space_bar += 1;
        }else{ 

            if (order_idx > 0){
            pos = order[order_idx-1];
            space_bar = level[order_idx-1];
            order_idx -= 1;
            }else{
                pos = NULL;
            }
            
        }
    }
    
    return 0;
}

void print_path(tree_t *tree, int start, int end){

    int path[MAX_LEN];
    int path_idx = 0;
    int start_idx = 0;

    int level[MAX_LEN];
    int space_bar = 0;

    tree_t *order[MAX_LEN];
    int order_idx = 0;

    tree_t *pos = tree;
    
    //while 
    while (pos != NULL){
        tree_t *current = pos;

        if (current->value == start){
            start_idx = path_idx;
        }
        if (current->value == end){
            for(int i = start_idx; i < path_idx; i++){
                printf("%d ", path[i]);
            }
            printf("%d\n", current->value);
        }

        //push another value into stack 
        path[path_idx] = current->value;
        path_idx++;

        if (current->next_sibling != NULL){
            level[order_idx] = space_bar;

            order[order_idx] = current->next_sibling;
            order_idx++;
            
            current = current->next_sibling;
        }

        if (pos->first_child != NULL){
            pos = pos->first_child;
            space_bar += 1;
        }else{ 
            if (order_idx > 0){
                pos = order[order_idx-1];
                space_bar = level[order_idx-1];
                path_idx = space_bar;
                order_idx--;
            }else{
                pos = NULL;
            }
        }
    }
    
    return ;

}

int path_length(tree_t *tree, int start, int end){

    int path[MAX_LEN];
    int path_idx = 0;
    int start_idx = 0;

    int level[MAX_LEN];
    int space_bar = 0;

    tree_t *order[MAX_LEN];
    int order_idx = 0;

    tree_t *pos = tree;
    
    //while 
    while (pos != NULL){
        tree_t *current = pos;

        if (current->value == start){
            start_idx = path_idx;
        }
        if (current->value == end){
            return path_idx - start_idx + 1;
        }

        //push another value into stack 
        path[path_idx] = current->value;
        path_idx++;

        if (current->next_sibling != NULL){
            level[order_idx] = space_bar;

            order[order_idx] = current->next_sibling;
            order_idx++;
            
            current = current->next_sibling;
        }

        if (pos->first_child != NULL){
            pos = pos->first_child;
            space_bar += 1;
        }else{ 
            if (order_idx > 0){
                pos = order[order_idx-1];
                space_bar = level[order_idx-1];
                path_idx = space_bar;
                order_idx--;
            }else{
                pos = NULL;
            }
        }
    }


    return 1;
}

void ancestor(tree_t *tree, int node){ 

    int path[MAX_LEN];
    int path_idx = 0;
    int start_idx = 0;

    int level[MAX_LEN];
    int space_bar = 0;

    tree_t *order[MAX_LEN];
    int order_idx = 0;

    tree_t *pos = tree;

    //init start with first 
    start_idx = 0;
    
    //while 
    while (pos != NULL){
        tree_t *current = pos;

        if (current->value == node){
            for(int i = start_idx; i < path_idx; i++){
                printf("%d ", path[i]);
            }
            printf("%d\n", current->value);
        }

        //push another value into stack 
        path[path_idx] = current->value;
        path_idx++;

        if (current->next_sibling != NULL){
            level[order_idx] = space_bar;

            order[order_idx] = current->next_sibling;
            order_idx++;
            
            current = current->next_sibling;
        }

        if (pos->first_child != NULL){
            pos = pos->first_child;
            space_bar += 1;
        }else{ 
            if (order_idx > 0){
                pos = order[order_idx-1];
                space_bar = level[order_idx-1];
                path_idx = space_bar;
                order_idx--;
            }else{
                pos = NULL;
            }
        }
    }

    return;
}

void descendant(tree_t *tree, int node){ 
    

    tree_t *pos = tree;
    tree_t *queue[MAX_LEN];
    int queue_start_idx = 0;
    int queue_end_idx = 1;
    
    while (queue_start_idx < queue_end_idx){
            tree_t *current = pos;
            while(current != NULL){
                
                if (current->value == node){
                    
                    tree_t *pos_local = current;
                    // printf("Start on : %d\n", pos_local->value);
                    tree_t *local_queue[MAX_LEN];
                    int local_queue_start_idx = 0;
                    int local_queue_end_idx = 1;
                    
                    printf("%d ", pos_local->value);
                    pos_local = pos_local->first_child;
                    
                    while (local_queue_start_idx < local_queue_end_idx){
                            tree_t *local_current = pos_local;
                            while(local_current != NULL){

                                printf("%d ", local_current->value);

                                if (local_current->first_child != NULL){
                                    //enlocal_queue if have a child 
                                        local_queue[local_queue_end_idx-1] = local_current->first_child;
                                        local_queue_end_idx += 1; 
                                }

                                local_current = local_current->next_sibling;
                            }

                            //delocal_queue when finding next local_queue 
                            pos_local = local_queue[local_queue_start_idx];
                            local_queue_start_idx += 1;
                        }

                    printf("\n");
                    return;

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

    return;
}

void bfs(tree_t *tree){

    tree_t *pos = tree;
    tree_t *queue[MAX_LEN];
    int queue_start_idx = 0;
    int queue_end_idx = 1;
    
    while (queue_start_idx < queue_end_idx){
            tree_t *current = pos;
            while(current != NULL){

                printf("%d ", current->value);

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

    return;
}



void dfs(tree_t *tree){

    tree_t *order[MAX_LEN];
    int order_idx = 0;

    tree_t *pos = tree;
    
    //while 
    while (pos != NULL){
        tree_t *current = pos;
        printf("%d ", current->value);

        if (current->next_sibling != NULL){
            
            order[order_idx] = current->next_sibling;
            order_idx++;
            
            current = current->next_sibling;
        }

        if (pos->first_child != NULL){
            pos = pos->first_child;
        }else{ 
            if (order_idx > 0){
                pos = order[order_idx-1];
                order_idx--;
            }else{
                pos = NULL;
            }
        }
    }
    
    return ;
}



void print_tree(tree_t *tree){

    tree_t *order[MAX_LEN];
    int order_idx = 0;
    int level[MAX_LEN];
    int space_bar = 0;

    tree_t *pos = tree;
    
    while (pos != NULL){

        for(int i = 0;i < space_bar; i++){
            printf("    ");
        }

        tree_t *current = pos;
        printf("%d\n", current->value);

        if (current->next_sibling != NULL){
            level[order_idx] = space_bar;
            order[order_idx] = current->next_sibling;
            order_idx += 1;
            
            current = current->next_sibling;
        }

        if (pos->first_child != NULL){
            pos = pos->first_child;
            space_bar += 1;
        }else{ 

            if (order_idx > 0){
            pos = order[order_idx-1];
            space_bar = level[order_idx-1];
            order_idx -= 1;
            }else{
                pos = NULL;
            }
            
        }
    }
    
    return ;
}


int main(void) {
    tree_t *t = NULL;
    int n, i, command;
    int parent, child, node, start, end;
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d", &command);
    switch(command) {
        case 1:
            scanf("%d %d", &parent, &child);
            t = attach(t, parent, child);
            break;
        case 2:
            scanf("%d", &node);
            t = detach(t, node);
            break;
        case 3:
            scanf("%d", &node);
            printf("%d\n", search(t, node));
            break;
        case 4:
            scanf("%d", &node);
            printf("%d\n", degree(t, node));
            break;
        case 5:
            scanf("%d", &node);
            printf("%d\n", is_root(t, node));
            break;
        case 6:
            scanf("%d", &node);
            printf("%d\n", is_leaf(t, node));
            break;
        case 7:
            scanf("%d", &node);
            siblings(t, node);
            break;
        case 8:
            scanf("%d", &node);
            printf("%d\n", depth(t, node));
            break;
        case 9:
            scanf("%d %d", &start, &end);
            print_path(t, start, end);
            break;
        case 10:
            scanf("%d %d", &start, &end);
            printf("%d\n",
                path_length(t, start, end));
            break;
        case 11:
            scanf("%d", &node);
            ancestor(t, node);
            break;
        case 12:
            scanf("%d", &node);
            descendant(t, node);
            break;
        case 13:
            bfs(t);
            break;
        case 14:
            dfs(t);
            break;
        case 15:
            print_tree(t);
            break;
        }
    }
    return 0;
}
 