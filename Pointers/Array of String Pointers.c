#include <stdio.h>

int main(void)
{
    // An array of character pointers, which can hold a list of strings.
    char *strNames[5] = {0};
    int x;

    // Assigning string literals to each pointer in the array.
    strNames[0] = "Michael";
    strNames[1] = "Sheila";
    strNames[2] = "Spencer";
    strNames[3] = "Hunter";
    strNames[4] = "Kenya";

    printf("\nNames in pointer array of type char:\n\n");

    // Looping through the array and printing each string.
    for (x = 0; x < 5; x++) {
        printf("%s\n", strNames[x]);
    }

    return 0;
}
