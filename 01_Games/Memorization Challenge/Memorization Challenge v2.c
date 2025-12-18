#include <stdio.h>
#include <stdlib.h> // For rand(), srand(), system()
#include <time.h>   // For time(), clock()
#include <stdbool.h> // For using bool type

// --- Constants ---
#define MAX_DIGITS 5     // Maximum number of digits the game can handle
#define MAX_VALUE 100    // Numbers will be between 0 and 99
#define DISPLAY_TIME_SEC 3 // Time to display the numbers

// --- Function Prototypes ---
void init_game();
int get_game_length();
void run_game(int num_digits);
void custom_sleep(int seconds);

// --- Function Implementations ---

/*
 * Function: init_game
 * Purpose: Initializes the random seed once at the start of the program.
 */
void init_game() {
    srand((unsigned int)time(NULL));
}

/*
 * Function: custom_sleep
 * Purpose: Pauses execution for a specified number of seconds using time(NULL).
 * Parameters:
 * seconds - The duration of the pause.
 *
 * NOTE: This is the time-based sleep method used in your original file,
 * which is effective for simple console programs.
 */
void custom_sleep(int seconds) {
    long current_time = time(NULL);
    long elapsed_time;
    do {
        elapsed_time = time(NULL);
    } while ((elapsed_time - current_time) < seconds);
}

/*
 * Function: get_game_length
 * Purpose: Prompts the user to select the difficulty/length of the memorization challenge.
 * Returns: The valid number of digits (3, 4, or 5) the user chose.
 */
int get_game_length() {
    int choice = 0;
    int status;
    bool valid = false;

    printf("\n--- MEMORIZATION CHALLENGE ---\n");
    printf("Select difficulty:\n");
    printf("1. Easy (3 numbers)\n");
    printf("2. Medium (4 numbers)\n");
    printf("3. Hard (5 numbers)\n");
    printf("Enter choice (1-3): ");

    while (!valid) {
        status = scanf("%d", &choice);
        while (getchar() != '\n'); // Clear input buffer

        if (status == 1 && choice >= 1 && choice <= 3) {
            valid = true;
        } else {
            printf("Invalid input. Please enter 1, 2, or 3: ");
        }
    }
    // Map choice (1, 2, 3) to number of digits (3, 4, 5)
    return choice + 2;
}

/*
 * Function: run_game
 * Purpose: Contains the main game logic for generating, displaying, and checking numbers.
 * Parameters:
 * num_digits - The number of digits for the current challenge (e.g., 3, 4, or 5).
 */
void run_game(int num_digits) {
    // Use arrays to store the sequence and the user's responses
    int correct_sequence[MAX_DIGITS];
    int user_response[MAX_DIGITS];
    bool is_correct = true;

    // 1. Generate random numbers using a loop
    for (int i = 0; i < num_digits; i++) {
        correct_sequence[i] = rand() % MAX_VALUE;
    }

    // 2. Display the numbers to the user for them to memorize
    printf("\nConcentrate on these %d numbers. You have %d seconds:\n", num_digits, DISPLAY_TIME_SEC);
    
    // Display numbers using a loop
    for (int i = 0; i < num_digits; i++) {
        printf("%d\t", correct_sequence[i]);
    }
    printf("\n");

    // 3. Create a delay (3 seconds)
    custom_sleep(DISPLAY_TIME_SEC);

    // 4. Clear the screen (assuming a Unix/Windows environment)
    system("cls"); // Use "clear" for Unix/Linux

    // 5. Get the user's input
    printf("Enter the %d numbers you memorized (separated by spaces):\n", num_digits);
    
    // Read responses using a loop
    for (int i = 0; i < num_digits; i++) {
        if (scanf("%d", &user_response[i]) != 1) {
             fprintf(stderr, "Input error. Exiting current round.\n");
             while (getchar() != '\n'); // Clear buffer
             return;
        }
    }
    while (getchar() != '\n'); // Clear any remaining input

    // 6. Check if the user's answers are correct using a loop
    for (int i = 0; i < num_digits; i++) {
        if (user_response[i] != correct_sequence[i]) {
            is_correct = false;
            break;
        }
    }

    // 7. Display results
    if (is_correct) {
        printf("\nCONGRATULATIONS! You correctly memorized all %d numbers.\n", num_digits);
    } else {
        printf("\nWRONG! You missed at least one number.\n");
        printf("The correct sequence was: ");
        for (int i = 0; i < num_digits; i++) {
            printf("%d%s", correct_sequence[i], (i == num_digits - 1 ? "" : " "));
        }
        printf("\n");
    }
}

/*
 * Function: main
 * Purpose: Main entry point. Handles setup and the play loop.
 */
int main(void) {
    init_game(); // Seed the random number generator

    char cYesNo = 'Y'; // Start by assuming the user wants to play

    while (cYesNo == 'y' || cYesNo == 'Y') {
        int num_digits = get_game_length(); // Get user difficulty choice

        run_game(num_digits); // Run the core game challenge

        printf("\nPlay again (Y or N): ");
        if (scanf(" %c", &cYesNo) != 1) {
            cYesNo = 'N'; // Exit on input error
        }
        while (getchar() != '\n'); // Clear input buffer
    }

    printf("\nThank you for playing. Goodbye!\n");
    return 0;
}