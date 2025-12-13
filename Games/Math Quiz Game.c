/*This program is a maths quiz game which generates random maths problems of varying difficulties
which the user must guess the answer to if the answer is correct the user gets some points or vice versa*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// --- Configuration Constants ---
#define MAX_QUIZ_VALUE 100 // Maximum value for the random operands (0 to 99)
#define MAX_PROBLEM_COUNT 100 // Upper limit for the number of questions
#define MIN_PROBLEM_COUNT 1   // Lower limit for the number of questions

// --- Enumeration for Operations ---

/*
 * Enum to define the possible arithmetic operations.
 * This makes the code much more readable than using raw integer codes.
 */
typedef enum {
    OP_ADDITION = 0,
    OP_SUBTRACTION,
    OP_MULTIPLICATION,
    NUM_OPERATIONS // Used to determine the range for random selection
} Operation;

// --- Data Structure for Quiz ---

/*
 * Structure to hold all necessary data for a single quiz problem.
 * The 'operation' field is added to track the type of problem.
 */
typedef struct {
    int operand1;
    int operand2;
    int user_answer;
    int correct_answer; // Storing the correct answer avoids recalculation
    Operation operation;
    char result_code; // 'C' for correct, 'I' for incorrect
} QuizProblem;


// --- Function Prototypes ---
void initialize_random_seed();
int get_problem_count();
QuizProblem* allocate_quiz_memory(int count);
void run_quiz(QuizProblem problems[], int count);
void display_results(const QuizProblem problems[], int count);
void free_quiz_memory(QuizProblem *problems);


// --- Function Implementations ---

/*
 * Function: initialize_random_seed
 * Purpose: Seeds the random number generator using the current time.
 */
void initialize_random_seed() {
    srand((unsigned int)time(NULL));
}

/*
 * Function: get_problem_count
 * Purpose: Prompts the user for the number of quiz problems and validates the input.
 * Returns: The requested number of problems (integer).
 */
int get_problem_count() {
    int response = 0;
    int status;
    bool valid_input = false;

    printf("\n\t\t--- MULTI-OPERATION MATH QUIZ CHALLENGE ---\n");

    while (!valid_input) {
        printf("\nEnter number of problems (max %d): ", MAX_PROBLEM_COUNT);

        // Check if scanf successfully read an integer
        status = scanf("%d", &response);

        // Handle successful read and bounds check
        if (status == 1) {
            if (response >= MIN_PROBLEM_COUNT && response <= MAX_PROBLEM_COUNT) {
                valid_input = true;
            } else {
                printf("Error: Please enter a number between %d and %d.\n", MIN_PROBLEM_COUNT, MAX_PROBLEM_COUNT);
            }
        } else {
            printf("Error: Invalid input. Please enter a whole number.\n");
            // Clear the input buffer to prevent infinite loop on bad input
            while (getchar() != '\n');
        }
    }
    return response;
}

/*
 * Function: allocate_quiz_memory
 * Purpose: Dynamically allocates memory for the array of QuizProblem structures using calloc.
 * Parameters:
 * count - The number of QuizProblem structures needed.
 * Returns: A pointer to the allocated array, or NULL if allocation fails.
 */
QuizProblem* allocate_quiz_memory(int count) {
    // Use calloc to allocate memory and initialize it to zero
    QuizProblem *problems = (QuizProblem *)calloc(count, sizeof(QuizProblem));

    if (problems == NULL) {
        fprintf(stderr, "\nERROR: Failed to allocate memory for %d problems. Exiting.\n", count);
    }
    return problems;
}

/*
 * Function: get_operator_char
 * Purpose: Helper function to return the character representation of an operation.
 * Parameters:
 * op - The Operation enum value.
 * Returns: The character ('+', '-', or '*').
 */
char get_operator_char(Operation op) {
    switch (op) {
        case OP_ADDITION:       return '+';
        case OP_SUBTRACTION:    return '-';
        case OP_MULTIPLICATION: return '*';
        default:                return '?'; // Should not happen
    }
}

/*
 * Function: run_quiz
 * Purpose: Generates, presents, and scores the multi-operation math problems.
 * Parameters:
 * problems - The array of QuizProblem structures.
 * count - The number of problems to run.
 */
