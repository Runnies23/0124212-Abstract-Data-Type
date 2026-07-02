#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){

    // input 
    int  times;
    char seq[100000];
    scanf("%d", &times);
    scanf("%s", seq);
    
    //compute 
    int dis_x = 0, dis_y = 0;
    char direction = 'U';
    
    // printf("x : %d | y : %d\n", dis_x, dis_y);
    for (int i = 0; i < strlen(seq); i++){
        char command =  seq[i];
        if (command == 'F'){
            if (direction == 'U'){
                dis_x += 1;
            }else if(direction == 'D'){
                dis_x -= 1;
            }else if(direction == 'L'){
                dis_y -= 1;
            }else if(direction == 'R'){
                dis_y += 1;
            }
        }
        if (direction == 'U'){
            if (command == 'L'){
                direction = 'L';
            }else if(command == 'R'){
                direction = 'R';
            }
        }else if (direction == 'D'){
            if (command == 'L'){
                direction = 'R';
            }else if(command == 'R'){
                direction = 'L';
            }
        }else if (direction == 'L'){
            if (command == 'L'){
                direction = 'D';
            }else if(command == 'R'){
                direction = 'U';
            }
        }else if (direction == 'R'){
            if (command == 'L'){
                direction = 'U';
            }else if(command == 'R'){
                direction = 'D';
            }
        }
        
        // printf("x : %d | y : %d\n", dis_x, dis_y);
        
    }

    double distant = (dis_x * dis_x) + (dis_y * dis_y);
    printf("%.4lf", sqrt(distant));


    return 0;
}