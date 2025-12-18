#include <stdio.h>
#include <stdlib.h>
#include <windows.h> // For Sleep() and system("cls")

/********************************************
FUNCTION PROTOTYPES
********************************************/
int sciencequestions(void);
int sportquestions(void);
int geographyquestions(void);

/*******************************************/
/********************************************
GLOBAL VARIABLES
********************************************/
int correct = 0;
int incorrect = 0;
int giresponse = 0;
/*******************************************/

int main(void)
{
    do {
        system("cls"); // Clears the screen (Windows-specific)
        printf("\t\nTHE TRIVIA GAME\n");
        printf("1\t Sports\n");
        printf("2\t Geography\n");
        printf("3\t Science\n");
        printf("4\t Quit\n");
        printf("What is your selection: ");
        scanf("%d", &giresponse);

        switch (giresponse) {
            case 1:
                if (sportquestions() == 4) {
                    printf("Correct!\n");
                    correct++;
                } else {
                    printf("Incorrect!\n");
                    incorrect++;
                }
                Sleep(2000); // Pauses for 2 seconds (Windows-specific)
                break;
            case 2:
                if (geographyquestions() == 2) {
                    printf("Correct!\n");
                    correct++;
                } else {
                    printf("Incorrect!\n");
                    incorrect++;
                }
                Sleep(2000);
                break;
            case 3:
                if (sciencequestions() == 3) {
                    printf("Correct!\n");
                    correct++;
                } else {
                    printf("Incorrect!\n");
                    incorrect++;
                }
                Sleep(2000);
                break;
        } // end switch
    } while (giresponse != 4); // end while

    printf("U answered %d questions throughout the game.\n", correct + incorrect);
    if (giresponse == 4 && (correct + incorrect) != 0) {
        printf("Congratulations! You got %d questions correct.\n", correct);
        printf("You got %d questions wrong.\n", incorrect);
    }

    return 0;
} // end main

/**********************************************************
FUNCTION DEFINITIONS
**********************************************************/

int sportquestions(void)
{
    int ianswer = 0;
    system("cls");
    printf("\tSports Question\n");
    printf("\nWhat University did NFL star Deion Sanders attend? ");
    printf("\n\n1\tUniversity of Miami\n");
    printf("2\tCalifornia State University\n");
    printf("3\tIndiana University\n");
    printf("4\tFlorida State University\n");
    printf("Enter selection: ");
    scanf("%d", &ianswer);
    return ianswer;
} // end sportquestions

int geographyquestions(void)
{
    int ianswer = 0;
    system("cls");
    printf("\tGeography Question\n");
    printf("\nWhat is the state capitol of Florida? ");
    printf("\n\n1\tPensecola\n");
    printf("2\tTallahassee\n");
    printf("3\tJacksonville\n");
    printf("4\tMiami\n");
    printf("\nEnter your selection: ");
    scanf("%d", &ianswer);
    return ianswer;
} // end geographyquestions

int sciencequestions(void)
{
    int ianswer = 0;
    system("cls");
    printf("\tScience Question\n");
    printf("\nWho discovered the atom? ");
    printf("\n\n1\tJJ Thompson\n");
    printf("2\tGeiger Muller\n");
    printf("3\tJohn Dalton\n");
    printf("4\tErnest Rutherford\n");
    printf("\nEnter your selection: ");
    scanf("%d", &ianswer);
    return ianswer;
} // end sciencequestions
