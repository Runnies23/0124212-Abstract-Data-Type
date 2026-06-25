
#include <stdio.h>

int main(){

    // input 
    int x, y;
    char ops;
    scanf("%d %c %d", &x, &ops, &y);
    
    //compute 

    if (ops == '+'){
        printf("%d", x + y);
    }else if (ops == '-'){
        printf("%d", x - y);
    }else if (ops == '*'){
        printf("%d", x * y);
    }else if (ops == '%'){
        printf("%d", x / y);
    }else if (ops == '/'){
    
        float y_float = (float)y;
        printf("%.2f", x / y_float);
    }else{
        printf("Unknown Operator");
    }

    
    return 0;
}