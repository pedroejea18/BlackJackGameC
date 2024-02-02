#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
int dealCard(int cards[]);
int calculateScore(int cards[], int size);
void compare(int userScore, int computerScore);

int main() {
    // Seed for random number generation
    srand(time(NULL));

    // Card values
    int cards[] = {11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};
    int userCards[10];
    int computerCards[10];

    // Initialize user and computer hands
    for (int i = 0; i < 2; i++) {
        userCards[i] = dealCard(cards);
        computerCards[i] = dealCard(cards);
    }

    // Print the ASCII art for the title
    printf(".------.            _     _            _    _            _    \n");
    printf("|A_  _ |.          | |   | |          | |  (_)          | |   \n");
    printf("|( \\/ ).-----.     | |__ | | __ _  ___| | ___  __ _  ___| | __\n");
    printf("| \\  /|K /\\  |     | '_ \\| |/ _` |/ __| |/ / |/ _` |/ __| |/ /\n");
    printf("|  \\/ | /  \\ |     | |_) | | (_| | (__|   <| | (_| | (__|   < \n");
    printf("`-----| \\  / |     |_.__/|_|\\__,_|\\___|_|\\_\\ |\\__,_|\\___|_|\\_\\ \n");
    printf("      |  \\/ K|                            _/ |                \n");
    printf("      `------'                           |__/                 \n");

    int userIndex = 2;
    int computerIndex = 2;
    int userTurn = 1;

    // User turn
    while (userTurn != 0) {
        // Display user current cards and score
        printf("Your cards: ");
        for (int i = 0; i < userIndex; i++) {
            printf("%d ", userCards[i]);
        }
        printf(", current score: %d\n", calculateScore(userCards, userIndex));

        // Display the computer first card
        printf("Computer's first card: %d\n", computerCards[0]);

        char input[2];
        // Prompt user to get another card or pass
        printf("Type 'y' to get another card, type 'n' to pass: ");
        scanf("%s", input);

        if (input[0] == 'y') {
            userCards[userIndex++] = dealCard(cards);
        } else {
            userTurn = 0;
        }
    }

    // Computer's turn
    while (calculateScore(computerCards, computerIndex) != 0 && calculateScore(computerCards, computerIndex) < 17) {
        computerCards[computerIndex++] = dealCard(cards);
    }

    // Display final hands and scores
    printf("Your final hand: ");
    for (int i = 0; i < userIndex; i++) {
        printf("%d ", userCards[i]);
    }
    printf(", final score: %d\n", calculateScore(userCards, userIndex));

    printf("Computer's final hand: ");
    for (int i = 0; i < computerIndex; i++) {
        printf("%d ", computerCards[i]);
    }
    printf(", final score: %d\n", calculateScore(computerCards, computerIndex));

    // Compare user and computer scores and determine the winner
    compare(calculateScore(userCards, userIndex), calculateScore(computerCards, computerIndex));

    return 0;
}

// Function to deal a random card
int dealCard(int cards[]) {
    return cards[rand() % 13];
}

// Function to calculate the score of a hand
int calculateScore(int cards[], int size) {
    int sum = 0;
    int aceCount = 0;

    for (int i = 0; i < size; i++) {
        sum += cards[i];

        // Check for Aces
        if (cards[i] == 11) {
            aceCount++;
        }
    }

    // Adjust for Aces
    while (sum > 21 && aceCount > 0) {
        sum -= 10;
        aceCount--;
    }

    return sum;
}

// Function to compare user and computer scores
void compare(int userScore, int computerScore) {
    if (userScore == computerScore) {
        printf("It's a draw\n");
    } else if (computerScore == 0) {
        printf("You lose, Computer Blackjack\n");
    } else if (userScore == 0) {
        printf("You win, Blackjack\n");
    } else {
        if (userScore > 21) {
            printf("You lose\n");
        } else if (computerScore > 21) {
            printf("You win\n");
        } else {
            if (userScore > computerScore) {
                printf("You win\n");
            } else {
                printf("You lose\n");
            }
        }
    }
}
