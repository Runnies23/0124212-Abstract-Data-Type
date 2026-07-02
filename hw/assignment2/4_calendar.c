#include <stdio.h>

int printformat(int idx, int days);
int specialyears(int years);

const char *months[] = {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };

int month_days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

int main(){

    // input 
    int  years, month;
    printf("Enter year: ");
    scanf("%d", &years);

    printf("Enter month: ");
    scanf("%d", &month);

    
    int total_day = 0;
    for (int i = 1990;i < years;i++){
        if (specialyears(i)){
            // printf("total %d  + 366 \n", total_day);
            total_day += 366;
        }else{
            // printf("total %d  + 365 \n", total_day);
            total_day += 365;
        }
    }

    // printf("total on years : %d", total_day);

    for (int i = 0; i < month - 1; i++){
        if (i == 1 && specialyears(years)){
            // printf("Month : %d | 29\n", i);
            total_day += 29;
            continue;
        }
        // printf("Month : %d | %d\n", i, month_days[i]);
        total_day += month_days[i];
    }



    int remain = (total_day) % 7;
    int month_day;
    if (month == 1 && specialyears(years)){
        month_day = 29;
    }else{
        month_day = month_days[month - 1];
    }

    int start_idx = (remain + 1) % 7;
    int idx = 1;

    printf("====================\n");
    // printf("total : %d | %d\n", total_day, remain);

    
    // printf("month_day : %d\n", month_day);
    // printf("start : %d\n", start_idx);
    printf("%s %d\n", months[month - 1], years);
    printf("Sun Mon Tue Wed Thu Fri Sat\n");
    int day_position = 1;
    while (idx <= month_day){
        
        if (start_idx + 1 > day_position){
                printf("   ");
            }
        else{
            printf("%3d", idx);
            idx++;
        }

        if (day_position % 7 == 0 & day_position != 0){
            printf("\n");
        }else{
            printf(" ");
        }
        
        day_position++;
        
    }

    return 0;
}

// Function compute roman number
// int yearstodays(int a){


//     return a;
// }

// int printformat(int idx, int days){

// }

int specialyears(int years){

    if (years % 100 == 0 && years % 400 == 0){
        return 1;
    }else if(years % 100 != 0 && years % 4 == 0){
        return 1;
    }

    return 0;
}



// 1 2 3 4 5 6