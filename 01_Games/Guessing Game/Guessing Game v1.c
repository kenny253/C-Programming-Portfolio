#include <stdio.h>
#include <stdlib.h> // Required for rand() and srand()
#include <time.h>   // Required for time()
#include <ctype.h>  // Required for the isdigit() function

int main(void)
{
    // Declare variables
    char cUrnumber;
    int Number;
    int Randnum;

    // Seed the random number generator using the current time.
    // This ensures a different sequence of random numbers each time the program runs.
    srand(time(NULL));

    // Generate a random number between 1 and 10.
    Randnum = (rand() % 10) + 1;

    // --- Part 1: Character vs. Digit Check ---
    printf("\nThis is a program that will try to determine if your input is a digit or a letter.\n");
    printf("\nEnter an input: ");

    // Use ' ' before %c in scanf to handle any whitespace characters (like the newline
    // from a previous input) that might be left in the buffer.
    scanf(" %c", &cUrnumber);

    // Use isdigit() to check if the character is a digit.
    if (isdigit(cUrnumber))
    {
        printf("You entered a number.\n");
    }
    else
    {
        printf("You entered a character.\n");
    }

    // --- Part 2: Number Guessing Game ---
    printf("\nNow, let's play a number guessing game.\n");
    printf("I have generated a number between 1 and 10. Try to guess it: ");

    // Read the user's number guess.
    scanf("%d", &Number);

    printf("I generated %d.\n", Randnum);

    // Check if the user's guess matches the random number.
    if (Randnum == Number)
    {
        printf("You guessed right!\n");
    }
    else
    {
        printf("You guessed wrong.\n");
    }
    return 0;
}