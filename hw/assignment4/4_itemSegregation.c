// O(n)

#include <stdio.h>

int main(){

    int n;
    
    scanf("%d", &n);
    
    int a[n];
    
    for (int i = 0; i < n;i++){
        scanf("%d", &a[i]);
    }


    // printf("%d\n", n);
    // for (int i = 0; i < n;i++){
    //     printf("%d ", a[i]);
    // }
    // printf("\n");

    int result[n];
    int count = 0;

    // ========================================================================
    for (int i = 0; i < n; i++){
        if (a[i] == -1 || a[i] == -2){
            result[count] = a[i];
            count++;
        }else{
            printf("%d ",a[i]);
        }
    }
    // ========================================================================

    for (int i = 0; i < count; i++){
        printf("%d ",result[i]);
    }

    return 0;
}
