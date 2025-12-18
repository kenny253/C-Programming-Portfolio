#include <stdio.h>
#include <stdlib.h> // Required for rand() and srand()
#include <time.h>   // Required for time()

int main(void)
{
    // Seed the random number generator using the current time.
    // This ensures a different sequence of random numbers each time the program runs.
    srand(time(NULL));
    int input;

    // Generate two random numbers between 1 and 6 to simulate a pair of dice.
    int diceone = (rand() % 6) + 1;
    int dicetwo = (rand() % 6) + 1;

    printf("\nEnter 1 to roll the dice: ");
    scanf("%d", &input);

    // Calculate the sum of the two dice.
    int sum = diceone + dicetwo;

    printf("\nYou rolled a %d and a %d.\n", diceone, dicetwo);

    // Check if the sum of the dice is a winning number (7 or 11).
    if (sum == 6 || sum == 12)
    {
        printf("The sum is %d. Player wins!\n", sum);
    }
    else
    {
        printf("The sum is %d. Better luck next time!\n", sum);
    }

    printf("\nThank you for playing.\n");

    return 0;
}
