#include <stdio.h>

int main(void)
{
    // An array to store up to 30 GPAs.
    float EntGpa[30] = {0};
    int select = 0;
    float sum = 0;
    // To track how many GPAs have been entered.
    int counter = 0;

    printf("STUDENT GPA CALCULATOR\n");

    // Main loop runs until the user quits or the array is full.
    while (counter < 30) {
        printf("\n\tMENU\n");
        printf("1\tEnter GPA\n");
        printf("2\tCalculate GPA average\n");
        printf("3\tQuit\n");
        printf("Choose a selection: ");
        scanf("%d", &select);

        if (select == 1) {
            printf("Enter GPA score %d: ", counter + 1);
            scanf("%f", &EntGpa[counter]);
            counter++;
        }
        else if (select == 2) {
            if (counter == 0) {
                printf("No GPA entries yet. Please add a GPA first.\n");
            } else {
                sum = 0;
                for (int i = 0; i < counter; i++) {
                    sum += EntGpa[i];
                }
                printf("GPA Average is: %.2f \n", sum / counter);
            }
        }
        else if (select == 3) {
            printf("\nYou entered %d GPA(s).\n", counter);
            for (int i = 0; i < counter; i++) {
                printf("Index %d: GPA = %.2f\n", i, EntGpa[i]);
            }
            break;
        }
        else {
            printf("Invalid choice. Please select 1, 2 or 3.\n");
        }
    }

    return 0;
}
