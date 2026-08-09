#include <stdio.h>
#include <string.h>

int main(){

    char input[1000000];


    scanf("%s", input);

    // printf("%s", input);

    int str_len = strlen(input);

    int x_idx = -1;
    for (int i = 0;i < str_len; i++){
        if (input[i] == 'x'){
            x_idx = i;
            break;

        }
    }

    if (x_idx == -1){
        printf("0");
        return 0;
    }

    // printf("x_idx : %d | y_idx : %d\n", x_idx, str_len - x_idx);
    if (x_idx != str_len - x_idx - 2) {
        printf("0");
        return 0;
    }

    for (int j = x_idx; j < str_len; j++){
        if (input[j] != 'y'){
            
            // printf("%c : %d | %c : %d\n", input[j] ,j ,input[x_idx - (j - x_idx)], x_idx - (j - x_idx));

            int mirror = x_idx - (j-x_idx);

            if ((mirror < 0) || input[j] != input[mirror]){
                printf("0");
                return 0;
                break;
            }
        }

    }

    printf("1");

    
    return 1;
}