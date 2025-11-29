/*Question 1: Create a structure called &quot;Student&quot; with members name, age, and total
marks. Write a C program to input data for two students, display their information, and
find the average of total marks.*/
#include <stdio.h>

struct Student {
    char name[50];
    int age;
    float total_marks;
};

int main() {
    struct Student st1, st2;
    printf("Enter details for student 1:\n");
    printf("Name: ");
    scanf("%s", st1.name);
    printf("Age: ");
    scanf("%d", &st1.age);
    printf("Total marks: ");
    scanf("%f", &st1.total_marks);
    printf("\nEnter details for student 2:\n");
    printf("Name: ");
    scanf("%s", st2.name);
    printf("Age: ");
    scanf("%d", &st2.age);
    printf("Total marks: ");
    scanf("%f", &st2.total_marks);
    printf("\nStudent Information:\n");
    printf("Student 1: %s, %d years, %.2f marks\n", st1.name, st1.age, st1.total_marks);
    printf("Student 2: %s, %d years, %.2f marks\n", st2.name, st2.age, st2.total_marks);
    float average = (st1.total_marks + st2.total_marks) / 2;
    printf("\nAverage of total marks: %.2f\n", average);
    
    return 0;
}
