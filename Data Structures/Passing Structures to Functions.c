#include <stdio.h>
#include <string.h>

// Define a structure to hold employee data.
typedef struct employee {
    int id;
    float salary;
    char name[10];
} emp;

// Function prototype for passing a structure by reference (using a pointer).
void processEmp(emp *);

int main(void)
{
    // Create an instance of the 'emp' structure.
    emp emp1 = {0, 0, 0};

    // Create a pointer to the 'emp' structure and assign the address of emp1.
    emp *ptremp;
    ptremp = &emp1;

    // Pass the structure by reference. The function will modify the original data.
    processEmp(ptremp);

    // Print the modified data.
    printf("Name: %s\n", ptremp->name);
    printf("ID: %d\n", ptremp->id);
    printf("Salary: $%.2f\n", ptremp->salary);

    return 0;
}

// This function receives a pointer to a structure, allowing it to modify the original data.
// The '->' operator is used to access members through a pointer.
void processEmp(emp *e)
{
    strcpy(e->name, "Kelvin");
    e->id = 123;
    e->salary = 3000.00;
}
