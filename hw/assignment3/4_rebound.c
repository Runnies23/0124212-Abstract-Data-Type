// P:pass, T:timeout(<10 sec.), -:fail
// GRADER: PPP--P--

// need to experiment more test case 

#include <stdio.h>
#include <stdlib.h>

int RomanNumber(int a);

int main(){

    int m, n, x, y, direction_input;
    scanf("%d %d %d %d %d", &m, &n, &y, &x, &direction_input);

    // printf("%d %d %d %d %d\n", m, n, x, y, direction_input);
    // printf("End if x : %d | y: %d | direction : %d\n", x, y, direction_input);

    int **a = NULL;

    int current_x = x, current_y = y, direction = direction_input;
    int count = 0;

    // m = y , n = x
    a = (int **)malloc(sizeof(int *) * m);
    for (int i=0; i<m; i++) {
        a[i] = (int *)malloc(sizeof(int) * n);
        for (int j=0; j<n; j++)
            a[i][j] = 0;
    }

    while (1 == 1){
        printf("X : %d | Y : %d | Direction : %d \n", current_x, current_y, direction);

        a[current_y][current_x] = 1;

        switch (direction)
        {
        case 0:
            current_y --;
            break;
        case 1:
            current_x ++;
            current_y --;
            break;
        case 2:
            current_x ++;
            break;
        case 3:
            current_x ++;
            current_y ++;
            break;
        case 4:
            current_y ++;
            break;
        case 5:
            current_x --;
            current_y ++;
            break;
        case 6:
            current_x --;
            break;
        case 7:
            current_x --;
            current_y --;
            break;
    
        }

        if (current_x == 0 || 
            current_x == n-1 || 
            current_y == 0 || 
            current_y == m-1 ){
            // is boundary 
            if ((
                (current_x == 0 && current_y == 0) || 
                (current_x == 0 && current_y == m - 1) || 
                (current_x == n - 1 && current_y == 0) || 
                (current_x == n - 1 && current_y == m - 1) 
                ) && direction % 2 == 0){
                    
            }
            
            
            if (    
                // corner 
                (current_x == 0 && current_y == 0) || 
                (current_x == 0 && current_y == m-1) || 
                (current_x == n-1 && current_y == 0) || 
                (current_x == n-1 && current_y == m-1) || 
                // straight bounce
                (direction % 2 == 0)){

                direction = (direction + 4) % 8;

            }else{
                if (
                    //case of continue momentum Anti-clock wise 
                    (direction == 5 && current_x == 0) || 
                    (direction == 7 && current_y == 0) ||
                    (direction == 3 && current_y == m-1) || 
                    (direction == 1 && current_x == n-1)){

                    direction = (direction + 6) % 8; 

                }else{
                    //remain case == clock wise 
                    direction = (direction + 2) % 8; 
                }
            }
        }
        
        if (current_x == x && current_y == y && direction == direction_input){
            // if same position & direction == break the loop
            // printf("Break X : %d | Y : %d | Direction : %d\n", current_x, current_y, direction);
            break;
        }   

        count++;
        // k++;
    }

    //compute the result
    int total = 0;
    for (int i = 0;i < m;i++){
        for (int j = 0; j < n; j++){
            if (a[i][j] == 1){
                total += 1;
            }
        }
    }

    for (int i = 0;i < m;i++){
        free(a[i]);
    }
    free(a);
    
    // printf("count : %d | total : %d\n", count, total);
    printf("%d", total);

}
