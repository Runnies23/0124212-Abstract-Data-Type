
#include <stdio.h>

int main(){

    // input 
    long long m, n;
    scanf("%lld %lld", &m, &n);
    
    //compute 
    long long side1, side2, hypotenuse;

    side1 = (m * m) - (n * n);
    side2 = 2 * m * n;
    hypotenuse = (m * m) + (n * n);

    printf("%lld %lld %lld", side1, side2, hypotenuse);
    return 0;
}