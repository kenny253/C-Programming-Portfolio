#include <stdio.h>

// SORTING AN ARRAY USING BUBBLE SORT
int main(void)
{
    // Unsorted numbers
    int blocks[5] = {5, 3, 8, 2, 1};
    int x, y, temp;

    // Outer loop for passes
    for (x = 0; x < 5 - 1; x++) {
        // Inner loop for comparisons and swaps
        for (y = 0; y < 5 - 1 - x; y++) {
            if (blocks[y] > blocks[y + 1]) {
                // Ascending order: swap if the current element is greater than the next
                temp = blocks[y];
                blocks[y] = blocks[y + 1];
                blocks[y + 1] = temp;
            }
        }
    }

    printf("The sorted values are:\n");
    for (x = 0; x < 5; x++) {
        printf("%d ", blocks[x]);
    }

    return 0;
}
