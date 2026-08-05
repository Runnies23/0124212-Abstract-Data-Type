#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#define MAX_lenght 1000000

int main(){

    char a[MAX_lenght],b[MAX_lenght];

    int result[MAX_lenght + 1];
    int result_idx = 0;

    
    scanf("%s", a);
    scanf("%s", b);
    
    int len_a = strlen(a), len_b = strlen(b);
    
    // printf("%s | %s \n", a,b);

    int idx = 0;
    int mins = len_a;
    if (len_a > len_b){
        mins = len_b;
    }

    int product;
    int add_on = 0;

    // for(int i = 0;i < len_a;i++){
        // printf("%c | idx %d \n", a[i], i);
    // }
    // printf("\n");
    // for(int i = 0;i < len_b;i++){
        // printf("%c | idx %d\n", b[i], i);
    // }
    // printf("\n");

    while (idx < mins){

        int product = 0;
        char part_a = a[len_a - idx - 1] - '0';
        char part_b = b[len_b - idx - 1] - '0';

        // printf("a : %d idx : %d \n", part_a, len_a - idx - 1 );
        // printf("b : %d idx : %d \n", part_b, len_b - idx - 1 );


        product = part_a + part_b;
        // printf("P : %d\n", product);
        if (add_on){
            product++;
        }
        if (product >= 10){
            add_on = 1;
            product -= 10;
        }else{ 
            add_on = 0;
        }
        result[idx] = product;

        idx++;
    }

    // printf("\nResult : ");
    // for (int i = idx - 1; i >= 0; i--){
    //     printf("%d", result[i]);
    // }
    // printf("\n");

    if (len_a > len_b){
        // printf("A \n");
        while(idx < len_a){
            char part_a = a[len_a - idx - 1] - '0';
            // printf("A : %d | %d \n", part_a,add_on);
            if (add_on){
                product = part_a + 1;
                if(product >= 10){
                    add_on = 1;
                    product -= 10;
                }else{
                    add_on = 0;
                }
                // printf("P - addon : %d \n", product);
                result[idx] = product;
            }else{ 
                // printf("P : %d \n", part_a);
                result[idx] = part_a;
                add_on = 0;
            }
            idx++;
        }
    }else if(len_b > len_a){
        // printf("B \n");
        while(idx < len_b){
            char part_b = b[len_b - idx - 1] - '0';
            // printf("B : %d | %d \n", part_b, add_on);
            if (add_on){
                product = part_b + 1;
                if(product >= 10){
                    add_on = 1;
                    product -= 10;
                }else{
                    add_on = 0;
                }
                // printf("P - addon : %d \n", product);
                result[idx] = product;
            }else{ 
                // printf("P : %d \n", part_b);
                result[idx] = part_b;
                add_on = 0;
            }
            idx++;
        }

    }
    
    if(add_on){
        result[idx] = 1;
        idx ++;

    }

    // printf("\n");

    for (int i = idx - 1; i >= 0; i--){
        printf("%d", result[i]);
    }

    // printf("\n");

    // for (int i = MAX_lenght; i >= 0; i--){
        // printf("%d", result[i]);
    // }
    
    return 0;
}