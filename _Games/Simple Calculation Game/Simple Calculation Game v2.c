#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// --- Configuration Constants ---
#define MAX_VALUE 20           // Max operand value for easier mental math
#define MAX_SCORE_FILE "math_quiz_score.txt" // File to store the high score

// --- Enumeration for Operations ---
typedef enum {
    OP_ADDITION = 0,
    OP_SUBTRACTION,
    OP_MULTIPLICATION,
    NUM_OPERATIONS // Used to determine the range for random selection
} Operation;

// --- Function Prototypes ---
void init_game();
double get_high_score();
void update_high_score(double current_score);
char get_operator_char(Operation op);
int run_single_question(Operation *op);
void run_quiz_session();

// --- File I/O Functions ---

/*
 * Function: get_high_score
 * Purpose: Reads the previously saved high score from a file.
 * Returns: The recorded high score (double), or 0.0 if the file cannot be read.
 */
double get_high_score() {
    FILE *file = fopen(MAX_SCORE_FILE, "r");
    double high_score = 0.0;

    if (file == NULL) {
        // File doesn't exist yet, return 0
        return 0.0;
    }

    if (fscanf(file, "%lf", &high_score) != 1) {
        // File exists but is empty/corrupted
        high_score = 0.0;
    }

    fclose(file);
    return high_score;
}

/*
 * Function: update_high_score
 * Purpose: Compares the current quiz score with the saved high score and updates the file if better.
 * Parameters:
 * current_score - The score achieved in the latest quiz (as a percentage).
 */
void update_high_score(double current_score) {
    double old_high_score = get_high_score();

    if (current_score > old_high_score) {
        FILE *file = fopen(MAX_SCORE_FILE, "w"); // Open file in write mode to overwrite

        if (file == NULL) {
            fprintf(stderr, "Error: Could not open high score file for writing.\n");
            return;
        }

        fprintf(file, "%.2lf", current_score); // Save the new score formatted to 2 decimal places
        fclose(file);

        printf("\n*** NEW HIGH SCORE ACHIEVED! %.2f%% ***\n", current_score);
    } else {
        printf("\nHigh score is %.2f%%. Great effort!\n", old_high_score);
    }
}


// --- Core Quiz Logic Functions ---

/*
 * Function: init_game
 * Purpose: Seeds the random number generator.
 */
void init_game() {
    srand((unsigned int)time(NULL));
}

/*
 * Function: get_operator_char
 * Purpose: Returns the character representation for an operation.
 */
char get_operator_char(Operation op) {
    switch (op) {
        case OP_ADDITION:       return '+';
        case OP_SUBTRACTION:    return '-';
        case OP_MULTIPLICATION: return 'x'; // Use 'x' for multiplication for clarity
        default:                return '?';
    }
}

/*
 * Function: run_single_question
 * Purpose: Generates a single random arithmetic problem, asks the user, and scores it.
 * Parameters:
 * op - Pointer to the Operation enum that was used (optional, for tracking).
 * Returns: 1 if the answer is correct, 0 if incorrect.
 */
int run_single_question(Operation *op) {
    int randnum1, randnum2, user_response, total;

    // 1. Select a random operation
    Operation random_op = rand() % NUM_OPERATIONS;
    *op = random_op; // Store the operation used

    // 2. Generate numbers based on the operation
    randnum1 = rand() % MAX_VALUE;
    randnum2 = rand() % MAX_VALUE;

    switch (random_op) {
        case OP_ADDITION:
            total = randnum1 + randnum2;
            break;

        case OP_SUBTRACTION:
            // Ensure the result is non-negative: swap operands if the first is smaller
            if (randnum1 < randnum2) {
                int temp = randnum1;
                randnum1 = randnum2;
                randnum2 = temp;
            }
            total = randnum1 - randnum2;
            break;

        case OP_MULTIPLICATION:
            // Keep multiplication numbers smaller for easier mental math
            randnum1 = rand() % (MAX_VALUE / 2);
            randnum2 = rand() % (MAX_VALUE / 2);
            total = randnum1 * randnum2;
            break;

        default:
            total = 0; // Should not happen
            break;
    }

    // 3. Prompt user and read response
    printf("\nWhat is %d %c %d: ", randnum1, get_operator_char(random_op), randnum2);
    if (scanf("%d", &user_response) != 1) {
        // Input error handling
        while (getchar() != '\n'); // Clear buffer
        return 0; // Treat as incorrect
    }

    // 4. Score and display result
    if (user_response == total) {
        printf("Correct!\n");
        return 1;
    } else {
        printf("Wrong. The correct answer is %d.\n", total);
        return 0;
    }
}

/*
 * Function: run_quiz_session
 * Purpose: Manages the entire quiz session, including input and scoring.
 */
void run_quiz_session() {
    int numquestions = 0;
    int correct = 0;
    int x;
    double final_score;
    Operation current_op;

    printf("\t--- MATH QUIZ PROGRAM ---\n");
    printf("(Current High Score: %.2f%%)\n", get_high_score());

    printf("\nHow many questions do you want to answer? ");
    if (scanf("%d", &numquestions) != 1 || numquestions <= 0) {
        printf("Invalid number of questions. Starting with 5.\n");
        numquestions = 5;
    }
    while (getchar() != '\n'); // Clear input buffer

    // Loop for the number of questions specified by the user
    for (x = 0; x < numquestions; x++) {
        printf("\n--- Question %d of %d ---", x + 1, numquestions);
        if (run_single_question(&current_op) == 1) {
            correct++;
        }
    }

    // Calculate final score
    final_score = ((double)correct / numquestions) * 100.0;

    printf("\n\n--- Quiz Complete ---\n");
    printf("Total Questions: %d\n", numquestions);
    printf("Correct Answers: %d\n", correct);
    printf("Final Score: %.2f%%\n", final_score);

    // Update high score using File I/O
    update_high_score(final_score);
}

/*
 * Function: main
 * Purpose: Main entry point.
 */
int main(void) {
    init_game();
    run_quiz_session();
    return 0;
}