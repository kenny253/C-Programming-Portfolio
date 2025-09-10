#include <stdio.h>

int main(void)
{
    int x;
    int iArray[5];
    int index = -1;

    // Populate the array with values
    for (x = 0; x < 5; x++)
        iArray[x] = (x + 5);

    // Prompt the user until a valid index is entered
    do {
        printf("Enter a valid index (0 - 4): ");
        scanf("%d", &index);
    } while (index < 0 || index > 4);

    printf("The value of index %d is %d\n", index, iArray[index]);

    return 0;
}
