#include <stdio.h>

int main(void)
{
    // A 3x3 array to search through
    int a[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };

    // Flag to check if the value was found, initialized to 0 (false)
    int found = 0;
    int value, x, y;

    // Array to store the coordinates where the value was found
    int foundat[2] = {0, 0};

    printf("Enter a value to search for ");
    scanf("%d", &value);

    // Search the 2D array
    for (x = 0; x < 3; x++) {
        for (y = 0; y < 3; y++) {
            if (a[x][y] == value) {
                found = 1;
                foundat[0] = x;
                foundat[1] = y;
                // Exit the inner loop once the value is found
                break;
            }
        }
    }

    if (found == 1)
        printf("Found value in a[%d][%d]\n", foundat[0], foundat[1]);
    else
        printf("Value not found\n");

    return 0;
}
