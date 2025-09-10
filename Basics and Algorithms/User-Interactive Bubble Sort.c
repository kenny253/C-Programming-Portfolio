#include <stdio.h>

int main(void)
{
    int value[10];
    int x, y;
    int resp;
    int temp;

    printf("Enter 10 values to store in the array.\n");
    for (x = 0; x < 10; x++) {
        printf("Enter value number %d: ", x + 1);
        scanf("%d", &value[x]);
    }

    printf("1\t Ascending\n");
    printf("2\t Descending\n");
    printf("In what order do you want to display the Arrays [1 - 2]: ");
    scanf("%d", &resp);

    // ASCENDING ORDER
    for (x = 0; x < 10 - 1; x++) {
        for (y = 0; y < 10 - 1 - x; y++) {
            if (resp == 1 && value[y] > value[y + 1]) {
                temp = value[y];
                value[y] = value[y + 1];
                value[y + 1] = temp;
            }
        }
    }

    if (resp == 1) {
        printf("The sorted values in ascending order are:\n");
        for (x = 0; x < 10; x++)
            printf("%d ", value[x]);
    }

    // DESCENDING ORDER
    for (x = 0; x < 10 - 1; x++) {
        for (y = 0; y < 10 - 1 - x; y++) {
            if (resp == 2 && value[y] < value[y + 1]) {
                temp = value[y];
                value[y] = value[y + 1];
                value[y + 1] = temp;
            }
        }
    }

    if (resp == 2) {
        printf("The sorted values in descending order are:\n");
        for (x = 0; x < 10; x++)
            printf("%d ", value[x]);
    }

    return 0;
}
