// Pointers

A series of focused C programs demonstrating the fundamental concepts and advanced applications of **Pointers** in C, covering memory access, array manipulation, function arguments, and type safety.


// Pointers Concepts Overview

This collection showcases a detailed exploration of how pointers operate at the memory level in C.

| File | Description | Concepts Demonstrated |
| ---- | ---- | ---- |
| **Basic Pointer Operation.c** | Illustrates the core concepts of declaring and initializing a pointer, using the address-of operator (&) and the indirection operator (`*`). | Address-of operator (&), Indirection operator (*), Pointer declaration syntax. |
| **Pointers and Indirection.c** | Focuses on using the indirection operator (`*`) to read and, crucially, modify the value of a variable via its pointer. | **Dereferencing**, L-values vs. R-values in pointer context. |
| **Passing Arguments by Reference.c** | Shows how to use pointers to implement **Call-by-Reference**, allowing a function to modify the value of a variable declared in the calling scope. | **Call-by-Reference** implementation, Function prototypes using pointer parameters. |
| **Pointers and Arrays.c** | Explores the intrinsic relationship between array names and pointers, including array traversal and element access using **pointer arithmetic**. | Pointer Arithmetic. |
| **Array of String Pointers.c** | Demonstrates how to create an array where each element is a pointer (char *) that points to the beginning of a separate string literal. | Pointer-to-char (char *), Managing a list of variable-length strings efficiently. |
| **Pointers with Different Data Types.c** | Illustrates how pointers handle different memory sizes (int, char, float) and the difference in pointer arithmetic across types. | Type casting for pointers, Memory alignment. |
| **Read-only Arguments with const.c** | Demonstrates the use of the `const` keyword with pointers to guarantee that a function cannot modify the data being pointed to, enhancing **type safety** and preventing side effects. | const keyword, Type safety, Preventing unintentional modification of memory. |


// Compilation and Execution

All programs can be compiled using the GNU Compiler Collection (GCC) on Linux, macOS, or Windows (via MinGW/WSL).

To compile a project:

// bash
gcc "Project_File_Name.c" -o output_name