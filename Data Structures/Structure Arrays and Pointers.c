#include <stdio.h>
#include <string.h>

// Define a structure for employee data.
typedef struct employee {
    int id;
    float salary;
    char name[20];
} e;

// Function prototype to process an array of structures.
// The array name is a pointer to the first element.
void processEmp(e *);

int main(void)
{
    // Create an array of 3 'e' structures.
    e emp1[3] = {0};
    int x;

    // Pass the array to the function.
    processEmp(emp1);

    // Loop through the array and print the modified contents.
    for (x = 0; x < 3; x++) {
        printf("Name: %s\n", emp1[x].name);
        printf("ID: %d\n", emp1[x].id);
        printf("Salary: $%.2f\n", emp1[x].salary);
    }

    return 0;
}

// This function receives a pointer to the first element of the array.
// It can then access and modify the data in the array.
void processEmp(e *emp)
{
    emp[0].id = 123;
    strcpy(emp[0].name, "Sheila");
    emp[0].salary = 65000.00;

    emp[1].id = 234;
    strcpy(emp[1].name, "Hunter");
    emp[1].salary = 28000.00;

    emp[2].id = 456;
    strcpy(emp[2].name, "Kenya");
    emp[2].salary = 48000.00;
}
