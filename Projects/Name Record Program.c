#include <stdio.h>

int main(void)
{
    // A 2D array to store up to 5 names, each with a maximum length of 19 characters.
    char name[5][20];
    int choice, x, i;
    int counter = 0;

    printf("THE NAME RECORD PROGRAM\n");
    printf("You can enter up to 5 friends names\n\n");

    do {
        printf("1\tEnter a name\n");
        printf("2\tPrint out every name in record\n");
        printf("3\tQuit\n");
        printf("Choose a selection: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Check if the array is full before accepting new input.
                if (counter < 5) {
                    printf("Enter a name number %d: ", counter + 1);
                    scanf("%s", name[counter]);
                    counter++;
                } else {
                    printf("All 5 name slots are full.\n");
                }
                break;
            case 2:
                printf("\t\tNames in record are: \n");
                for (x = 0; x < counter; x++) {
                    printf("%d\t%s\n", x + 1, name[x]);
                }
                printf("\n\n");
                break;
            case 3:
                printf("Program exited. You have %d names in record.\n", counter);
                printf("\t\tNames in record are: \n");
                for (x = 0; x < counter; x++) {
                    printf("%d\t%s\n", x + 1, name[x]);
                }
                return 0; // Return a success code on exit.
                break;
            default:
                printf("You entered an incorrect option, enter 1 - 3\n");
                break;
        }
    } while (counter < 5);

    printf("All 5 name slots exhausted\n");
    printf("\t\tNames in record are: \n");
    for (i = 0; i < counter; i++) {
        printf("%d\t%s\n", i + 1, name[i]);
    }

    return 0;
}
