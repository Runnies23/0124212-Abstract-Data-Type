#include <stdio.h>
#include <string.h>
#include <math.h>

int stirng_to_int(char a);

int main(){
    char printformat[30] = "0123456789ABCDEFGHIJKLMNOPQRST";

    int base, target;
    char input_seq[100000];
    
    scanf("%d %d", &base, &target);
    scanf("%s", input_seq);
    
    int length = strlen(input_seq);
    // printf("%s : length : %d\n", input_seq, length);
    
    
    int total = 0;
    for (int i = length - 1; i >= 0; i--){
        // printf("str : %c | value %d | step : %d * (%d ^ %d)\n", input_seq[i], stirng_to_int(input_seq[i]), stirng_to_int(input_seq[i]), base, length - (i + 1));
        // printf("res : %d\n", stirng_to_int(input_seq[i]) * (int)pow(base, length - (i + 1)));
        
        total += stirng_to_int(input_seq[i]) * (int)pow(base, length - (i + 1));
        
    }
    // printf("total - middle : %d\n", total);
    
    char result[100];
    int idx = 0;
    while (total / target != 0){
        // printf("product : %d | remain : %d\n", total / target, total % target);
        // printf("%c\n", printformat[total % target]);
        result[idx] = printformat[total % target];
        total = total / target;
        idx ++ ;
    }
    
    // printf("%c", printformat[total]);
    result[idx] = printformat[total % target];
    idx += 1;
    
    // printf("final result : %s\n", result);

    for (int i = idx-1; i >= 0; i--){
        printf("%c", result[i]);
    }

    

    return 0;
}


int stirng_to_int(char a){
    if (a >= '0' && a <= '9'){
        return (a - '0');
    }else if(a >= 'A' && a <= 'T'){
        return a - 'A' + 10;
    }

    return 0;
}