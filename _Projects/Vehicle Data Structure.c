#include <stdio.h>
#include <string.h>

// Define a structure to hold a car's details.
// This is a blueprint for a custom data type.
typedef struct car {
    char make[15];
    char model[15];
    int year;
    float miles;
} details;

int main(void)
{
    int x;

    // Declare an array of 3 'details' structs to store car information.
    details myCar[3];

    // Assign data to the first car struct.
    strcpy(myCar[0].make, "SUV");
    strcpy(myCar[0].model, "FORD F150");
    myCar[0].year = 2015;
    myCar[0].miles = 15000;

    // Assign data to the second car struct.
    strcpy(myCar[1].make, "EV");
    strcpy(myCar[1].model, "TESLA MODEL S");
    myCar[1].year = 2020;
    myCar[1].miles = 5000;

    // Assign data to the third car struct.
    strcpy(myCar[2].make, "LUXURY");
    strcpy(myCar[2].model, "LAMBORGHINI");
    myCar[2].year = 2022;
    myCar[2].miles = 2000;

    printf("\nCAR DETAILS\n");

    // Loop through the array and print the details of each car.
    for (x = 0; x < 3; x++) {
        printf("Make: %s\n", myCar[x].make);
        printf("Model: %s\n", myCar[x].model);
        printf("Year: %d\n", myCar[x].year);
        printf("Miles: %.2f miles\n", myCar[x].miles);
        printf("\n");
    }

    return 0;
}
