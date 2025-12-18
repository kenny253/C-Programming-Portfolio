#include <stdio.h>
#include <stdlib.h> // Required for rand() and srand()
#include <time.h>   // Required for time()
#include <stdbool.h> // For using bool type

// --- Function Prototypes ---
void init_game();
int roll_dice();
void display_roll(int dice1, int dice2);
void run_game_session();

// --- Core Game Functions ---

/*
 * Function: init_game
 * Purpose: Seeds the random number generator.
 */
void init_game() {
    // Seed the random number generator using the current time.
    srand((unsigned int)time(NULL));
}

/*
 * Function: roll_dice
 * Purpose: Simulates rolling two standard six-sided dice.
 * Parameters (Output):
 * dice1 - Pointer to store the value of the first die.
 * dice2 - Pointer to store the value of the second die.
 * Returns: The sum of the two dice.
 */
int roll_dice(int *dice1, int *dice2) {
    // Generate two random numbers between 1 and 6.
    *dice1 = (rand() % 6) + 1;
    *dice2 = (rand() % 6) + 1;
    return *dice1 + *dice2;
}

/*
 * Function: display_roll
 * Purpose: Prints the result of the dice roll to the console.
 */
void display_roll(int dice1, int dice2) {
    printf("\n--> You rolled a %d and a %d. Total: %d\n", dice1, dice2, dice1 + dice2);
}

/*
 * Function: run_game_session
 * Purpose: Manages the game logic for a single round of Craps.
 */
void run_game_session() {
    int dice1, dice2;
    int roll_sum;
    int point = 0; // The target score in the second stage of the game
    int game_stage = 1; // 1 = First roll (Come-out), 2 = Point established
    bool keep_playing = true;

    printf("\n--- Welcome to Console Craps! ---\n");
    printf("Roll 7 or 11 to win instantly. Roll 2, 3, or 12 to lose instantly.\n");
    printf("Any other number becomes the 'Point'.\n");

    while (keep_playing) {
        printf("\n----------------------------------------\n");
        if (game_stage == 1) {
            printf("STAGE 1: Come-out Roll.\n");
        } else {
            printf("STAGE 2: Point is %d. Roll again to match it.\n", point);
        }

        // Wait for user input to roll
        printf("Press ENTER to roll the dice...");
        // Clear input buffer before waiting for the next ENTER
        while (getchar() != '\n'); 
        getchar();

        roll_sum = roll_dice(&dice1, &dice2);
        display_roll(dice1, dice2);

        if (game_stage == 1) {
            // --- STAGE 1 LOGIC (Come-out Roll) ---
            if (roll_sum == 7 || roll_sum == 11) {
                printf("!!! NATURAL WIN! You win on the first roll! !!!\n");
                keep_playing = false;
            } else if (roll_sum == 2 || roll_sum == 3 || roll_sum == 12) {
                printf("!!! CRAPS LOSS! You lose on the first roll! !!!\n");
                keep_playing = false;
            } else {
                // Point is established, move to Stage 2
                point = roll_sum;
                game_stage = 2;
                printf("Point established: %d. You must roll a %d again to win.\n", point, point);
                printf("If you roll a 7, you lose.\n");
            }
        } else {
            // --- STAGE 2 LOGIC (Point Roll) ---
            if (roll_sum == point) {
                printf("!!! POINT HIT! You win by matching your point! !!!\n");
                keep_playing = false;
            } else if (roll_sum == 7) {
                printf("!!! SEVEN OUT! You rolled a 7 and lost! !!!\n");
                keep_playing = false;
            } else {
                printf("Roll was %d. Continue rolling to hit the Point (%d).\n", roll_sum, point);
            }
        }
    }
}

/*
 * Function: main
 * Purpose: Main entry point. Contains the continuous play loop.
 */
int main(void) {
    init_game(); // Initialize random seed
    char play_again = 'Y';

    do {
        run_game_session(); // Play one full round of the dice game

        // Prompt for continuous play
        printf("\nDo you want to play another round? (Y/N): ");
        if (scanf(" %c", &play_again) != 1) {
            play_again = 'N'; // Exit on input error
        }
        // Consume any remaining characters in the buffer
        while (getchar() != '\n'); 

    } while (play_again == 'y' || play_again == 'Y');

    printf("\nThank you for playing. Goodbye!\n");
    return 0;
}