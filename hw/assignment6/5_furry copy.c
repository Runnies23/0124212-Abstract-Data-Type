// PPP-----
// queue
#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int car_long;
    char side;
}furry;


int main(){

    int MAX_LONG, n;

    scanf("%d", &MAX_LONG);
    scanf("%d", &n);

    furry *input[n];

    int car_long;
    char direction_input;
    char direction = 'L';

    furry *left_queue[n];
    furry *right_queue[n];

    int left_queue_idx = 0;
    int right_queue_idx = 0;
    
    for (int i = 0; i < n; i++){
        scanf("%d %c", &car_long, &direction_input);

        input[i] = (furry*)malloc(sizeof(furry));
        input[i]->car_long = car_long;
        input[i]->side = direction_input;
    }

    input[n] = (furry*)malloc(sizeof(furry));
    input[n]->car_long = 0;
    input[n]->side = 'U';

    MAX_LONG *= 100;

    // printf("%d \n", MAX_LONG);
    // printf("%d \n", n);
    for (int i = 0; i < n; i++){
        furry *current = input[i];
        // printf("%5d | %c\n", current->car_long, current->side);
    }

    int count = 0;
    int idx = 0;
    int total = 0;
    while (idx <= n){

        // printf("idx : %d - %d | Now : %c \n", idx, input[idx]->car_long, direction);

        // when boat on other size
        if (input[idx]->side != direction){
            // printf("Change Direction + 1\n");
            direction = input[idx]->side;
            count += 1;
            total += input[idx]->car_long;
        }else{
            // when boat on same side 
            // cal long
            if (total + input[idx]->car_long <= MAX_LONG){
                // printf("Add more car long : %d -> ", input[idx]->car_long);
                total += input[idx]->car_long;
                // printf("%d\n", total);
            }else{
                // printf("Service. + 1\n");
                total = 0;
                count += 1;
                if (direction == 'R'){
                    direction = 'L';
                }else{
                    direction = 'R';
                }

                continue;
            }
        }


        idx += 1;
    }

    printf("%d", count);
    
    return 0;
}


// base both side all fit 