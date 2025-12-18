#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a structure to represent a single playing card.
// Each card has a type (suit), a value, and a flag to see if it has been used.
typedef struct deck {
    char type[10];
    char used;
    int value;
} aDeck;

// Function prototype for the shuffle function.
void shuffle(aDeck *);

int main(void)
{
    int x, y;

    // Create an array of 52 'aDeck' structs to represent a full deck of cards.
    aDeck myDeck[52];

    // Seed the random number generator. This should be called only once.
    srand(time(NULL));

    // Initialize the structure array with all 52 cards.
    // The outer loop handles the four suits.
    for (x = 0; x < 4; x++) {
        // The inner loop handles the 13 cards within each suit.
        for (y = 0; y < 13; y++) {
            switch (x) {
                case 0:
                    strcpy(myDeck[y].type, "Diamonds");
                    myDeck[y].used = 'n';
                    myDeck[y].value = y;
                    break;
                case 1:
                    strcpy(myDeck[y + 13].type, "Clubs");
                    myDeck[y + 13].value = y;
                    myDeck[y + 13].used = 'n';
                    break;
                case 2:
                    strcpy(myDeck[y + 26].type, "Hearts");
                    myDeck[y + 26].value = y;
                    myDeck[y + 26].used = 'n';
                    break;
                case 3:
                    strcpy(myDeck[y + 39].type, "Spades");
                    myDeck[y + 39].value = y;
                    myDeck[y + 39].used = 'n';
                    break;
            } //end switch
        } //end inner loop
    } //end outer loop

    // Call the shuffle function to deal the cards.
    shuffle(myDeck);

    return 0;
} //end main

// Function to shuffle the deck and print five random, unique cards.
// It takes a pointer to the deck array.
void shuffle(aDeck *thisDeck)
{
    int iRnd;
    int found = 0;

    printf("Your five cards are: \n\n");

    // Loop until five unique cards have been found.
    while (found < 5) {
        // Generate a random number between 0 and 51.
        iRnd = rand() % 52;

        // Check if the randomly selected card has not been used yet.
        if (thisDeck[iRnd].used == 'n') {
            switch (thisDeck[iRnd].value) {
                case 12:
                    printf("Ace of %s\n", thisDeck[iRnd].type);
                    break;
                case 11:
                    printf("King of %s\n", thisDeck[iRnd].type);
                    break;
                case 10:
                    printf("Queen of %s\n", thisDeck[iRnd].type);
                    break;
                case 9:
                    printf("Jack of %s\n", thisDeck[iRnd].type);
                    break;
                default:
                    // For card values 0-8, print the number + 2 (so 2-10).
                    printf("%d of %s\n", thisDeck[iRnd].value + 2, thisDeck[iRnd].type);
                    break;
            } //end switch

            // Mark the card as used and increment the counter.
            thisDeck[iRnd].used = 'y';
            found = found + 1;
        } //end if
    } // end while loop
} //end shuffle
