#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    // Seed the random number generator using the current time
    srand(time(NULL));

    // Declare variables
    int randnum1, randnum2, response;
    int numquestions, total;
    int x;
    int correct = 0;
    int incorrect = 0;

    printf("\tTHIS IS A MATH QUIZ PROGRAM\n");
    printf("How many questions do you want to answer? ");
    scanf("%d", &numquestions);

    // Loop for the number of questions specified by the user
    for (x = 0; x < numquestions; x++)
    {
        // Generate two random numbers between 0 and 9
        randnum1 = rand() % 10;
        randnum2 = rand() % 10;
        total = randnum1 * randnum2;

        printf("What is %d x %d: ", randnum1, randnum2);
        scanf("%d", &response);

        // Check if the user's response is correct
        if (response == total)
        {
            printf("You entered the correct answer, which is %d.\n", response);
            correct++;
        }
        else
        {
            printf("The answer you entered was wrong. The correct answer is %d.\n", total);
            incorrect++;
        }
    }

    printf("\nQuiz complete!\n");
    printf("You got %d correct and %d wrong.\n", correct, incorrect);

    return 0;
}
