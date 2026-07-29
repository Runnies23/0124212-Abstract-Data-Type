// O(nv)
// https://leetcode.com/problems/coin-change/description/

#include <stdio.h>

int min_func(int a,int b);

int main(){

    int n, v;
    
    scanf("%d", &n);
    
    int a[n];
    
    for (int i = 0; i < n;i++){
        scanf("%d", &a[i]);
    }

    scanf("%d", &v);
    int result[v + 1];
    for (int i = 0; i < v + 1; i++){
        result[i] = v + 1;
    }
    result[0] = 0;

    // printf("%d\n", n);
    // for (int i = 0; i < n;i++){
    //     printf("%d ", a[i]);
    // }
    // printf("\n%d\n", v);

    // ========================================================================
    // O(v * n)

    int most_n = 0;

    for (int i = 1; i < v + 1; i++){
        for (int j = 0; j < n; j++){
            // printf("i : %d | a : %d | diff : %d\n", i, a[j], i - a[j]);
            if (i - a[j] >= 0){
                if (1 + result[i - a[j]] < result[i]){
                    result[i] = 1 + result[i - a[j]];
                    most_n = i;
                }
            }
        }
    }
    // ========================================================================

    // for (int i = 0; i < v + 1; i++){
    //     printf("%d : %d \n", i,result[i]);
    // }

    // printf("%d, %d, %d\n", result[v], v + 1, most_n);

    // if (result[v] == v + 1){
    //     printf("0");
    // }
    // else{ 
    //     printf("%d", result[v]);
    // }

    if (result[v] != v + 1){
        printf("%d", result[v]);
    }else if (result[v] == v + 1 && most_n != 0){ 
        printf("%d", result[most_n]);
    }
    else{ 
        printf("0");
    }


    return 0;
}

int min_func(int a,int b){
    if (b > a){
        return a;
    }
    return b;
}
