#include <stdio.h>
#include <stdlib.h> // For rand(), srand()
#include <time.h>   // For time()

int main(void)
{
    // Declare variables for the game
    char cYesNo = '\0';
    int iResp1 = 0;
    int iResp2 = 0;
    int iResp3 = 0;
    int iElapsedTime = 0;
    int iCurrentTime = 0;
    int i1 = 0;
    int i2 = 0;
    int i3 = 0;

    // Seed the random number generator using the current time
    srand(time(NULL));

    // Ask the user if they want to play
    printf("Play a game of concentration (Y or N): ");
    scanf(" %c", &cYesNo); // Note the space before %c to handle whitespace

    // Check if the user wants to play
    if (cYesNo == 'y' || cYesNo == 'Y')
    {
        // Generate three random numbers between 0 and 99
        i1 = rand() % 100;
        i2 = rand() % 100;
        i3 = rand() % 100;

        // Display the numbers to the user for them to memorize
        printf("Concentrate on the next 3 numbers\n");
        printf("\t%d\t%d\t%d", i1, i2, i3);

        // Create a delay of 3 seconds using a do-while loop
        iCurrentTime = time(NULL);
        do {
            iElapsedTime = time(NULL);
        } while ((iElapsedTime - iCurrentTime) < 3); // end loop

        // Clear the screen to remove the numbers
        system("cls");

        // Get the user's input
        printf("Enter each number separated with a space:");
        scanf("%d %d %d", &iResp1, &iResp2, &iResp3);

        // Check if the user's answers are correct
        if (iResp1 == i1 && iResp2 == i2 && iResp3 == i3) {
            printf("Congratulations!\n");
        }
        else {
            printf("Wrong! The correct answers were %d %d %d\n", i1, i2, i3);
        }
    }

    return 0;
}
