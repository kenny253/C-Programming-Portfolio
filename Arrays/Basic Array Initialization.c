#include <stdio.h>

int main(void)
{
    int x;
    int number[5]; // Array with 5 indexes from 0 to 4

    // Use a loop to populate the array with values
    for (x = 0; x < 5; x++) {
        number[x] = x + 1;
    }

    // Print the value in each index
    for (x = 0; x < 5; x++) {
        printf("The value in index number %d is %d\n", x, number[x]);
    }

    // Change a specific index's value and print it
    number[4] = 10;
    printf("\nThe value in index number 4 is now %d\n", number[4]);

    return 0;
}
