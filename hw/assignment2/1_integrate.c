
#include <stdio.h>
#include <math.h>

double function(double x, double A, double B);

int main(){

    // input 
    double a, b, A, B;
    int n;
    
    scanf("%lf %lf %lf %lf %d", &a, &b, &A, &B, &n);
    // printf("%lf %lf %lf %lf %lf\n" , a, b, A, B, n);
    
    //compute 
    double h = (b - a) / n;
    double area = 0.0;
    for (int i = 0; i < n; i++){
        double left = a + i * h;
        double right = a + (i + 1) * h;
        // printf("start : %lf\n", start);
        area += (function(left, A, B) + function(right, A, B)) / 2.0 * h;
    }

    printf("%.5lf\n", area);
    
    return 0;
}

double function(double x, double A, double B){
    return A * sin((3.14159265359 * x) / B);
}