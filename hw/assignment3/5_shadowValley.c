// P:pass, T:timeout(<10 sec.), -:fail
// GRADER: PPPPPTTTTT

// need to optimized run time
// runtime almost O (N ^ 3)
#include <stdio.h>
#include <string.h>
#include <math.h>


int parindrome(char *string, int lenght);

int main(){
    // input 
    int  times;
    char seq[100000];
    scanf("%d", &times);
    scanf("%s", seq);

    // printf("String : %s\n", seq);

    char longest_parindrome[100000];
    int longest_lenght = 1;

    longest_parindrome[0] = seq[0];
    longest_parindrome[1] = '\0'; //*****

    // printf("%d\n", parindrome(seq, strlen(seq)));

    // two pointer 
    int lenght = strlen(seq);
    int left = 0, right = 1;

    // O(N ^ 2) (for left , right)
    for (int left = 0; left < lenght; left++){

        for (int right = left + 1; right < lenght + 1; right++){

            int str_lenght = right - left;

            if (str_lenght < longest_lenght){
                continue;
            }

            char string[100000];
            memcpy(string, seq + left, str_lenght);

            // Add null terminator 
            string[str_lenght] = '\0'; //*****
            
            // printf("%s : %d\n", string, str_lenght);
            if (parindrome(string, str_lenght)){
                if (str_lenght > longest_lenght){
                    longest_lenght = str_lenght;
                    strcpy(longest_parindrome, string);
                }
            }

        }

    }
        


    printf("%s", longest_parindrome);

    return 0;
}

int parindrome(char *string, int lenght){
    
    // O ( M / 2 )  -> M = lenght 

    int odd = lenght / 2, isOdd = 0;

    if (lenght % 2 == 0){
        isOdd = 1;
    }

    for (int i = 0; i < lenght / 2; i++){

        if (string[i] != string[lenght - i - 1]){
            return 0;
            
        }

    }

    return 1;
}