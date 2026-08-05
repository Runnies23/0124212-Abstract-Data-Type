#include <stdio.h>

int main(){

    // int list[100000];
    int count = 0;
    
    int odds[1000000];
    int even[1000000];
    int odds_idx = 0, even_idx = 0;

    while (1 == 1){
        int input;
        scanf("%d", &input);

        if(input == -1){
            break;
        }
        // list[count] = input;
        // count++;

        if(input % 2 == 0){
            even[even_idx] = input;
            even_idx ++ ;
        }else{ 
            odds[odds_idx] = input;
            odds_idx ++ ;
        }

    }

    // for(int i = 0; i < count; i++){
    //     printf("%d ", list[i]);
    // }
    printf("\n");

    for(int i = 0; i < odds_idx; i++){
        printf("%d ", odds[i]);
    }
    for(int i = 0; i < even_idx; i++){
        printf("%d ", even[i]);
    }
    
    return 0;
}