void run_quiz(QuizProblem problems[], int count) {
    printf("\n--- Start Quiz ---\n");

    for (int i = 0; i < count; i++) {
        // 1. Select a random operation
        problems[i].operation = rand() % NUM_OPERATIONS;

        // 2. Generate operands (keep operands small for multiplication)
        if (problems[i].operation == OP_MULTIPLICATION) {
            problems[i].operand1 = rand() % 10; // 0-9
            problems[i].operand2 = rand() % 10; // 0-9
        } else {
            problems[i].operand1 = rand() % MAX_QUIZ_VALUE;
            problems[i].operand2 = rand() % MAX_QUIZ_VALUE;
        }

        // 3. Calculate the correct answer based on the operation
        switch (problems[i].operation) {
            case OP_ADDITION:
                problems[i].correct_answer = problems[i].operand1 + problems[i].operand2;
                break;
            case OP_SUBTRACTION:
                // Ensure the result is non-negative for a simpler quiz experience
                if (problems[i].operand1 < problems[i].operand2) {
                    // Swap them so operand1 >= operand2
                    int temp = problems[i].operand1;
                    problems[i].operand1 = problems[i].operand2;
                    problems[i].operand2 = temp;
                }
                problems[i].correct_answer = problems[i].operand1 - problems[i].operand2;
                break;
            case OP_MULTIPLICATION:
                problems[i].correct_answer = problems[i].operand1 * problems[i].operand2;
                break;
            default:
                // Fallback for safety, though NUM_OPERATIONS prevents this
                problems[i].correct_answer = 0;
                break;
        }

        // 4. Prompt user and read answer
        printf("Problem %d: %d %c %d = ", 
            i + 1, 
            problems[i].operand1, 
            get_operator_char(problems[i].operation), 
            problems[i].operand2);
        
        if (scanf("%d", &problems[i].user_answer) != 1) {
            fprintf(stderr, "Invalid input. Skipping problem %d.\n", i + 1);
            problems[i].result_code = 'I'; 
            while (getchar() != '\n'); // Clear buffer
            continue;
        }

        // 5. Score the answer
        if (problems[i].user_answer == problems[i].correct_answer) {
            problems[i].result_code = 'C';
        } else {
            problems[i].result_code = 'I';
        }
    }
    printf("\n--- Quiz Complete ---\n");
}

/*
 * Function: display_results
 * Purpose: Calculates and prints the detailed results, including score and summary statistics.
 * Parameters:
 * problems - The array of completed QuizProblem structures.
 * count - The total number of problems.
 */
void display_results(const QuizProblem problems[], int count) {
    int correct_count = 0;

    printf("\n\n--- Detailed Quiz Results ---\n");
    // Adjusted column size to fit multiplication problems
    printf("-----------------------------------------------------------\n"); 
    printf("| # | Question \t| Your Answer \t| Correct Answer | Result |\n");
    printf("-----------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        char op_char = get_operator_char(problems[i].operation);
        char *result_text;

        if (problems[i].result_code == 'C') {
            result_text = "Correct";
            correct_count++;
        } else {
            result_text = "Incorrect";
        }

        printf("| %d | %d %c %d\t| %d\t\t| %d\t\t | %s\n",
               i + 1,
               problems[i].operand1,
               op_char,
               problems[i].operand2,
               problems[i].user_answer,
               problems[i].correct_answer,
               result_text);
    }
    printf("-----------------------------------------------------------\n");

    // Display summary statistics
    printf("\n--- Summary ---\n");
    printf("Total Questions: %d\n", count);
    printf("Correct Answers: %d\n", correct_count);
    printf("Incorrect Answers: %d\n", count - correct_count);
    printf("Final Score: %.2f%%\n", (double)correct_count / count * 100.0);
}

/*
 * Function: free_quiz_memory
 * Purpose: Releases the dynamically allocated memory block.
 * Parameters:
 * problems - Pointer to the allocated memory block.
 */
void free_quiz_memory(QuizProblem *problems) {
    if (problems != NULL) {
        free(problems);
        // It's good practice to set the pointer to NULL after freeing
        problems = NULL;
    }
}

/*
 * Function: main
 * Purpose: Main entry point. Coordinates the setup, execution, and cleanup of the quiz.
 */
int main(void) {
    // 1. Setup Phase
    initialize_random_seed();
    int num_problems = get_problem_count();

    // 2. Memory Allocation Phase
    QuizProblem *quiz_data = allocate_quiz_memory(num_problems);

    // Critical error check for memory allocation failure
    if (quiz_data == NULL) {
        return 1; // Exit with error code
    }

    // 3. Execution Phase
    run_quiz(quiz_data, num_problems);

    // 4. Results and Cleanup Phase
    display_results(quiz_data, num_problems);
    free_quiz_memory(quiz_data);

    return 0; // Successful program exit
}