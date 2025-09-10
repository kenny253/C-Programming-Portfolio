// This program demonstrates dynamic memory allocation using malloc()
// to store a user's favorite movie title. It then converts the
// entered name to all uppercase letters before printing it.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    // USING MALLOC TO RECEIVE AND DISPLAY INFO ABOUT UR FAVORITE MOVIE
    char *Favmovie;
    int x;

    // Allocate 80 bytes of memory on the heap for the string.
    Favmovie = malloc(80 * sizeof(char));

    // Always check if memory allocation was successful.
    if (Favmovie == NULL) {
        printf("Out of Memory!\n");
        return 1;
    }

    printf("\nEnter your favorite movie: ");

    // Use fgets to safely read the user's input.
    fgets(Favmovie, 80, stdin);

    // Use strcspn to find and replace the newline character with the null terminator.
    Favmovie[strcspn(Favmovie, "\n")] = '\0';

    printf("\nThe movie you entered was:\n");

    // Uses a for loop to loop through the string and convert each character to uppercase.
    for (x = 0; x < strlen(Favmovie); x++){
        Favmovie[x] = toupper(Favmovie[x]);
    }

    printf("\n%s\n", Favmovie);

    // Free the allocated memory when you are done with it.
    free(Favmovie);

    return 0;
}
