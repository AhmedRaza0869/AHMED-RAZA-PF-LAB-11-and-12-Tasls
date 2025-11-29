/*Question 5: Write a C program to implement a recursive function to check if a given
string is a palindrome.*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int Palindrome(char str[], int start, int end) {
    if (start >= end) {
        return 1;
    }
    
    if (tolower(str[start]) != tolower(str[end])) {
        return 0;
    }
    
    return Palindrome(str, start + 1, end - 1);
}

int main() {
    char str[100];
     printf("Enter a string: ");
    scanf(" %[^\n]", str);
    
    int len = strlen(str);
    
    if (Palindrome(str, 0, len - 1)) {
        printf("'%s' is a palindrome.\n", str);
    } else {
        printf("'%s' is not a palindrome.\n", str);
    }
    
    return 0;
}
