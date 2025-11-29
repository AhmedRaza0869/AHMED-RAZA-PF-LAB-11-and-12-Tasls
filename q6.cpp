/*Question 6: Write a recursive program in C that repeatedly displays the following menu
until the user chooses Exit:
1. Addition
2. Subtraction
3. Exit
Use recursion to re-display the menu after every operation (except exit).
Requirements:
? Function menu()
? Each operation takes 2 inputs
? After printing result ? call menu() again*/
#include <stdio.h>

void menu() {
    int choice, a, b;
    printf("\n=== Menu ===\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("Enter two numbers: ");
            scanf("%d %d", &a, &b);
            printf("Result: %d + %d = %d\n", a, b, a + b);
            menu();
            break;
        case 2:
            printf("Enter two numbers: ");
            scanf("%d %d", &a, &b);
            printf("Result: %d - %d = %d\n", a, b, a - b);
            menu();
            break;
        case 3:
            printf("Goodbye!\n");
            break;
        default:
            printf("Invalid choice! Try again.\n");
            menu();
            break;
    }
}

int main() {
    menu();
    return 0;
}
