//stack 
#include <stdio.h>

int main(){

    int n;

    scanf("%d", &n);

    int stack[n];

    for (int i = 0; i < n; i++){
        stack[i] = 0;
    }

    int stack_idx = 0;

    int parade[n];

    for (int i = 0; i < n; i++){
        scanf("%d", &parade[i]);
    }

    // printf("%d \n", n);
    // for (int i = 0; i < n; i++){
        // printf("%d ", parade[i]);
    // }
    // printf("\n");

    int should_be_number = 1;
    int idx = 0;
    int result = 0;

    while (should_be_number < n + 1 && idx < n){
        // printf("parade idx : %d | %d - stack : %d | recent %d | AIM : %d\n", idx, parade[idx], stack_idx, stack[stack_idx  - 1], should_be_number);
        
        
        if(stack_idx > 0 && parade[idx] > should_be_number && stack[stack_idx - 1] == should_be_number){

            stack[stack_idx  - 1] = 0;
            stack_idx -= 1;
            should_be_number += 1;
            continue;

        }else if (parade[idx] > should_be_number){
                
            stack[stack_idx] = parade[idx];
            stack_idx += 1;
            // printf("Stacking %d | %d\n", stack[stack_idx  - 1], stack_idx);
        }else if (parade[idx] == should_be_number){
            // printf("Match %d | %d\n", should_be_number, parade[idx]);
            should_be_number += 1;
        }
        idx += 1;

        // printf("Current stack\n");
    
        // for (int i = 0; i < n; i++){
            // printf("%d ", stack[i]);
        // }
        // printf("\n");
        

    }

    if (stack_idx != 0){
        result = 1;
    }
    for (int i = n; i > 0; i--){
        // printf("idx : %d | %d \n", stack[n-i], i);
        if (stack[n-i] != i && stack[n - i] != 0){
            result = 0;
        }
    }

    if (should_be_number == n + 1 && stack_idx == 0){
        result = 1;
    }

    printf("%d",result);



    
    return 0;
}
