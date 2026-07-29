// O( (log A * log B) ^ 2)
// https://leetcode.com/problems/tiling-a-rectangle-with-the-fewest-squares/solutions/

#include <stdio.h>
#include <math.h>

int most_2n(int a);

int main(){

    int a, b;
    
    scanf("%d %d", &a, &b);

    int widht[100];
    int height[100];
    int widht_idx = 0, height_idx = 0;

    // printf("width : %d | height : %d\n", most_2n(a), most_2n(b));
    
    int most_n = 0;

    // O(log A)
    while(a > 0){
        most_n = most_2n(a);
        a -= most_n;
        widht[widht_idx] = most_n;
        widht_idx++;
    }

    // O(log B)
    while(b > 0){
        most_n = most_2n(b);
        b -= most_n;
        height[height_idx] = most_n;
        height_idx++;
    }

    // for(int i = 0; i < widht_idx; i++){
    //     printf("%d ", widht[i]);
    // }
    // printf("\n");

    // for(int i = 0; i < height_idx; i++){
    //     printf("%d ", height[i]);
    // }
    // printf("\n");

    int total_n = 0;
    // O(log A)
    for (int i = 0; i < widht_idx; i++){
        // O(log B) 
        for (int j = 0; j < height_idx; j++){

            // printf("%d | %d\n",  widht[i], height[j]);

            if (widht[i] > height[j]){
                total_n += widht[i] / height[j];
            }else{
                total_n += height[j] / widht[i];
            }

        }
    }

    printf("%d", total_n);
    return 0;
}


int most_2n(int a){
    int result = 0;
    // printf("A : %d\n",a);
    while(1 == 1){
        // printf("= : %d | %d -> %f\n", a, result, pow(2, result));
        if (a < pow(2, result)){
            result -= 1;
            break;
        }
        result ++;
    }   
    return pow(2, result);
}