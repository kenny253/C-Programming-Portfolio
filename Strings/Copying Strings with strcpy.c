#include <stdio.h>
#include <string.h>

int main(void)
{
    // COPYING CONTENTS OF ONE STRING TO ANOTHER
    char str1[11];
    char *str2 = "C language";

    printf("Str1 now contains %s\n", strcpy(str1, str2));

    return 0;
}
