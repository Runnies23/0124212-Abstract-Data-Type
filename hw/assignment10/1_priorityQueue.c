#include <stdio.h>
#include <stdlib.h>

typedef struct heap {
    int *data;
    int last_index;
} heap_t;


// ========================================
// Write your code here
// ...


//integrate max heap 
heap_t *init_heap(int size){

    int *data = (int*)malloc(sizeof(int) * size);

    for(int i = 0;i < size;i++){
        data[i] = 0;
    }

    heap_t *heap = (heap_t*)malloc(sizeof(heap_t)); 

    heap->data = data;
    heap->last_index = 0;

    return heap;
}

void insert(heap_t *h, int data){

    int idx = h->last_index;

    h->data[idx] = data;
    h->last_index += 1;

    //logic for adjusting heap
    int parent_idx = (idx - 1) / 2 ;
    
    //find the proper position ()
    while(h->data[parent_idx] < h->data[idx]){
        //switch
        int temp = h->data[idx];
        h->data[idx] = h->data[parent_idx];
        h->data[parent_idx] = temp;

        
        idx = parent_idx;
        parent_idx = (idx - 1) / 2;
    }
    

    return;
}

void delete_max(heap_t *h){

    h->last_index--;
    h->data[0] = h->data[h->last_index];

    //3 case 
    //when lower than left & right
    //when lower than left 
    //when lower than right

    int idx = 0;
    int left_child = (idx * 2) + 1;
    int right_child = (idx * 2) + 2;

    while((h->data[idx] < h->data[right_child] || h->data[idx] < h->data[left_child]) && (right_child < h->last_index || left_child < h->last_index) ){
        //break when no lower of child or null child 

        //case when less than both child 
        if (h->data[idx] < h->data[right_child] && h->data[idx] < h->data[left_child]){
            if (h->data[right_child] > h->data[left_child]){
                //switch
                int temp = h->data[idx];
                h->data[idx] = h->data[right_child];
                h->data[right_child] = temp;

                int idx = right_child; 
                int left_child = (idx * 2) + 1;
                int right_child = (idx * 2) + 2;

            }else{ //left more than right

                //switch
                int temp = h->data[idx];
                h->data[idx] = h->data[left_child];
                h->data[left_child] = temp;

                int idx = right_child; 
                int left_child = (idx * 2) + 1;
                int right_child = (idx * 2) + 2;

            }

        //when only less than left child
        }else if(h->data[left_child] > h->data[idx] && h->data[right_child] < h->data[idx]){
            int temp = h->data[idx];
            h->data[idx] = h->data[left_child];
            h->data[left_child] = temp;

            int idx = right_child; 
            int left_child = (idx * 2) + 1;
            int right_child = (idx * 2) + 2;
        }else{
            //when less than right child
            int temp = h->data[idx];
            h->data[idx] = h->data[right_child];
            h->data[right_child] = temp;

            int idx = right_child; 
            int left_child = (idx * 2) + 1;
            int right_child = (idx * 2) + 2;
        }


    }

    return;
}

int find_max(heap_t *h){
    // return first idx

    if(h->last_index > 0){
        return h->data[0];
    }
    

    return -1;
}

void update_key(heap_t *h, int old_key, int new_key){

    int idx;
    for(int i = 0; i < h->last_index; i++){
        if (h->data[i] == old_key){
            //logic for switching
            idx = i;
            h->data[i] = new_key;
            break;
        }
    }

    //switching
    //case when it's more than old_key => looking up 
    //case when it's less than old_key => looking down
    if(new_key > old_key){
        //reuse logic from insert
        //logic for adjusting heap
        int parent_idx = (idx - 1) / 2 ;
        
        //find the proper position
        while(h->data[parent_idx] < h->data[idx]){
            //switch
            int temp = h->data[idx];
            h->data[idx] = h->data[parent_idx];
            h->data[parent_idx] = temp;

            
            idx = parent_idx;
            parent_idx = (idx - 1) / 2;
        }

    }else{ 
        int left_child = (idx * 2) + 1;
        int right_child = (idx * 2) + 2;

        while((h->data[left_child] > h->data[idx] || h->data[left_child] > h->data[idx]) && 
        (left_child < h->last_index || right_child < h->last_index)){

            //case when less than both child 
            if (h->data[idx] < h->data[right_child] && h->data[idx] < h->data[left_child]){
                if (h->data[right_child] > h->data[left_child]){
                    //switch
                    int temp = h->data[idx];
                    h->data[idx] = h->data[right_child];
                    h->data[right_child] = temp;

                    int idx = right_child; 
                    int left_child = (idx * 2) + 1;
                    int right_child = (idx * 2) + 2;

                }else{ //left more than right

                    //switch
                    int temp = h->data[idx];
                    h->data[idx] = h->data[left_child];
                    h->data[left_child] = temp;

                    int idx = right_child; 
                    int left_child = (idx * 2) + 1;
                    int right_child = (idx * 2) + 2;

                }

            //when only less than left child
            }else if(h->data[left_child] > h->data[idx] && h->data[right_child] < h->data[idx]){
                int temp = h->data[idx];
                h->data[idx] = h->data[left_child];
                h->data[left_child] = temp;

                int idx = right_child; 
                int left_child = (idx * 2) + 1;
                int right_child = (idx * 2) + 2;
            }else{
                //when less than right child
                int temp = h->data[idx];
                h->data[idx] = h->data[right_child];
                h->data[right_child] = temp;

                int idx = right_child; 
                int left_child = (idx * 2) + 1;
                int right_child = (idx * 2) + 2;
            }
                
            
        }
    }



    return;
}

void bfs(heap_t *h){

    for(int i = 0;i < h->last_index;i++){
        printf("%d ", h->data[i]);
    }

    printf("\n");

    return;
}

// ========================================

int main(void) {
    heap_t *max_heap = NULL;
    int m, n, i;
    int command, data;
    int old_key, new_key;
    scanf("%d %d", &m, &n);
    max_heap = init_heap(m);
    for (i=0; i<n; i++) {
        scanf("%d", &command);
        switch (command) {
            case 1:
                scanf("%d", &data);
                insert(max_heap, data);
                break;
            case 2:
                delete_max(max_heap);
                break;
            case 3:
                printf("%d\n", find_max(max_heap));
                break;
            case 4:
                scanf("%d %d", &old_key, &new_key);
                update_key(max_heap, old_key,
                new_key);
                break;
            case 5:
                bfs(max_heap);
                break;
        }
    }
    return 0;
}