#include <stdio.h>

// Define a union. All members share the same memory space.
// Only one member can be used at a time.
union phonebook {
    char *name;
    char *number;
    char *address;
};

// Define a structure. Each member gets its own separate memory space.
struct magazine {
    char *name;
    char *author;
    int isbn;
};

int main(void)
{
    // Create instances of the union and structure.
    union phonebook aBook;
    struct magazine aMagazine;

    printf("\nUnion Details\n");
    // All members of the union point to the same memory address,
    // demonstrating that they share a single memory block.
    printf("Address for aBook.name: %p\n", &aBook.name);
    printf("Address for aBook.number: %p\n", &aBook.number);
    printf("Address for aBook.address: %p\n", &aBook.address);

    printf("\nStructure Details\n");
    // Each member of the structure has a unique memory address,
    // showing that they are stored independently.
    printf("Address for aMagazine.name: %p\n", &aMagazine.name);
    printf("Address for aMagazine.author: %p\n", &aMagazine.author);
    printf("Address for aMagazine.isbn: %p\n", &aMagazine.isbn);

    return 0;
}
