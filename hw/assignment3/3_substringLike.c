#include <stdio.h>
#include <string.h>

int main(){

    // input 
    int m, p, n;
    char seq[100000];
    char pattern[p];

    scanf("%d %d %d", &m, &p, &n);
    scanf("%s", seq);
    scanf("%s", pattern);
    
    // char seq[100] = "AAAGTGTGTCTGATT";
    // char pattern[100] = "GTAT";
    // int m = 15;
    // int p = 4;
    // int n = 2;
    

    int lenght = strlen(seq);
    int idx = 0, idx_pattern = 0, ref_idx;
    // printf("Text : %s\n", seq);
    // printf("Pattern : %s\n", pattern);
    while (idx < lenght){

        // printf("Start idx : %d | %c\n", idx, seq[idx]);

        ref_idx = idx;
        char result[p];
        int count = 0;

        for (int i = 0; i < p; i++){
        // for (int i = 0; i < p && i+idx < lenght; i++){
            if (i+idx >= lenght){
                printf("%c", seq[idx]);
                break;
            }

            if (seq[i+idx] == pattern[i]){
                // printf("Got pattern %c\n", seq[i+idx]);
                result[i] = seq[i+idx];
            }else{
                if(count < n){ 
                    result[i] = '?'; //
                    count += 1;
                }else{ 
                    // printf("====Normal char=== %c\n", seq[idx]);
                    printf("%c", seq[idx]);
                    break;
                }
            }

            if (p-1 == i){
                // printf("====result==== [%s] \n", result);
                printf("[%s]", result);
                idx += p - 1;
            }

        }

        idx++;
    }
}