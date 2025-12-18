#include <stdio.h>
#include <string.h>  // For string manipulation functions
#include <ctype.h>   // For character handling (toupper)
#include <time.h>    // For timing and seeding rand()
#include <stdlib.h>  // For system() call, rand(), srand(), exit()
#include <stdbool.h> // For boolean type

// --- Constants and Configuration ---
#define GRID_COUNT 10
#define MAX_WORD_LENGTH 25
#define MAX_INPUT_BUFFER (MAX_WORD_LENGTH + 2) // +2 for newline and null terminator

// Difficulty time limits in seconds
#define TIME_EASY 6
#define TIME_MEDIUM 4
#define TIME_HARD 2

// --- Data Structures ---

// Structure to hold the puzzle grid and its specific target word
typedef struct {
    const char *grid;
    const char *target_word;
} Puzzle;

// The complete list of puzzles. These words are HIDDEN and must be found by memory.
Puzzle puzzle_list[GRID_COUNT] = {
    // Grid                                     Target Word
    {"ADELANGUAGEFERVZOPIBMOU",                 "LANGUAGE"},
    {"ZBPOINTERSKLMLOOPMNOCOT",                 "POINTERS"},
    {"PODSTRINGGDIWHIEEICERLS",                 "STRING"},
    {"YVCPROGRAMMERWQKNULTHMD",                 "PROGRAMMER"},
    {"UKUNIXFIMWXIZEQZINPUTEX",                 "INPUT"},
    {"ALGORITHMSDNZCQWKXPYTHON",                "ALGORITHMS"},
    {"DATASTRUCTURESAEIOUYBCDE",                "DATASTRUCTURES"},
    {"MEMORYALLOCATIONFGHJKLMN",                "ALLOCATION"},
    {"COMPILERSOPTMIZATIONQRS",                 "COMPILERS"},
    {"DEBUGGINGPROCESSRSTUVWX",                 "DEBUGGING"}
};

// --- Function Prototypes ---
void display_menu(int *difficulty_level, int *time_limit);
void shuffle_puzzles(Puzzle arr[], int n);
void run_game(int time_limit);
bool check_answer(const Puzzle *puzzle, char *user_answer);
void normalize_input(char *str);
void clear_input_buffer();

// --- Function Implementations ---

/*
 * Function: clear_input_buffer
 * Purpose: Clears any leftover characters in the standard input buffer.
 */
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/*
 * Function: display_menu
 * Purpose: Presents the difficulty options and sets the time limit.
 */
void display_menu(int *difficulty_level, int *time_limit) {
    int choice = 0;
    
    // Clear screen for a clean start
    system("cls");
    printf("\n\n\t--- Advanced Word Search Memory Challenge ---\n\n");
    printf("Instructions: You will see a grid for a few seconds. Find and memorize a hidden word.\n\n");
    printf("Select Difficulty:\n");
    printf("1. Easy (Memorize Grid for %d seconds)\n", TIME_EASY);
    printf("2. Medium (Memorize Grid for %d seconds)\n", TIME_MEDIUM);
    printf("3. Hard (Memorize Grid for %d seconds)\n", TIME_HARD);
    printf("4. Quit\n");
    printf("\nEnter your selection: ");
    
    // Use scanf to read the integer, and check its result
    if (scanf("%d", &choice) != 1) {
        choice = 0; // Invalid input, default to 0
    }
    clear_input_buffer(); // Clear any remaining newline or invalid characters

    *difficulty_level = choice;

    // Set the time limit based on the user's choice
    switch (choice) {
        case 1:
            *time_limit = TIME_EASY;
            break;
        case 2:
            *time_limit = TIME_MEDIUM;
            break;
        case 3:
            *time_limit = TIME_HARD;
            break;
        case 4:
            // Quit option handled in main
            *time_limit = 0;
            break;
        default:
            printf("\nInvalid selection. Please try again.\n");
            *time_limit = 0;
            break;
    }
}

/*
 * Function: shuffle_puzzles
 * Purpose: Randomly shuffles the array of puzzles (Fisher-Yates algorithm).
 */
