
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    int response;
    int *answer;
    int *op1;
    int *op2;
    char *result;
    int x;

    srand(time(NULL));

    printf("\n\t\tMATHS PROBLEM\t\n");
    printf("\nEnter # of problems u wish to answer: ");
    scanf("%d", &response);

    /*Based on the number of questions the user wants to answer allocate memory
    to hold data*/

    op1 = (int *)calloc(response, sizeof(int));
    op2 = (int *)calloc(response, sizeof(int));
    answer = (int *)calloc(response, sizeof(int));
    result = (char *)calloc(response, sizeof(char));

    //Test for memory allocation success

    if (op1 == NULL || op2 == NULL || answer == NULL || result == NULL){
        printf("\nOut of Memory!\n");
        return 1;
    }//end if

    //Display random addition problems

    for (x = 0; x < response; x++){

        op1[x] = rand() % 100;
        op2[x] = rand() % 100;

        printf("\n%d + %d = ", op1[x], op2[x]);
        scanf("%d", &answer[x]);

        if ( answer[x] == op1[x] + op2[x] )
            result[x] = 'c';
        else
            result[x] = 'i';
        } // end for loop

        printf("\nQuiz Results\n");
        printf("\nQuestion\tYour Answer\tCorrect\n");

        //print the results of the quiz

        for ( x = 0; x < response; x++ ) {
        if ( result[x] == 'c' )
        printf("%d + %d\t\t%d\t\tYes\n", op1[x], op2[x], answer[x]);
        else
        printf("%d + %d\t\t%d\t\tNo\n", op1[x], op2[x], answer[x]);
        } //end for loop

        //free memory
        free(op1);
        free(op2);
        free(answer);
        free(result);

        return 0;
        //The main benefit of using calloc() rather than malloc() is calloc()’s ability to initialize
        //each memory segment allocated.

    }
