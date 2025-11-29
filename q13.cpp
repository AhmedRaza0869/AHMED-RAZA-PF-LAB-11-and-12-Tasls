#include <stdio.h>

void printStars(int n) {
    if(n <= 0) {
        printf("\n");
        return;
    }
    printf("*");
    printStars(n - 1);
}

void printUpper(int w) {
    if(w <= 0) return;
    
    printStars(w);
    printUpper(w - 1);
}

void printLower(int w, int max) {
    if(w > max) return;
    
    if(w > 1) {
        printStars(w);
    }
    printLower(w + 1, max);
}

void hourglass(int w) {
    printUpper(w);
    printLower(2, w);
}

int main() {
    int w;
    
    printf("Enter hourglass width: ");
    scanf("%d", &w);
    
    printf("\n");
    hourglass(w);
    
    return 0;
}
