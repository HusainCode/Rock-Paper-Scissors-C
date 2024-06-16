#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    const char* key; // Name of the selection (Rock, Paper, or Scissors)
    int value; // Numeric representation of the selection
} Selection;

#define NUM_CHOICES 3 // Constant for the number of game choices

// Function prototype
void determine_winner(int playerChoice, int computerChoice);

int main(void) {
    // Initialize the selections array with each game choice
    Selection selections[NUM_CHOICES] = {
            {"Rock", 0}, {"Paper", 1}, {"Scissors", 2}
    };

    srand(time(NULL));
    int computerChoice = rand() % NUM_CHOICES; // Randomly generate the computer choice

    // Display the choices to the user
    printf("Choose your selection:\n");
    for (int i = 0; i < NUM_CHOICES; i++) {
        printf("%d for %s\n", selections[i].value, selections[i].key);
    }

    int playerChoice;
    printf("Enter your choice: ");
    scanf("%d", &playerChoice);
    while (getchar() != '\n'); // Clear the input buffer

    // Check for valid input range
    if (playerChoice < 0 || playerChoice >= NUM_CHOICES) {
        printf("Invalid selection.\n");
        return 1;
    }

    // Announce the choices made
    printf("You chose %s\n", selections[playerChoice].key);
    printf("Computer chose %s\n", selections[computerChoice].key);

    determine_winner(playerChoice, computerChoice);

    return 0;
}

// Determine the winner, the rule of the game
void determine_winner(int playerChoice, int computerChoice) {
    if (playerChoice == computerChoice) {
        printf("It's a tie!\n");
    } else if ((playerChoice == 0 && computerChoice == 2) ||
               (playerChoice == 1 && computerChoice == 0) ||
               (playerChoice == 2 && computerChoice == 1)) {
        printf("You win!\n");
    } else {
        printf("Computer wins!\n");
    }
}
