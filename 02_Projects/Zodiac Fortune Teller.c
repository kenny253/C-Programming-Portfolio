#include <stdio.h>

int main(void)
{
    // Declare a variable to store the user's input.
    int input;

    // Display the program title and options to the user.
    printf("\tA program to generate your fortune based on your zodiac sign\n");
    printf("1. Scorpio\n");
    printf("2. Aquarius\n");
    printf("3. Leo\n");
    printf("4. Libra\n");
    printf("What is your zodiac sign? Enter a number between 1-4: ");
    scanf("%d", &input);

    // Use a 'switch' statement to handle the different user choices.
    switch (input)
    {
        case 1:
            printf("You are a natural leader and are going to lead one day.\n");
            break;
        case 2:
            printf("You are a humanitarian and are going to help a lot of people one day.\n");
            break;
        case 3:
            printf("You are a brave person; you are going to be a soldier one day.\n");
            break;
        case 4:
            printf("You are empathetic and going to be a doctor one day.\n");
            break;
        default:
            printf("You entered an invalid input. Please enter a number between 1-4.\n");
            break;
    }

    return 0;
}
