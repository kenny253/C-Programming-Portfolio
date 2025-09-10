#include <stdio.h>

int main(void)
{
    // Variables for the start, end, and increment values
    int incrementBy;
    int startNum;
    int endNum;
    int currentNum;

    printf("\tThe Number Counting Program\n");

    // Get the start, end, and increment numbers from the user
    printf("Enter a number to begin counting from: ");
    scanf("%d", &startNum);
    printf("Enter a number to end counting at: ");
    scanf("%d", &endNum);
    printf("Enter a number to increment counting by: ");
    scanf("%d", &incrementBy);

    // --- Input Validation ---
    // Check if the increment value is a positive number
    if (incrementBy <= 0) {
        printf("Error: Increment must be a positive number greater than 0.\n");
        return 1;
    }
    // Check if the start and end numbers are the same
    else if (startNum == endNum) {
        printf("Error: The start and end numbers must be different. You entered %d for both.\n", startNum);
        return 1;
    }

    // --- Counting Logic ---
    // If the starting number is greater than the ending number, count down
    if (startNum > endNum) {
        for (currentNum = startNum; currentNum >= endNum; currentNum -= incrementBy) {
            printf("NUMBER: %d\n", currentNum);
        }
    }
    // If the starting number is less than the ending number, count up
    else {
        for (currentNum = startNum; currentNum <= endNum; currentNum += incrementBy) {
            printf("NUMBER: %d\n", currentNum);
        }
    }

    printf("Counting complete!\n");

    return 0;
}
