
#include <stdio.h>
#include <math.h>

int perfectNumber(int a);
int perfectNumber_sqrt(int a);

int main(){

    // input 
    int numbers;
    int most = 1;
    scanf("%d", &numbers);
    
    //compute 
    for (int i = 0; i < numbers; i++){
        // if (perfectNumber(i)){
        if (perfectNumber_sqrt(i)){
            // printf("%d\n", i);
            if (i > most){
                most = i;
            }
        }
    
    }
    printf("%d", most);
    

    return 0;
}

int perfectNumber(int a){
    int sum = 0;
    for (int i = 1; i < a; i++){
        if(a % i == 0){
            sum += i;
        }
    }
    printf("A : %d | Sum : %d\n", a, sum);
    if (a == sum){
        return 1;
    }


    return 0;
}


int perfectNumber_sqrt(int a){
    int sum = 1;
    for (int i = 2; i < ceil(sqrt(a)); i++){
        if(a % i == 0){
            sum += i;
            sum += a / i;
        }
    }
    if (a == sum && a != 1){
        return 1;
    }


    return 0;
}