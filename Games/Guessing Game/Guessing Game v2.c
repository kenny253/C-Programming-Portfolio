/*This program is a number guessing game the program generates a random digit the user then gets a specific
number of tries depending on the difficulty level selected if the user gets the digit correct he is rewarded points
the higher the difficulty the higher the points the points earned are then saved to a .txt file called highscore 
in the computers internal memory system */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

// --- CONSTANTS ---
#define FILENAME "highscore.txt"
#define MAX_GUESSES 10

// --- FUNCTION PROTOTYPES ---
void clear_input_buffer();
int get_integer_input(const char *prompt);
void run_char_check();
void run_guessing_game();
int load_high_score();
void save_high_score(int new_score);
void display_high_score();
void display_main_menu();


/**
 * Clears the input buffer to prevent issues with mixed scanf types.
 */
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/**
 * Reads a single integer input from the user with basic validation.
 * This function loops until a valid integer is successfully read.
 * prompt The message displayed to the user.
 * return The validated integer input.
 */
int get_integer_input(const char *prompt) {
    int input;
    printf("%s", prompt);

    while (scanf("%d", &input) != 1) {
        // Clear the input buffer to prevent infinite loops on non-numeric input
        clear_input_buffer(); 
        printf("Invalid input. Please enter a valid number: ");
        printf("%s", prompt);
    }
    clear_input_buffer(); // Consume the trailing newline
    return input;
}


// --- FILE I/O AND SCORING FUNCTIONS ---

/**
 *  Loads the current high score from the highscore.txt file.
 * return The loaded high score, or 0 if the file cannot be read or is empty.
 */
int load_high_score() {
    FILE *file = fopen(FILENAME, "r");
    int high_score = 0;
    
    // Check if the file was opened successfully
    if (file != NULL) {
        // Read the integer score. fscanf returns the number of items successfully read.
        if (fscanf(file, "%d", &high_score) != 1) {
            high_score = 0; // File exists but is empty or corrupt
        }
        fclose(file);
    }
    // If file is NULL, it doesn't exist yet, which is fine (returns 0).
    return high_score;
}

/**
 * Saves a new high score to the highscore.txt file, overwriting the old one.
 * new_score The score to be saved.
 */
void save_high_score(int new_score) {
    // Open in write mode ("w") to overwrite any existing content
    FILE *file = fopen(FILENAME, "w");

    if (file != NULL) {
        fprintf(file, "%d", new_score);
        fclose(file);
    } else {
        fprintf(stderr, "Error: Could not open %s for writing.\n", FILENAME);//"stderr is a correct way to display error messages in C"
    }
}

/**
 * Displays the current high score to the user.
 */
void display_high_score() {
    int score = load_high_score();
    printf("\n===================================\n");
    printf("   CURRENT HIGH SCORE: %d points\n", score);
    printf("===================================\n");
}


// --- GAME LOGIC FUNCTIONS ---

/**
 * Executes the character/digit identification logic.
 */
void run_char_check() {
    char input_char;
    printf("\n--- 1. Character/Digit Analyzer ---\n");
    printf("Enter a single character or digit: ");

    // Use scanf(" %c") to read a single character, skipping leading whitespace
    if (scanf(" %c", &input_char) == 1) {
        // Consume the trailing newline left by scanf
        clear_input_buffer(); 

        printf("Input: '%c'\n", input_char);
        
        if (isdigit(input_char)) {
            printf("Result: This is a DIGIT.\n");
        } else if (isalpha(input_char)) {
            // Check if it's an uppercase or lowercase letter
            if (isupper(input_char)) {
                printf("Result: This is an UPPERCASE LETTER.\n");
            } else {
                printf("Result: This is a LOWERCASE LETTER.\n");
            }
        } else {
            printf("Result: This is a SYMBOL or punctuation.\n");
        }
    } else {
        printf("Error reading input.\n");
        clear_input_buffer();
    }
}

/**
 * Executes the number guessing game logic with difficulty levels.
 */
void run_guessing_game() {
    printf("\n--- 2. Advanced Number Guessing Game ---\n");

    int min, max, max_attempts;
    int difficulty_choice = get_integer_input("Select Difficulty (1: Easy 1-10, 2: Medium 1-50, 3: Hard 1-100): ");

    switch (difficulty_choice) {
        case 1:
            min = 1; max = 10; max_attempts = 4;
            break;
        case 2:
            min = 1; max = 50; max_attempts = 7;
            break;
        case 3:
            min = 1; max = 100; max_attempts = 10;
            break;
        default:
            printf("Invalid difficulty choice. Defaulting to Medium (1-50).\n");
            min = 1; max = 50; max_attempts = 7;
            break;
    }

    // Generate random number in the defined range
    const int RAND_NUM = (rand() % (max - min + 1)) + min;
    int number_guess;
    int attempts = 0;
    int score_points = 0;

    printf("I have generated a number between %d and %d. You have %d tries.\n", min, max, max_attempts);
    
    // Game Loop
    do {
        attempts++;
        printf("\nAttempt %d of %d.\n", attempts, max_attempts);
        
        number_guess = get_integer_input("Your guess: ");

        if (number_guess < min || number_guess > max) {
            printf("Guess must be between %d and %d. Try again.\n", min, max);
            continue; 
        }

        if (RAND_NUM == number_guess) {
            // Calculate score: fewer attempts = higher score
            score_points = (max_attempts - attempts + 1) * 10;
            printf("\nCONGRATULATIONS! You guessed the number (%d) in %d attempts.\n", RAND_NUM, attempts);
            printf("You earned %d points!\n", score_points);
            
            int high_score = load_high_score();
            if (score_points > high_score) {
                printf("NEW HIGH SCORE! Previous score: %d\n", high_score);
                save_high_score(score_points);
            }

            return; // Exit the game function on win
        } else if (attempts < max_attempts) {
            printf("Wrong guess. ");
            // Provide feedback (higher/lower)
            if (number_guess < RAND_NUM) {
                printf("Try HIGHER.\n");
            } else {
                printf("Try LOWER.\n");
            }
        }
    } while (attempts < max_attempts);

    // If loop finishes without a return, the player ran out of attempts
    printf("\nGAME OVER. You ran out of attempts.\n");
    printf("The correct number was %d.\n", RAND_NUM);
}

// --- MAIN MENU ---

/**
 * Displays the main menu options to the user.
 */
void display_main_menu() {
    printf("\n------------------------------------------\n");
    printf("   C CONSOLE GAME SUITE (Portfolio Demo)\n");
    printf("------------------------------------------\n");
    printf("1. Run Character Analyzer\n");
    printf("2. Start Number Guessing Game\n");
    printf("3. View High Score\n");
    printf("4. Quit Program\n");
    printf("------------------------------------------\n");
}

/**
 * Main function: controls the program flow.
 */
int main(void) {
    // Seed the random number generator only once
    srand(time(NULL));

    int choice = 0;

    // Main program loop
    do {
        display_main_menu();
        choice = get_integer_input("Enter your choice (1-4): ");

        switch (choice) {
            case 1:
                run_char_check();
                break;
            case 2:
                run_guessing_game();
                break;
            case 3:
                display_high_score();
                break;
            case 4:
                printf("\nExiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid selection. Please choose a number between 1 and 4.\n");
                break;
        }

        if (choice != 4) {
            printf("\nPress ENTER to return to the menu...");
            getchar(); // Wait for user to press enter
        }
        
    } while (choice != 4);

    return 0;
}