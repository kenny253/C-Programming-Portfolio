#include <stdio.h>
#include <string.h>

int main(void)
{
    char sentence[50];

    printf("\nEnter a sentence: ");
    // Use fgets() to safely read a line of text from standard input.
    // It takes the variable, the max size, and the input stream (stdin).
    fgets(sentence, 50, stdin);

    // The `fgets()` function includes the newline character.
    // This line finds the newline and replaces it with a null terminator.
    sentence[strcspn(sentence, "\n")] = '\0';

    printf("\nThe sentence you entered was: \n");
    printf("%s\n", sentence);

    return 0;
}
