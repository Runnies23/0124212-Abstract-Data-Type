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

    int car_long;
    char direction_input;
    char direction = 'L';

    furry *left_queue[n];
    furry *right_queue[n];

    int left_queue_idx = 0;
    int right_queue_idx = 0;

    int left_max = 0;
    int right_max = 0;
    
    for (int i = 0; i < n; i++){
        scanf("%d %c", &car_long, &direction_input);

        if (direction_input == 'L'){
            left_queue[left_max] = (furry*)malloc(sizeof(furry));
            left_queue[left_max]->car_long = car_long;
            left_queue[left_max]->side = direction_input;
            left_max += 1;
        }else{
            right_queue[right_max] = (furry*)malloc(sizeof(furry));
            right_queue[right_max]->car_long = car_long;
            right_queue[right_max]->side = direction_input;
            right_max += 1;
        }
    }

    // left_max -= 1;
    // right_max -= 1;

    MAX_LONG *= 100;

    // printf("%d \n", MAX_LONG);
    // printf("%d \n", n);
    // for (int i = 0; i < left_max; i++){
    //     furry *current = left_queue[i];
    //     printf("%5d | %c\n", current->car_long, current->side);
    // }

    //     for (int i = 0; i < right_max; i++){
    //     furry *current = right_queue[i];
    //     printf("%5d | %c\n", current->car_long, current->side);
    // }

    int count = 0;
    int total = 0;
    while (left_queue_idx < left_max || right_queue_idx < right_max){


        // printf("Direction - %c | left idx : %d | max : %d -- right idx %d | max : %d \n", direction,left_queue_idx, left_max, right_queue_idx, right_max);

        if (direction == 'L'){
            // if boat on left side

            if(left_queue_idx == left_max && right_queue_idx != right_max){
                // when no queue and go other side
                // printf("Going to Right\n");
                total = 0;
                direction = 'R';
                count += 1;
            }else if (left_queue[left_queue_idx]->car_long + total <= MAX_LONG){
            // get more car on the left to maximum 
                // printf("Left : add more car -> %d\n", left_queue[left_queue_idx]->car_long);

                total += left_queue[left_queue_idx]->car_long;
                left_queue_idx += 1;
            }else if(left_queue[left_queue_idx]->car_long + total > MAX_LONG){
                // when get max car
                // printf("Going to Right\n");
                total = 0;
                direction = 'R';
                count += 1;
            }
        }else{ 

            if(right_queue_idx == right_max && left_queue_idx != left_max){
                // when no queue and go other side
                // printf("Going to Left\n");
                total = 0;
                direction = 'L';
                count += 1;
            }else if (right_queue[right_queue_idx]->car_long + total <= MAX_LONG){
                // get more car on the right to maximum 
                // printf("Right : add more car -> %d\n", right_queue[right_queue_idx]->car_long);
                total += right_queue[right_queue_idx]->car_long;
                right_queue_idx += 1;
            }else if(right_queue[right_queue_idx]->car_long + total > MAX_LONG){
                // when get max car
                // printf("Going to Left\n");
                total = 0;
                direction = 'L';
                count += 1;
            }
        }

    }

    printf("%d", count + 1);
    
    return 0;
}