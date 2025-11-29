/*Question 3: Create a structure named Book to store book details like title, author, and
price. Write a C program to input details for three books, find the most expensive and
the lowest priced books, and display their information.*/
#include <stdio.h>
#include <string.h>

struct Book {
    char title[100];
    char author[50];
    float price;
};

int main() {
    struct Book books[3];
    for (int i = 0; i < 3; i++) {
        printf("Enter details for book %d:\n", i + 1);
        printf("Title: ");
        scanf(" %[^\n]", books[i].title);
        printf("Author: ");
        scanf(" %[^\n]", books[i].author);
        printf("Price: ");
        scanf("%f", &books[i].price);
        printf("\n");
    }
    
    int max = 0, min = 0;
    
    for (int i = 1; i < 3; i++) {
        if (books[i].price > books[max].price) {
            max = i;
        }
        if (books[i].price < books[min].price) {
            min = i;
        }
    }
    
    printf("Most Expensive Book:\n");
    printf("Title: %s\n", books[max].title);
    printf("Author: %s\n", books[max].author);
    printf("Price: $%.2f\n", books[max].price);
    printf("\nLowest Priced Book:\n");
    printf("Title: %s\n", books[min].title);
    printf("Author: %s\n", books[min].author);
    printf("Price: $%.2f\n", books[min].price);
    
    return 0;
}
