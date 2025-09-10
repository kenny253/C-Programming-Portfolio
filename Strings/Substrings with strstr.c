#include <stdio.h>
#include <string.h>

int main(void)
{
    char *str1 = "When the going gets tough, the tough stay put!";
    char *str2 = "Going";
    char *str3 = "tou";
    char *str4 = "ay put!";

    printf("\nSentence = \"%s\"\n", str1);
    printf("str2 = \"%s\"\n", str2);
    printf("str3 = \"%s\"\n", str3);
    printf("str4 = \"%s\"\n", str4);
    printf("\n");

    // Use strstr() to check if "Going" is a substring of str1.
    // strstr() returns a pointer to the first occurrence if found, or NULL otherwise.
    if (strstr(str1, str2) != NULL) {
        printf("The string \"%s\" was found in the sentence: \"%s\"\n", str2, str1);
    } else {
        printf("The string \"%s\" was not found in the sentence\n", str2);
    }

    // Check for "tou".
    if (strstr(str1, str3) != NULL) {
        printf("The string \"%s\" was found in the sentence: \"%s\"\n", str3, str1);
    } else {
        printf("The string \"%s\" was not found in the sentence\n", str3);
    }

    // Check for "ay put!".
    if (strstr(str1, str4) != NULL) {
        printf("The string \"%s\" was found in the sentence: \"%s\"\n", str4, str1);
    } else {
        printf("The string \"%s\" was not found in the sentence:\n", str4);
    }

    return 0;
}
