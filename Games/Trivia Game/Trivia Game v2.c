#include <stdio.h>
#include <stdlib.h>
#include <string.h>    // For strcmp
#include <windows.h> // For Sleep() and system("cls")

// --- Constants for Trivia Data Structure ---
#define MAX_OPTIONS 4
#define MAX_QUESTION_LEN 100
#define MAX_OPTION_LEN 50
#define MAX_CATEGORY_LEN 20
#define TOTAL_QUESTIONS 15 // Total number of questions in the database

// --- Data Structures ---
// Structure to hold a single trivia question, its options, and the correct answer.
typedef struct {
    char category[MAX_CATEGORY_LEN];
    char question_text[MAX_QUESTION_LEN];
    char options[MAX_OPTIONS][MAX_OPTION_LEN];
    int correct_index; // 1-based index (1, 2, 3, or 4)
} Question;

// --- Trivia Question Database ---
Question trivia_database[TOTAL_QUESTIONS] = {
    // CATEGORY       QUESTION TEXT                                                   OPTIONS                                                                         CORRECT
    // Sports Questions
    {"Sports", "What University did NFL star Deion Sanders attend?",                {"University of Miami", "California State University", "Indiana University", "Florida State University"}, 4},
    {"Sports", "Which country won the FIFA World Cup in 2018?",                     {"Brazil", "Germany", "France", "Argentina"}, 3},
    {"Sports", "How many rings are in the official Olympic symbol?",                 {"4", "5", "6", "7"}, 2},
    {"Sports", "Which sport uses the terms 'Love' and 'Deuce'?",                    {"Baseball", "Golf", "Tennis", "Badminton"}, 3},
    {"Sports", "Who is the all-time leading scorer in NBA history?",                 {"LeBron James", "Michael Jordan", "Kareem Abdul-Jabbar", "Kobe Bryant"}, 1},

    // Geography Questions
    {"Geography", "What is the state capitol of Florida?",                           {"Pensecola", "Tallahassee", "Jacksonville", "Miami"}, 2},
    {"Geography", "Which continent is the Sahara Desert located on?",                {"Asia", "North America", "Africa", "South America"}, 3},
    {"Geography", "What is the capital city of Japan?",                              {"Shanghai", "Kyoto", "Seoul", "Tokyo"}, 4},
    {"Geography", "Which river is the longest in the world?",                        {"Amazon River", "Nile River", "Yangtze River", "Mississippi River"}, 2},
    {"Geography", "What is the smallest country in the world by land area?",         {"Monaco", "Vatican City", "Nauru", "Tuvalu"}, 2},

    // Science Questions
    {"Science", "What is H2O commonly known as?",                                   {"Salt", "Vinegar", "Water", "Oxygen"}, 3},
    {"Science", "What planet is known as the 'Red Planet'?",                         {"Jupiter", "Mars", "Venus", "Saturn"}, 2},
    {"Science", "What is the hardest natural substance on Earth?",                   {"Gold", "Iron", "Diamond", "Quartz"}, 3},
    {"Science", "What gas do plants primarily absorb from the atmosphere?",          {"Oxygen", "Nitrogen", "Carbon Dioxide", "Hydrogen"}, 3},
    {"Science", "What instrument is used to measure atmospheric pressure?",          {"Thermometer", "Barometer", "Anemometer", "Hygrometer"}, 2}
};

// --- Function Prototypes ---
void run_category_quiz(const char *category_name);
void clear_input_buffer(void);

// --- GLOBAL VARIABLES ---
int correct = 0;
int incorrect = 0;
int giresponse = 0;


/**********************************************************
FUNCTION DEFINITIONS
**********************************************************/

/*
 * Function: clear_input_buffer
 * Purpose: Clears any leftover characters in the standard input buffer
 * to prevent infinite loops or skipped inputs after using scanf.
 */
void clear_input_buffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/*
 * Function: run_category_quiz
 * Purpose: Iterates through the trivia database, finds questions belonging
 * to the specified category, administers the quiz, and updates
 * the global scores (correct, incorrect).
 * Parameters:
 * category_name - The category to filter questions by (e.g., "Sports").
 */
void run_category_quiz(const char *category_name)
{
    int ianswer = 0;
    int question_count = 0;

    system("cls");
    printf("\t--- %s QUIZ ---\n\n", category_name);

    for (int i = 0; i < TOTAL_QUESTIONS; i++)
    {
        // Use strcmp to check if the question belongs to the selected category
        if (strcmp(trivia_database[i].category, category_name) == 0)
        {
            question_count++;

            // Display question and options
            printf("Question %d: %s\n\n", question_count, trivia_database[i].question_text);
            for (int j = 0; j < MAX_OPTIONS; j++)
            {
                printf("%d\t%s\n", j + 1, trivia_database[i].options[j]);
            }

            printf("\nEnter selection (1-4): ");

            // Input handling
            if (scanf("%d", &ianswer) != 1) {
                // Handle invalid non-integer input
                ianswer = 0;
                clear_input_buffer();
            }

            // Check answer and update global score
            if (ianswer == trivia_database[i].correct_index)
            {
                printf("\nCorrect!\n");
                correct++;
            }
            else
            {
                printf("\nIncorrect! The correct answer was %d: %s\n", 
                       trivia_database[i].correct_index, 
                       trivia_database[i].options[trivia_database[i].correct_index - 1]);
                incorrect++;
            }

            Sleep(2000); // Pauses for 2 seconds (Windows-specific)
            system("cls"); // Clear screen for the next question
        }
    }
}

/*
 * Function: main
 */
int main(void)
{
    do {
        system("cls"); // Clears the screen (Windows-specific)
        printf("\t\nTHE TRIVIA GAME\n");
        printf("\nSelect a category to play:\n");
        printf("1\t Sports\n");
        printf("2\t Geography\n");
        printf("3\t Science\n");
        printf("4\t Quit\n");
        printf("What is your selection: ");
        
        // Read the user's menu choice
        if (scanf("%d", &giresponse) != 1) {
             giresponse = 0;
        }
        clear_input_buffer(); // Always clear the buffer after scanf

        switch (giresponse) {
            case 1:
                run_category_quiz("Sports");
                break;
            case 2:
                run_category_quiz("Geography");
                break;
            case 3:
                run_category_quiz("Science");
                break;
            case 4:
                // Exit condition handled below
                break;
            default:
                printf("\nInvalid selection. Press ENTER to try again...\n");
                getchar();
                break;
        }
        
        // After running a quiz or invalid choice, display current totals
        if (giresponse != 4)
        {
            printf("\n\n--- Current Totals ---\n");
            printf("Total Correct: %d\n", correct);
            printf("Total Incorrect: %d\n", incorrect);
            printf("Press ENTER to return to the category menu...");
            getchar(); // Wait for user to press enter
        }
        
    } while (giresponse != 4);

    system("cls");
    printf("\n\n================================\n");
    printf("TRIVIA GAME OVER\n");
    printf("Final Score: %d Correct, %d Incorrect.\n", correct, incorrect);
    printf("Thank you for playing!\n");
    printf("================================\n\n");

    return 0;
} // end main