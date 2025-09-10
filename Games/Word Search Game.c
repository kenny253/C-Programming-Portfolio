#include <stdio.h>
#include <string.h>
#include <stdlib.h> // For rand() and srand()
#include <ctype.h>  // For toupper()
#include <windows.h> // For Sleep() and system("cls")

// Function prototype for the main game logic.
void answer(char *strGame[], char *hiddenWords[]);

int main(void)
{
    // A 2D array of strings representing the word puzzle grid.
    char *strGame[5] = {
        "ADELANGUAGEFERVZOPIBMOU",     // Hidden word: LANGUAGE
        "ZBPOINTERSKLMLOOPMNOCOT",     // Hidden word: POINTER
        "PODSTRINGGDIWHIEEICERLS",     // Hidden word: STRING
        "YVCPROGRAMMERWQKNULTHMD",     // Hidden word: PROGRAMMER
        "UKUNIXFIMWXIZEQZINPUTEX"      // Hidden word: UNIX
    };

    // An array containing the hidden words for validation.
    char *hiddenWords[5] = {
        "LANGUAGE", "POINTER", "STRING", "PROGRAMMER", "UNIX"
    };

    int difficulty;
    int x;

    printf("\t\tWORD GAME\n");
    printf("1\tEasy\n");
    printf("2\tMedium\n");
    printf("3\tHard\n");
    printf("Select Difficulty [1 - 3]: ");
    scanf("%d", &difficulty);
    getchar(); // Consume the leftover newline character

    int waitTime = 0;
    // Set the memorization time based on the selected difficulty.
    switch (difficulty) {
        case 1:
            waitTime = 7000; // 7 seconds
            printf("\nEasy Difficulty Mode\n");
            break;
        case 2:
            waitTime = 5000; // 5 seconds
            printf("\nMedium Difficulty Mode\n");
            break;
        case 3:
            waitTime = 3000; // 3 seconds
            printf("\nHard Difficulty Mode\n");
            break;
        default:
            printf("Invalid choice. Defaulting to Easy.\n");
            waitTime = 7000;
            break;
    }

    printf("You have %.1f seconds to memorize the words in the letters below.\n", waitTime / 1000.0);
    printf("The word grids are:\n");
    // Print the word grids to the console.
    for (x = 0; x < 5; x++) {
        printf("%s\n", strGame[x]);
    }

    // Pause the program to allow the user to memorize the words.
    Sleep(waitTime);
    // Clear the screen.
    system("cls");

    // Call the function that handles the rest of the game.
    answer(strGame, hiddenWords);

    return 0;
}

// Function to handle user input and scoring.
void answer(char *strGame[], char *hiddenWords[])
{
    int choice;
    char input[50];
    int score = 0;
    int i, found;

    do {
        printf("\nEnter 1 to enter a word, or 2 to quit: ");
        scanf("%d", &choice);
        getchar(); // Clear the newline after scanf

        if (choice == 1) {
            printf("Enter word found: ");
            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = '\0'; // Remove the newline character

            // Convert the user's input to uppercase for case-insensitive comparison.
            for (i = 0; i < strlen(input); i++) {
                input[i] = toupper(input[i]);
            }

            // Check if the entered word exists in the hiddenWords array.
            found = 0;
            for (i = 0; i < 5; i++) {
                if (strcmp(input, hiddenWords[i]) == 0) {
                    // Check if the word is found within the corresponding grid line.
                    if (strstr(strGame[i], input) != NULL) {
                        found = 1;
                        break;
                    }
                }
            }

            if (found) {
                printf("Good! The word was found in the text.\n");
                score++;
            } else {
                printf("Wrong. The word was not found or is not one of the hidden words.\n");
                score--;
            }
        }
    } while (choice != 2);

    printf("\nFinal Score: %d\n", score);
}
