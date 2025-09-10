#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

int main(void)
{
    //CHARACTER COUNTING USING CALLOC
    int x = 0;
    char *name;
    name = calloc(80, sizeof(char));

    //Checks whether memory allocation was succesful
    if (name == NULL){
        printf("\nOut of Memory!\n");
        return 1;
    }

    printf("\nEnter your name(79 characters max): ");
    fgets(name, 80, stdin);
    name[strcspn(name, "\n")] = 0;//removes the newline fgets automatically puts at the end of my stdin

    while (name[x] != '\0'){
            x++;}
        printf("\nThe number of characters in your name is %d\n", x);
    free(name);//frees up space after the code stops running so the code can be reused
}





