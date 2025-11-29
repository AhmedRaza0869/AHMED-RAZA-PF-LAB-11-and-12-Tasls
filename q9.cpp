/*Question 9: Recursive String Reverse Game
Write a recursive C program that takes a string from the user and reverses it using
recursion. Then show the reversed string as a “puzzle output”.
Requirements:
? Function reverseString(str, start, end)
? No loops allowed
? Swap characters recursively*/
#include <stdio.h>
#include <string.h>

void reverseString(char string[], int start, int end) {
    if (start >= end) {
        return;
    }
    
    char temp = string[start];
    string[start] = string[end];
    string[end] = temp;
    
    reverseString(string, start + 1, end - 1);
}

int main() {
    char string[100];
    
    printf("Enter a string: ");
    scanf(" %[^\n]", string);
    
    char og[100];
    strcpy(og, string);
    
    int len = strlen(string);
    reverseString(string, 0, len - 1);
    
    printf("\n=== String Reverse Puzzle ===\n");
    printf("Original: %s\n", og);
    printf("Reversed: ");
    
    for (int i = 0; i < len; i++) {
        printf("%c", string[i]);
    }
    printf("\n");
    
    printf("Can you read the reversed string? It's a puzzle!\n");
    
    return 0;
}
