#include <stdio.h>
#include <stdlib.h>


void findStats(int* list_of_int, double *avg, int *maxi,int *mini, int size) {


    double sum = list_of_int[0];
    *maxi = list_of_int[0];
    *mini = list_of_int[0];
    
    for (int i = 1; i < size; i++){
        
        int current_num = list_of_int[i];
        // printf("Current nums : %d Max : %d Min : %d \n", current_num, *maxi, *mini);

        if (current_num > *maxi){
            *maxi = current_num;
        }

        if (current_num < *mini){
            *mini = current_num;
        }

        sum += current_num;

    }   
    
    // printf("Sum : %lf\n", sum);

    *avg = sum / size;

}


int main(void) {
    int n, i, maxi, mini;
    double avg;
    int *nums;
    scanf("%d", &n);
    nums = (int *)malloc(sizeof(int) *n);
    for (i=0; i<n; i++)
    scanf("%d", nums+i);
    findStats(nums, &avg, &maxi, &mini, n);
    printf("%.2f %d %d", avg, maxi, mini);
    return 0;
}