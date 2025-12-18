#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototype for the dice toss function.
void TossDie(int []);

int main(void)
{
    int Dice[6] = {0};
    int select;

    printf("\t\tDICE ROLLING GAME\n");
    do {
        printf("\n\tMENU\n");
        printf("1\tToss dies\n");
        printf("2\tQuit\n");
        printf("Choose your option: ");
        scanf("%d", &select);

        switch(select) {
            case 1:
                TossDie(Dice);
                break;
            case 2:
                printf("\nProgram exited.\n");
                return 0;
            default:
                printf("You entered the wrong option. Returning to menu.\n");
                break;
        }
    } while (select != 2);

    return 0;
}

// Function to simulate rolling six dice and storing the results.
void TossDie(int Array[6])
{
    int x;
    srand(time(NULL)); // Seed the random number generator using the current time.

    for (x = 0; x < 6; x++) {
        // Generate a random number between 1 and 6.
        int randnum = (rand() % 6) + 1;
        Array[x] = randnum;
    }

    printf("\nThe value of the 6 dice are:\n");

    for (x = 0; x < 6; x++) {
        printf("\nDie %d -> %d\n", x + 1, Array[x]);
    }
}
