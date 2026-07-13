#include <stdio.h>
#include <string.h>
#include <math.h>

// optimized run time

int parindrome(char *string, int lenght);

int main(){
    // input 
    int  times;
    char seq[100000];
    scanf("%d", &times);
    scanf("%s", seq);

    // printf("String : %s\n", seq);

    int longest_start_idx = 0;
    int longest_lenght = 1;

    int seq_lenght = strlen(seq);
    int middle = 0;
    int expand = 0;
    int left = 0, right = 0; 
    while (middle < seq_lenght){

        // printf("==== Middle start ==== M : %d | L : %d | R : %d\n", middle, left, right);

        left = middle - 1;
        right = middle + 1;
        while (left < right && right < seq_lenght && left >= 0){
            // printf("==== Middle ==== M : %d | L : %d | R : %d\n", middle, left, right);

            if (seq[left] == seq[right]){ // odds case 
                // printf("=== left == right ===\n");
                if (right - left > longest_lenght){
        
                    longest_lenght = right - left + 1;
                    longest_start_idx = left;
                    // printf("idx_start : %d | lenght : %d\n", longest_start_idx, longest_lenght);
                }


                left = left - 1 ;
                right = right + 1;
            }else if(seq[middle] == seq[right] && seq[left] != seq[right] && right - left == 2){ // even charactor case

                // printf("=== middle == right ===\n");
                if (right - left > longest_lenght){
                    longest_lenght =  right - middle + 1;
                    longest_start_idx = middle;

                    // printf("idx_start : %d | lenght : %d\n", longest_start_idx, longest_lenght);
                }

                left = left;
                right = right + 1;

                
            }else{
                break;;
            }
        }

        middle += 1;

    }
    
    // printf("start idx : %d | lenght : %d\n", longest_start_idx, longest_lenght);
    for (int i = 0; i < longest_lenght; i++){
        printf("%c", seq[longest_start_idx + i]);
    }

    return 0;
}
