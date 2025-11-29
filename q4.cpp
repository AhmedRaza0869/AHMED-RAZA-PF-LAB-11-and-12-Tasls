/*Question 4: Define a structure named &quot;Date&quot; with members day, month, and year. Write
a C program to input two dates and find the difference in days between them.*/
#include <stdio.h>
#include <stdlib.h>

struct Date {
    int day;
    int month;
    int year;
};

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year) {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    return days[month - 1];
}

int totalDays(struct Date d) {
    int total = d.day;
    
    for (int i = 1; i < d.month; i++) {
        total += daysInMonth(i, d.year);
    }
    
    for (int i = 1; i < d.year; i++) {
        total += isLeapYear(i) ? 366 : 365;
    }
    
    return total;
}

int dateDifference(struct Date d1, struct Date d2) {
    return abs(totalDays(d1) - totalDays(d2));
}

int main() {
    struct Date date1, date2;
    
    printf("Enter first date (dd mm yyyy): ");
    scanf("%d %d %d", &date1.day, &date1.month, &date1.year);
    
    printf("Enter second date (dd mm yyyy): ");
    scanf("%d %d %d", &date2.day, &date2.month, &date2.year);
    
    int diff = dateDifference(date1, date2);
    
    printf("Difference between dates: %d days\n", diff);
    
    return 0;
}
