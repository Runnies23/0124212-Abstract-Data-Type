
#include <stdio.h>

int main(){

    // input 
    unsigned int timestamp;
    scanf("%d", &timestamp);
    
    //compute 
    int day, hours, mins, secs;

    day = timestamp / 86400;
    timestamp = timestamp - (day * 86400);

    hours = timestamp / 3600;
    timestamp = timestamp - (hours * 3600);

    mins = timestamp / 60;
    secs = timestamp - (mins * 60);

    printf("%d %d %d %d", day, hours, mins, secs);
    return 0;
}