/*Question 8: Recursive Rock–Paper–Scissors (RPS) Game
Write a recursive C program to play Rock–Paper–Scissors for N rounds. Use recursion
to call the next round until all rounds are completed.
Requirements:
? Function playRPS(round, totalRounds)
? Random computer choice
? User input: rock/paper/scissors
? Keep score recursively
? End after N rounds*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
void playRPS(int round, int totalRounds, int userScore, int compScore) {
    if (round > totalRounds) {
        printf("\n=== Final Score ===\n");
        printf("User: %d, Computer: %d\n", userScore, compScore);
        if (userScore > compScore) {
            printf("You win the game!\n");
        } else if (compScore > userScore) {
            printf("Computer wins the game!\n");
        } else {
            printf("It's a tie!\n");
        }
        return;
    }
    printf("\n=== Round %d ===\n", round);
    srand(time(0) + round);
    int compChoice = rand() % 3;
    char *choices[] = {"rock", "paper", "scissors"};
    char userInput[10];
    printf("Enter your choice (rock/paper/scissors): ");
    scanf("%s", userInput);
    
    int userChoice = -1;
    for (int i = 0; i < 3; i++) {
        if (strcmp(userInput, choices[i]) == 0) {
            userChoice = i;
            break;
        }
    }
    
    if (userChoice == -1) {
        printf("Invalid choice! Please enter rock, paper, or scissors.\n");
        playRPS(round, totalRounds, userScore, compScore);
        return;
    }
    
    printf("Computer chose: %s\n", choices[compChoice]);
    printf("You chose: %s\n", choices[userChoice]);
    
    if (userChoice == compChoice) {
        printf("It's a tie!\n");
        playRPS(round + 1, totalRounds, userScore, compScore);
    } else if ((userChoice == 0 && compChoice == 2) ||
               (userChoice == 1 && compChoice == 0) ||
               (userChoice == 2 && compChoice == 1)) {
        printf("You win this round!\n");
        playRPS(round + 1, totalRounds, userScore + 1, compScore);
    } else {
        printf("Computer wins this round!\n");
        playRPS(round + 1, totalRounds, userScore, compScore + 1);
    }
}

int main() {
    int rounds;
    printf("Enter number of rounds: ");
    scanf("%d", &rounds);
    
    playRPS(1, rounds, 0, 0);
    
    return 0;
}
