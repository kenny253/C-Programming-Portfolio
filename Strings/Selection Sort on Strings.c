#include <stdio.h>
#include <string.h>

int main(void)
{
    // A 2D array of strings to be sorted.
    char states[4][20] = {"Alaska", "Oregon", "Texas", "Florida"};
    // A temporary buffer to hold a string during the swap process.
    char temp[20];
    int i, j;

    // Selection Sort algorithm to sort the strings in alphabetical order.
    // The outer loop iterates through the array from the first element to the second-to-last.
    for (i = 0; i < 4 - 1; i++) {
        // The inner loop compares the current element with all subsequent elements.
        for (j = i + 1; j < 4; j++) {
            // Use strcmp() to compare the strings.
            // strcmp() returns a value greater than 0 if the first string is alphabetically larger.
            if (strcmp(states[i], states[j]) > 0) {
                // If the strings are out of order, swap them.
                // strcpy() is used for string assignment.
                strcpy(temp, states[i]);
                strcpy(states[i], states[j]);
                strcpy(states[j], temp);
            }
        }
    }

    printf("The states sorted in alphabetic order are: \n");
    // Print the sorted array.
    for (i = 0; i < 4; i++) {
        printf("%s, ", states[i]);
    }

    printf("\n");

    return 0;
}
