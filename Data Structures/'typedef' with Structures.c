#include <stdio.h>
#include <string.h>

// Use 'typedef' to create an alias 'employee' for the structure.
typedef struct employee {
    char fname[10];
    char lname[10];
    int id;
    float salary;
} employee; // Now 'employee' can be used instead of 'struct employee'.

int main(void)
{
    // Create an instance of the employee structure using the new 'employee' alias.
    employee emp1 = {0, 0, 0, 0};

    // Assign values to the structure members.
    strcpy(emp1.fname, "Michael");
    strcpy(emp1.lname, "Vine");
    emp1.id = 123;
    emp1.salary = 50000.00;

    // Print the member contents to demonstrate the stored values.
    printf("\nFirst Name: %s\n", emp1.fname);
    printf("Last Name: %s\n", emp1.lname);
    printf("Employee ID: %d\n", emp1.id);
    printf("Salary: $%.2f\n", emp1.salary);

    return 0;
}
