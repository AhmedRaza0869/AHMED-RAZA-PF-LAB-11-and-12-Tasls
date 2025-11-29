/*Question 7: Write a recursive program in C in which the computer selects a secret
number between 1 and 50. The user will keep guessing the number until the correct
answer is found. Use recursion such that every wrong guess calls the function again.
Requirements:
? Function guessNumber(secret)
? If guess &lt; secret ? print “Too Low”
? If guess &gt; secret ? print “Too High”
? If correct ? stop recursion and print number of attempts*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int guessNumber(int secret, int attempts) {
    int guess;
    
    printf("Guess the number (1-50): ");
    scanf("%d", &guess);
    
    if (guess == secret) {
        printf("Congratulations! You guessed it in %d attempts.\n", attempts + 1);
        return attempts + 1;
    } else if (guess < secret) {
        printf("Too Low! Try again.\n");
        return guessNumber(secret, attempts + 1);
    } else {
        printf("Too High! Try again.\n");
        return guessNumber(secret, attempts + 1);
    }
}

int main() {
    srand(time(0));
    int secret = rand() % 50 + 1;
    
    printf("=== Number Guessing Game ===\n");
    printf("I'm thinking of a number between 1 and 50.\n\n");
    
    int attempts = guessNumber(secret, 0);
    
    printf("Game Over! Total attempts: %d\n", attempts);
    
    return 0;
}
