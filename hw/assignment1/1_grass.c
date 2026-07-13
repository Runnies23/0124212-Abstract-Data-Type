#include <stdio.h>

int main(){

    // input 
    double foot = 3.28084;
    double lenght, width;
    printf("length(m.): ");
    scanf("%lf", &lenght);

    printf("width(m.): ");
    scanf("%lf", &width);
    
    //compute 
    double result = ((lenght * foot) * (width * foot)) / 2;

    printf("Use %.5f seconds.", result);

    return 0;
}