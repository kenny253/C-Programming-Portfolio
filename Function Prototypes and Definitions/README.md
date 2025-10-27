// Function Prototypes and Definitions in C

This section focuses on how **functions** are defined, declared, and used in C programs.  
It demonstrates the role of function prototypes, return values, parameter passing, and the use of multiple functions for modular programming.


// What Are Functions in C?

A function in C is a block of code designed to perform a specific task.  
Functions improve code **organization**, **reusability**, and **readability** by dividing large programs into smaller, manageable parts.

Each function has:
- A **prototype**: declares the function’s name, return type, and parameters (so it can be used before being defined).  
- A **definition**: contains the actual code that runs when the function is called.  
- A **call**: the point in the program where the function is executed.


// Key Concepts Covered
- Writing and using function prototypes  
- Creating functions with and without return values  
- Passing arguments by value  
- Managing local and global variables  
- Organizing multi-function programs for clarity and scalability


// Programs Included

| File | Description |
|------|--------------|
| **Functions and Global Variables.c** | Demonstrates how functions can share and modify global variables. |
| **Functions with Return Values.c** | Shows how functions return computed results to the caller. |
| **Functions with Return Values 2.c** | Expands on function return handling with different data types. |
| **Functions with User Input.c** | Accepts user data through functions and processes it. |
| **Manipulating Multiple Functions.c** | Combines several functions to perform coordinated tasks. |
| **Prototypes and Definitions.c** | Introduces the concept of declaring functions before defining them. |
| **Prototypes and Definitions 2.c** | Reinforces the use of prototypes in structured, multi-function programs. |


// How to Compile and Run

Each program can be compiled individually with GCC or any C compiler:

```bash
gcc "Functions and Global Variables.c" -o globals
./globals
