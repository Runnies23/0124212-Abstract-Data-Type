
#include <stdio.h>

int main(){

    // input 
    float weight, height;
    scanf("%f %f", &weight, &height);
    
    //compute 
    float bmi;

    if (height > 100){
        height = height / 100;
    }

    bmi = weight / (height * height);

    if (bmi >= 30){
        printf("BMI: %.4f and you are obese", bmi);
    }else if (bmi >= 25){
        printf("BMI: %.4f and you are overweight", bmi);
    }else if (bmi >= 18.6){
        printf("BMI: %.4f and you are healthy", bmi);
    }else{
        printf("BMI: %.4f and you are underweight", bmi);
    }

    
    return 0;
}