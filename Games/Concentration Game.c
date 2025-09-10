#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h> // For Sleep()

int main(void)
{
    srand(time(NULL)); // Seed random numbers

    int correct = 0;
    int incorrect = 0;
    int level = 0;

    // Variables for numbers and responses
    int rand1, rand2, rand3, rand4, rand5;
    int resp1, resp2, resp3, resp4, resp5;

    while (1) // infinite loop, break when user chooses Quit
    {
        system("cls"); // clear screen
        printf("\t\tTHE CONCENTRATION GAME\n");
        printf("Select difficulty\n");
        printf("1 Easy (remember 3 numbers in 5 seconds)\n");
        printf("2 Intermediate (remember 5 numbers in 5 seconds)\n");
        printf("3 Hard (remember 5 numbers in 2 seconds)\n");
        printf("4 Quit\n");
        printf("Enter your selection: ");
        scanf("%d", &level);

        if (level == 4) // exit condition
            break;

        // Generate random numbers
        rand1 = rand() % 10;
        rand2 = rand() % 10;
        rand3 = rand() % 10;
        rand4 = rand() % 10;
        rand5 = rand() % 10;

        switch (level)
        {
        case 1:
            printf("\nMemorize these numbers. You have 5 seconds:\n");
            printf("%d\t%d\t%d\n", rand1, rand2, rand3);
            Sleep(5000);

            system("cls");
            printf("Enter the 3 numbers you memorized: ");
            scanf("%d %d %d", &resp1, &resp2, &resp3);

            if (resp1 == rand1 && resp2 == rand2 && resp3 == rand3)
            {
                printf("Correct!\n");
                correct++;
            }
            else
            {
                printf("Incorrect. The correct numbers were %d, %d, %d.\n", rand1, rand2, rand3);
                incorrect++;
            }
            break;

        case 2:
            printf("\nMemorize these numbers. You have 5 seconds:\n");
            printf("%d\t%d\t%d\t%d\t%d\n", rand1, rand2, rand3, rand4, rand5);
            Sleep(5000);

            system("cls");
            printf("Enter the 5 numbers you memorized: ");
            scanf("%d %d %d %d %d", &resp1, &resp2, &resp3, &resp4, &resp5);

            if (resp1 == rand1 && resp2 == rand2 && resp3 == rand3 && resp4 == rand4 && resp5 == rand5)
            {
                printf("Correct!\n");
                correct++;
            }
            else
            {
                printf("Incorrect. The correct numbers were %d, %d, %d, %d, %d.\n", rand1, rand2, rand3, rand4, rand5);
                incorrect++;
            }
            break;

        case 3:
            printf("\nMemorize these numbers. You have 2 seconds:\n");
            printf("%d\t%d\t%d\t%d\t%d\n", rand1, rand2, rand3, rand4, rand5);
            Sleep(2000);

            system("cls");
            printf("Enter the 5 numbers you memorized: ");
            scanf("%d %d %d %d %d", &resp1, &resp2, &resp3, &resp4, &resp5);

            if (resp1 == rand1 && resp2 == rand2 && resp3 == rand3 && resp4 == rand4 && resp5 == rand5)
            {
                printf("Correct!\n");
                correct++;
            }
            else
            {
                printf("Incorrect. The correct numbers were %d, %d, %d, %d, %d.\n", rand1, rand2, rand3, rand4, rand5);
                incorrect++;
            }
            break;

        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }

        //Pause so the player can see result
        printf("\nCurrent Score: %d correct, %d wrong\n", correct, incorrect);
        printf("Press Enter to continue...");
        getchar(); // consume leftover newline
        getchar(); // wait for Enter
    }

    // Final score
    printf("\n\nGame Over. You got %d correct and %d wrong.\n", correct, incorrect);

    return 0;
}
