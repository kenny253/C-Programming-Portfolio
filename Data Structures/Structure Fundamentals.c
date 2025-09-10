#include <stdio.h>
#include <string.h>

// A simple structure definition for a math problem.
struct math {
    int x;
    int y;
    int result;
};

int main(void)
{
    // Create an instance of the 'math' structure and initialize its members.
    struct math aProblem = {0, 0, 0};

    // Assign values to the structure's members using the dot operator.
    aProblem.x = 10;
    aProblem.y = 10;
    aProblem.result = 20;

    // Print the contents of the structure to the console.
    printf("\n%d plus %d", aProblem.x, aProblem.y);
    printf(" equals %d\n", aProblem.result);

    return 0;
}