void shuffle_puzzles(Puzzle arr[], int n) {
    if (n > 1) {
        for (int i = 0; i < n - 1; i++) {
            // Generate a random index j such that i <= j < n
            int j = i + rand() / (RAND_MAX / (n - i) + 1);
            
            // Swap arr[i] with arr[j]
            Puzzle temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
}

/*
 * Function: normalize_input
 * Purpose: Converts input string to uppercase and removes trailing newline/whitespace.
 */
void normalize_input(char *str) {
    int len = strlen(str);
    // 1. Remove trailing newline/carriage return if present (from fgets)
    if (len > 0) {
        if (str[len - 1] == '\n' || str[len - 1] == '\r') {
            str[len - 1] = '\0';
            len--;
        }
    }
    // 2. Convert to uppercase for case-insensitive comparison
    for (int i = 0; i < len; i++) {
        str[i] = toupper(str[i]);
    }
}

/*
 * Function: check_answer
 * Purpose: Determines if the user's answer is correct by matching the target word.
 */
bool check_answer(const Puzzle *puzzle, char *user_answer) {
    char target_word_upper[MAX_WORD_LENGTH];
    
    // Copy target word to a mutable buffer for conversion to uppercase
    strcpy(target_word_upper, puzzle->target_word);
    normalize_input(target_word_upper);
    
    // Check 1: Does the user's answer match the required target word (case-insensitively)?
    if (strcmp(user_answer, target_word_upper) != 0) {
        printf("Incorrect Word. The target word was: '%s'.\n", puzzle->target_word);
        return false;
    }

    // Check 2: Verify the word is actually in the grid (redundant but robust)
    if (strstr(puzzle->grid, puzzle->target_word) == NULL) {
        printf("System Error: Target word '%s' not found in the puzzle grid!\n", puzzle->target_word);
        return false;
    }
    
    printf("Correct! You remembered the target word: %s\n", puzzle->target_word);
    return true;
}

/*
 * Function: run_game
 * Purpose: Contains the main loop and gameplay logic.
 */
void run_game(int time_limit) {
    char user_answer[MAX_INPUT_BUFFER];
    time_t start_time;
    int correct_count = 0;
    
    // 1. Shuffle the puzzles before starting the challenge
    shuffle_puzzles(puzzle_list, GRID_COUNT);
    
    printf("\n\n--- Starting Challenge (%d seconds per puzzle) ---\n", time_limit);
    printf("Press ENTER to view the first puzzle...");
    getchar(); // Wait for user to start

    for (int i = 0; i < GRID_COUNT; i++) {
        const Puzzle *current_puzzle = &puzzle_list[i];
        
        system("cls");
        printf("\n--- Puzzle %d of %d ---\n", i + 1, GRID_COUNT);
        
        // **KEY IMPROVEMENT: Display ONLY the Grid for the limited time.**
        printf("Memorize the hidden word in the grid! Time limit: %d seconds.\n\n", time_limit);
        printf("GRID: %s\n", current_puzzle->grid);
        
        // --- Timer Loop (Delay) ---
        start_time = time(NULL);
        while (time(NULL) < start_time + time_limit) {
            // Wait for time to expire
        }

        system("cls"); // Clear the screen, hiding the puzzle
        
        // --- Get Input ---
        printf("\n--- TIME'S UP! ---\n");
        printf("Which word was hidden in the grid? (Enter now): ");
        
        // Use the safe fgets function
        if (fgets(user_answer, sizeof(user_answer), stdin) == NULL) {
             printf("\nInput error. Skipping puzzle.\n");
             clear_input_buffer(); 
             continue;
        }

        // --- Process and Check Answer ---
        normalize_input(user_answer);
        
        if (check_answer(current_puzzle, user_answer)) {
            correct_count++;
        }
        
        // Pause before the next round
        printf("\n\n--- Current Score: %d/%d ---\n", correct_count, i + 1);
        printf("Press ENTER for the next puzzle...");
        getchar(); // Wait for user to acknowledge result and press Enter
    }
    
    // --- Final Score ---
    system("cls");
    printf("\n========================================\n");
    printf("CHALLENGE COMPLETE!\n");
    printf("Your final score is %d out of %d.\n", correct_count, GRID_COUNT);
    printf("========================================\n\n");
}

/*
 * Function: main
 */
int main(void) {
    // Seed the random number generator
    srand(time(NULL)); 
    
    int difficulty_level = 0;
    int time_limit = 0;

    // Loop until a valid choice or Quit is selected
    while (difficulty_level != 4) {
        display_menu(&difficulty_level, &time_limit);
        
        if (difficulty_level >= 1 && difficulty_level <= 3) {
            run_game(time_limit);
            // After the game, the loop continues to show the menu again
        } else if (difficulty_level == 4) {
            printf("\nExiting Challenge. Goodbye!\n");
            break;
        }
    }
    
    return 0;
}