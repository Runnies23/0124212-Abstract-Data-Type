#include <stdio.h>

int exist_digit(int numbers, int digit);

int main(){

    int n, k;

    scanf("%d", &n);
    scanf("%d", &k);

    int player[n];

    int counting = 1;

    for (int i = 0; i < n; i++){
        scanf("%d", &player[i]);
    }

    // printf("%d, %d \n", n,k);
    // for (int i = 0; i < n; i++){
    //     printf("%d ", player[i]);
    // }

    // printf("\n");

    int remain = n;
    int idx = 0;
    while (1 == 1)
    {

        if (player[idx] >= 0){
            // printf("id %d - %d : %d | %d \n", idx, player[idx], counting, k);

            if (counting % k == 0 || exist_digit(counting, k)){
                player[idx] -= 1;
                // printf("turn into -> %d\n", player[idx]);
            }
            if (player[idx] < 0){
                remain -= 1;
            }
            
            counting++;
        }

        if (remain == 1){
            break;
        }
        
        idx = (idx + 1) % n;
    }


    for (int i = 0; i < n; i++){
        if (player[i] != -1){
            printf("%d",i + 1);
        }
    }
    
    return 0;
}

int exist_digit(int numbers, int digit){

    while (numbers > 0){
        if (digit == numbers % 10){
            return 1;
        }

        numbers = numbers / 10;

    }

    return 0;
}