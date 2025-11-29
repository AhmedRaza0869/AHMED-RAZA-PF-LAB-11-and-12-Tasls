/*Question 2: Define a structure named Time with members hours, minutes, and seconds.
Write a C program to input two times, add them, and display the result in proper time
format.?*/
#include <stdio.h>

struct Time {
    int hrs;
    int mins;
    int secs;
};

struct Time addTimes(struct Time t1, struct Time t2) {
    struct Time result;
    result.secs = t1.secs + t2.secs;
    result.mins = t1.mins + t2.mins;
    result.hrs = t1.hrs + t2.hrs;
    
    if (result.secs >= 60) {
        result.mins += result.secs / 60;
        result.secs %= 60;
    }
    
    if (result.mins >= 60) {
        result.hrs += result.mins / 60;
        result.mins %= 60;
    }
    
    return result;
}

int main() {
    struct Time time1, time2, sum;
    
    printf("Enter first time (hh mm ss): ");
    scanf("%d %d %d", &time1.hrs, &time1.mins, &time1.secs);
    
    printf("Enter second time (hh mm ss): ");
    scanf("%d %d %d", &time2.hrs, &time2.mins, &time2.secs);
    
    sum = addTimes(time1, time2);
    
    printf("\nTime 1: %02d:%02d:%02d\n", time1.hrs, time1.mins, time1.secs);
    printf("Time 2: %02d:%02d:%02d\n", time2.hrs, time2.mins, time2.secs);
    printf("Sum: %02d:%02d:%02d\n", sum.hrs, sum.mins, sum.secs);
    
    return 0;
}

