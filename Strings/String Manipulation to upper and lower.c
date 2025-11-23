#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char name[20];
    int x;

    printf("\nEnter your name: ");
    // Note: scanf("%s", ...) stops reading at the first whitespace.
    // This is useful for single-word input like a name.
    scanf("%s", name);

    // Loop through the string and convert each character to uppercase.
    for (x = 0; x < strlen(name); x++) {
        name[x] = toupper(name[x]);
    }

    printf("\nThe name you entered was %s\n", name);
    printf("The number of characters in your name is %d\n", strlen(name));

    return 0;
}
