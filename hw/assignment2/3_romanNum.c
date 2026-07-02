#include <stdio.h>

int RomanNumber(int a);

int main(){

    // input 
    int  times, number;
    scanf("%d", &times);

    for (int i = 0; i < times;i++){
        scanf("%d", &number);
        RomanNumber(number);
        printf("\n");
    }

    return 0;
}

// Function compute roman number
int RomanNumber(int a){
    // printf("\nget : %d\n", a);
    int remainning;
    if (a / 1000 > 0){
        printf("M");
        remainning = a - 1000;
        RomanNumber(remainning);
    }else if(a / 900 > 0){
        printf("CM");
        remainning = a - 900;
        RomanNumber(remainning);
    }else if(a / 500 > 0){
        printf("D");
        remainning = a - 500;
        RomanNumber(remainning);
    }else if(a / 400 > 0){
        printf("CD");
        remainning = a - 400;
        RomanNumber(remainning);
    }else if(a / 100 > 0){
        printf("C");
        remainning = a - 100;
        RomanNumber(remainning);
    }else if(a / 90 > 0){
        printf("XC");
        remainning = a - 90;
        RomanNumber(remainning);
    }else if(a / 60 > 0){
        printf("LX");
        remainning = a - 60;
        RomanNumber(remainning);
    }else if(a / 50 > 0){
        printf("L");
        remainning = a - 50;
        RomanNumber(remainning);
    }else if(a / 40 > 0){
        printf("XL");
        remainning = a - 40;
        RomanNumber(remainning);
    }else if(a / 10 > 0){
        printf("X");
        remainning = a - 10;
        RomanNumber(remainning);
    }else if(a / 9 > 0){
        printf("IX");
        remainning = a - 9;
        RomanNumber(remainning);
    }else if(a / 5 > 0){
        printf("V");
        remainning = a - 5;
        RomanNumber(remainning);
    }else if(a / 4 > 0){
        printf("IV");
        remainning = a - 4;
        RomanNumber(remainning);
    }else{
        for(int i = 0; i < a; i++){
            printf("I");
        }
        // printf("\n%d\n", a);
    }
    return a;
}
