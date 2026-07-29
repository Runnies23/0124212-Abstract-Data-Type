// O(√n)
#include <stdio.h>
#include <math.h>

int is_prime(int a);

int main(){

    int input;
    
    scanf("%d", &input);

    printf("%d", is_prime(input));

    
    return 0;
}

int is_prime(int a){

    if (a < 3){
        return 1;
    }

    for (int i = 2; i <= sqrt(a); i++){
        if(a % i == 0){
            return 0;
        }
    }


    return 1;
}