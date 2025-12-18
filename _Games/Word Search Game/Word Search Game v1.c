#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h> // For system() call

// Function prototype for checking the user's answer
void checkAnswer(char *, char []);

int main(void)
{
    // A 2D array of strings representing the word puzzle grids.
    char *strGame[5] = {
        "ADELANGUAGEFERVZOPIBMOU",
        "ZBPOINTERSKLMLOOPMNOCOT",
        "PODSTRINGGDIWHIEEICERLS",
        "YVCPROGRAMMERWQKNULTHMD",
        "UKUNIXFIMWXIZEQZINPUTEX"
    };

    char answer[80] = {0}; // Array to store the user's input
    int displayed = 0;
    int x;
    time_t startTime = 0;

    system("cls"); // Clear the console screen
    printf("\n\n\tWord Find\n\n");

    // Get the current time to start the timer
    startTime = time(NULL);

    // Loop through each word grid
    for (x = 0; x < 5; x++) {
        // Display the text for a limited time (3 seconds)
        while (startTime + 3 > time(NULL)) {
            if (displayed == 0) {
                printf("\n\nFind a Word in: \n\n");
                printf("%s\n\n", strGame[x]);
                displayed = 1;
            }
        }

        system("cls"); // Clear the screen again
        printf("\nEnter Word Found: ");

        // Note: Using `gets()` is risky because it doesn't check for buffer overflows.
        // It is recommended to use `fgets()` instead for safer input handling.
        gets(answer);

        // Pass the grid string and the user's answer to the checkAnswer function.
        checkAnswer(strGame[x], answer);

        // Reset the flag and timer for the next word.
        displayed = 0;
        startTime = time(NULL);
    }

    return 0;
}

// Function to check if the user's answer is a substring of the word grid.
void checkAnswer(char *string1, char string2[])
{
    int x;

    // Convert the user's answer to uppercase for a valid comparison.
    for (x = 0; x < strlen(string2); x++) {
        string2[x] = toupper(string2[x]);
    }

    // `strstr()` returns a non-zero pointer if a substring is found, otherwise it returns NULL (which is 0).
    // The second check `string2[0] != 0` ensures the user didn't just press Enter on an empty line.
    if (strstr(string1, string2) != 0 && string2[0] != 0) {
        printf("\nGreat Job!\n");
    } else {
        printf("\nSorry, word not found!\n");
    }
}
