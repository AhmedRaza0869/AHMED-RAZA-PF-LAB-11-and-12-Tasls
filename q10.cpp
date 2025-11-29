#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pub {
    char pub[30];
    int yr;
};

struct Avail {
    int avail;
    int total;
};

struct Book {
    int id;
    char title[50];
    char author[30];
    struct Pub pub;
    struct Avail avail;
};

void inputBook(struct Book *b) {
    printf("Enter Book ID: ");
    scanf("%d", &b->id);
    printf("Enter Title: ");
    scanf(" %[^\n]", b->title);
    printf("Enter Author: ");
    scanf(" %[^\n]", b->author);
    printf("Enter Publisher: ");
    scanf(" %[^\n]", b->pub.pub);
    printf("Enter Year: ");
    scanf("%d", &b->pub.yr);
    printf("Enter Total Copies: ");
    scanf("%d", &b->avail.total);
    b->avail.avail = b->avail.total;
}

void showBook(struct Book *b) {
    printf("\n=== Book Info ===\n");
    printf("ID: %d\n", b->id);
    printf("Title: %s\n", b->title);
    printf("Author: %s\n", b->author);
    printf("Publisher: %s\n", b->pub.pub);
    printf("Year: %d\n", b->pub.yr);
    printf("Available: %d/%d\n", b->avail.avail, b->avail.total);
}

void updateCopies(struct Book *b, int new_copies) {
    if (new_copies >= 0 && new_copies <= b->avail.total) {
        b->avail.avail = new_copies;
        printf("Updated!\n");
    } else {
        printf("Error! Copies must be 0-%d\n", b->avail.total);
    }
}

struct Book* findBook(struct Book *books, int n, int id) {
    for (int i = 0; i < n; i++) {
        if (books[i].id == id) {
            return &books[i];
        }
    }
    return NULL;
}

int main() {
    int n;
    printf("How many books? ");
    scanf("%d", &n);
    
    struct Book *books = (struct Book*)malloc(n * sizeof(struct Book));
    
    if (books == NULL) {
        printf("Memory error!\n");
        return 1;
    }
    
    for (int i = 0; i < n; i++) {
        printf("\nBook %d:\n", i + 1);
        inputBook(&books[i]);
    }
    
    printf("\n=== All Books ===\n");
    for (int i = 0; i < n; i++) {
        showBook(&books[i]);
    }
    
    int ch;
    do {
        printf("\n=== Menu ===\n");
        printf("1. Find & Update\n");
        printf("2. Show All\n");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1: {
                int sid, nc;
                printf("Enter Book ID: ");
                scanf("%d", &sid);
                
                struct Book *found = findBook(books, n, sid);
                if (found != NULL) {
                    showBook(found);
                    printf("New available copies: ");
                    scanf("%d", &nc);
                    updateCopies(found, nc);
                } else {
                    printf("Book %d not found!\n", sid);
                }
                break;
            }
            case 2:
                printf("\n=== All Books ===\n");
                for (int i = 0; i < n; i++) {
                    showBook(&books[i]);
                }
                break;
            case 3:
                printf("Done!\n");
                break;
            default:
                printf("Invalid!\n");
                break;
        }
    } while (ch != 3);
    
    free(books);
    return 0;
}
