#include <stdio.h>

int main(void)
{
    int iFound = -1;
    int x;
    int iValue;
    int iArray[5];

    // Populate the array with values
    for (x = 0; x < 5; x++)
        iArray[x] = (x + x);

    printf("Enter a value to search for: ");
    scanf("%d", &iValue);

    // Loop through the array to find the value
    for (x = 0; x < 5; x++) {
        if (iArray[x] == iValue) {
            iFound = x;
            break;
        }
    }

    // Print the result of the search
    if (iFound > -1)
        printf("\nI found your search value in element %d\n", iFound);
    else
        printf("\nSorry, your search value was not found\n");

    return 0;
}
