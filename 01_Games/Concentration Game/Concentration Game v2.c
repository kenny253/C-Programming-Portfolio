// Standard C Library for Input/Output operations (like printf and scanf)
#include <stdio.h>
// Standard C Library for general utilities (like the rand() function)
#include <stdlib.h>
// Standard C Library for time-related functions (used to seed randomizer and for delay)
#include <time.h>

/*
 * Note on Libraries:
 * This program uses <time.h> and the clock() function for a more standard/portable
 * way to implement a software-based delay, which works on most platforms without
 * relying on specific OS headers.
 */

// --- Function to simulate delay/sleep (platform-independent method) ---
void delay(int milliseconds) {
    // Variable to store the required number of clock ticks to pause
    long pause;
    // Variables to hold the current time (now) and the start time (then)
    clock_t now, then;

    // Calculate the number of clock ticks needed based on CLOCKS_PER_SEC macro
    // CLOCKS_PER_SEC is the number of clock ticks per second.
    // We divide by 1000 to get ticks per millisecond, then multiply by desired milliseconds.
    pause = milliseconds * (CLOCKS_PER_SEC / 1000);
    // Record the current clock time for both start and iteration check
    now = then = clock();

    // Loop continuously until the difference between the current time (now)
    // and the start time (then) is greater than or equal to the required pause duration.
    while ((now - then) < pause) {
        now = clock(); // Update the current clock time in each loop iteration
    }
}

// --- Function to clear the screen (uses ANSI Escape Codes for portability) ---
void clear_screen() {
    // "\033[H" moves the cursor to the home position (top-left).
    // "\033[J" clears the screen from the cursor position to the end.
    // This is the standard, cross-platform way to clear the terminal output.
    printf("\033[H\033[J");
}

// --- CORE GAME LOGIC FUNCTION ---
// The function plays one round of the concentration game.
// It returns 1 if the user is correct, and 0 if the user is incorrect or if an input error occurred.
int play_level(int count, int seconds) {
    // Variable Length Array (VLA) to store the random numbers. Its size 'count' is determined at runtime.
    int numbers[count];
    // VLA to store the user's responses.
    int responses[count];
    // Flag to track the round result. Starts as 1 (correct) and changes to 0 (incorrect) if a mismatch is found.
    int is_correct = 1;

    // Start of the round: Clear the screen for a clean display.
    clear_screen();
    printf("--- LEVEL START ---\n");
    printf("Memorize these %d numbers. You have %d seconds:\n\n", count, seconds);

    // 1. Generate and display random numbers
    for (int i = 0; i < count; i++) {
        // Generate a random single digit (0-9)
        numbers[i] = rand() % 10;
        // Print the digit
        printf("%d", numbers[i]);
        // Print a tab character (\t) between numbers for spacing, but not after the last number
        if (i < count - 1) {
            printf("\t");
        }
    }
    printf("\n\n"); // Print two newlines after displaying all numbers

    // 2. Wait for the specified time using the custom delay function
    delay(seconds * 1000); // Convert seconds to milliseconds for the function

    // 3. Clear screen and get user input
    clear_screen(); // Clear the screen so the numbers are hidden
    printf("Enter the %d numbers you memorized, separated by spaces: ", count);

    // Read the user's input into the responses array
    for (int i = 0; i < count; i++) {
        // Attempt to read an integer. scanf returns 1 if successful, 0 if not.
        if (scanf("%d", &responses[i]) != 1) {
            // Error handling for non-integer input (e.g., user types 'a')
            printf("\nInput error. Please only enter numbers.\n");
            // Consume remaining input to clear the buffer and prevent the error from affecting the next loop iteration
            while (getchar() != '\n');
            return 0; // Return 0 to indicate an incorrect attempt due to input error
        }
    }

    // Consume the leftover newline character ('\n') from the input buffer
    // This is crucial because if the buffer isn't clear, the next getchar() (later in main) might read this leftover newline immediately.
    while (getchar() != '\n');


    // 4. Compare results
    for (int i = 0; i < count; i++) {
        // Check if the user's response matches the generated random number
        if (responses[i] != numbers[i]) {
            is_correct = 0; // Set the flag to 0 (incorrect)
            break; // Stop checking immediately once a mismatch is found
        }
    }

    // 5. Display result and correct answer
    printf("\n--- RESULT ---\n");
    if (is_correct) {
        printf("CORRECT! Great concentration!\n");
        return 1; // Return 1 for correct
    } else {
        printf("INCORRECT.\n");
        // Display what the user entered
        printf("Your numbers: ");
        for (int i = 0; i < count; i++) {
            printf("%d%s", responses[i], (i < count - 1) ? "  " : "");
        }
        // Display the correct numbers
        printf("\nThe correct numbers were: ");
        for (int i = 0; i < count; i++) {
            printf("%d%s", numbers[i], (i < count - 1) ? "\t" : "");
        }
        printf("\n");
        return 0; // Return 0 for incorrect
    }
}

