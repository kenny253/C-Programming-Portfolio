#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Declare pointers to integers
    int *number;
    int *Newnumber;
    int x;

    // Use malloc() to allocate memory for 5 integers.
    number = malloc(5 * sizeof(int));

    // Always check for successful memory allocation.
    if (number == NULL) {
        printf("Out of Memory!");
        return 1;
    }

    printf("\nOriginal Memory (5 integers):\n");
    // Initialize and print the values in the original memory block.
    for (x = 0; x < 5; x++) {
        number[x] = x * 100;
        printf("number[%d] = %d\n", x, number[x]);
    }

    // Use realloc() to resize the memory block to hold 10 integers.
    Newnumber = realloc(number, 10 * sizeof(int));

    // Check for successful reallocation. If Newnumber is NULL, the original
    // pointer 'number' is still valid.
    if (Newnumber == NULL) {
        printf("\nOut of Memory!\n");
        // Free the original memory block if reallocation fails.
        free(number);
        return 1;
    } else {
        // If successful, update the 'number' pointer to the new memory location.
        number = Newnumber;
    }

    // Since realloc() does not initialize new memory, we must do it ourselves.
    // The loop initializes all 10 integers to demonstrate the expanded size.
    for (x = 0; x < 10; x++) {
        number[x] = x * 100;
    }

    printf("\nExpanded Memory (10 integers):\n");
    // Print the values in the expanded memory block.
    for (x = 0; x < 10; x++) {
        printf("number[%d] = %d\n", x, number[x]);
    }

    // Free the dynamically allocated memory when done.
    free(number);

    return 0;
}
