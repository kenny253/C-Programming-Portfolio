#include <stdio.h>

int main(void)
{
    // Initializing character arrays
    // char cName[] = { 'o', 'l', 'i', 'v', 'i', 'a', '\0'};
    char cName[] = "olivia";
    char cArray[5];
    int x;

    // Print an uninitialized character array to show its default contents
    printf("Uninitialized character array\n");
    for (x = 0; x < 5; x++)
        printf("Element %d content are %d\n", x, cArray[x]);

    // Print the initialized character array
    printf("Initialized character array\n");
    for (x = 0; x < 6; x++)
        printf("Element %d content are %c\n", x, cName[x]);

    return 0;
}