// --- MAIN FUNCTION: Program Entry Point ---
int main(void) {
    // Initialize the random number generator
    // time(NULL) returns the current time, ensuring a different sequence of random numbers each time the program runs.
    srand(time(NULL));

    int correct = 0;   // Counter for correct rounds
    int incorrect = 0; // Counter for incorrect/failed rounds
    int choice = 0;    // Variable to store the user's menu selection

    // Main game loop: Runs indefinitely until the user chooses the Quit option (case 4)
    while (1) {
        clear_screen(); // Clear the screen before showing the menu
        printf("\t\t--- THE CONCENTRATION GAME ---\n");
        printf("\nSelect difficulty\n");
        // Menu options defining the 'count' and 'seconds' for the play_level function
        printf("1. Easy (3 digits, 5 seconds)\n");
        printf("2. Intermediate (5 digits, 5 seconds)\n");
        printf("3. Hard (5 digits, 2 seconds)\n");
        printf("4. Quit\n"); // Option to exit the game
        printf("--------------------------------------------\n");
        printf("Enter your selection: ");

        // Basic input check for the menu choice
        if (scanf("%d", &choice) != 1) {
            // Handle non-integer input for choice
            printf("Invalid input. Please enter a number (1-4).\n");
            // Clear the input buffer to prevent looping issues
            while (getchar() != '\n');
            delay(2000); // Pause for 2 seconds so the user can read the error message
            continue; // Skip the rest of the loop and restart at the beginning (menu display)
        }
        // Consume the leftover newline after reading the choice integer
        while (getchar() != '\n');

        int result = 0; // Variable to store the return value of play_level (1 or 0)

        // Switch statement executes the appropriate game logic based on user's choice
        switch (choice) {
            case 1:
                result = play_level(3, 5); // Call game logic: 3 digits, 5 seconds
                break;
            case 2:
                result = play_level(5, 5); // Call game logic: 5 digits, 5 seconds
                break;
            case 3:
                result = play_level(5, 2); // Call game logic: 5 digits, 2 seconds
                break;
            case 4:
                // Exit condition: Jumps out of the 'while(1)' loop to the 'end_game' label
                goto end_game;
            default:
                // Handling for choices that are integers but not 1, 2, 3, or 4
                printf("\nInvalid choice. Please select 1, 2, 3, or 4.\n");
                delay(2000);
                continue; // Restart the loop (go back to the menu)
        }

        // Update score based on the result of the play_level function
        if (result == 1) {
            correct++;
        } else if (result == 0) {
            // Note: This covers both incorrect answers and input errors within play_level
            incorrect++;
        }

        // Pause section: Allows the player to review the round result and score
        printf("\n--------------------------------------------\n");
        printf("Current Score: %d correct, %d wrong\n", correct, incorrect);
        printf("Press ENTER to return to the menu...");
        // Wait for the user to press the Enter key before restarting the main loop
        getchar();
    }

    // Label for the exit point of the program
    end_game:
    clear_screen();
    printf("\n\t--- GAME OVER ---\n");
    printf("Final Score: %d correct and %d wrong.\n", correct, incorrect);
    printf("Thanks for playing!\n\n");

    return 0; // Indicate successful program execution
}