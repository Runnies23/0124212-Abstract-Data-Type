#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 1000

typedef struct {
    int data;
    int freq;
} Node;


int main(){
    int table_len = 0;
    Node *table[MAX_LEN];
    
    int input;
    int leave = 0;
    int most_freq = 1;
    while(1 == 1){
        leave = 0;
        scanf("%d", &input);
        if(input == -1){
            break;
        }
        // printf("%d \n", input);

        for (int i = 0; i < table_len; i++){
            Node *current = table[i];
            // printf("idx %d , data %d, freq %d\n", i, current->data, current->freq);
            if (current->data == input){
                current->freq += 1;
                if (current->freq > most_freq){
                    most_freq = current->freq;
                }
                // printf("Got it idx %d , data %d, freq %d \n", i, current->data, current->freq);
                leave = 1;
                break;
            }
        }

        if (leave){
            // for(int i = 0; i < table_len; i++){
            //     Node *current = table[i];
            //     printf("%d | %d \n", current->data, current->freq);
            // }
            continue;
        }
        // if not have in table -> create a new node
        Node *new_node = (Node *)malloc(sizeof (Node));
        new_node->data = input;
        new_node->freq = 1;
        table[table_len] = new_node;
        table_len++;
        // printf("Create a new Node, %d\n", new_node->data); 

        // for(int i = 0; i < table_len; i++){
        //     Node *current = table[i];
        //     printf("%d | %d \n", current->data, current->freq);
        // }
    }

    // for(int i = 0; i < table_len; i++){
    //     Node *current = table[i];
    //     printf("%d | %d \n", current->data, current->freq);
    // }

    // printf("most_freq : %d\n", most_freq);
    for (int i = most_freq; i > 0; i--){
        // printf("freq : %d\n", i);
        for (int j = 0; j < table_len; j++){
            Node *current = table[j];
            // printf("lets go : %d -> %d\n", current->data, current->freq);
            if (current->freq == i){
                // printf(" = %d -> %d times", current->data, current->freq);
                for (int k = 0; k < current->freq; k++){
                    printf("%d ", current->data);
                }
            }
        }
    }


}