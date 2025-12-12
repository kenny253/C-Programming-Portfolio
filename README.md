// C Programming Portfolio: A Deep Dive

Welcome to my C Programming Portfolio! This repository is a structured collection of programs demonstrating fundamental, intermediate, and advanced concepts in the C language, ranging from memory management and algorithms to file persistence and simple cryptography.

// Featured Project: CLI Secure Account Manager

The **CLI Secure Account Manager** (found in the `/Projects` folder) is my most complete application, showcasing proficiency in combining multiple core concepts—file I/O, user authentication, and basic security—into a single, functional, command-line application.


// Repository Structure: By Concept

This portfolio is organized into logical folders, each containing focused examples and projects related to a specific domain of C programming. Each folder contains its own dedicated `README.md` with detailed descriptions of the files within.

| Folder | Core Focus | Example Concepts |
| ---- | ---- | ---- |
| **Projects** | **Complete Applications** (CLI Bank, ATM Simulator, etc.) | Integration of multiple concepts into a single product. |
| **Pointers** | Memory addressing, indirection, and call-by-reference. | `&`, `*`, `const`, Pointer Arithmetic. |
| **Strings** | Character arrays and string manipulation. | `strlen`, `strcpy`, `strcat`, `ctype.h` functions. |
| **Arrays** | Static memory allocation and sequential data storage. | 1D/2D arrays, Array Traversal. |
| **Data Structures** | Custom data organization methods. | `struct`, `union`, basic Linked Lists. |
| **Basics and Algorithms** | Foundational logic and core language elements. | Loops, Conditionals, Data Types, Sorting Algorithms. |
| **Cryptography** | Implementation of simple ciphers for security demonstration. | Caesar Cipher. |
| **Dynamic Memory Allocation** | Allocating memory at runtime. | `malloc()`, `calloc()`, `realloc()`, `free()`. |
| **Manipulating File Input and Output** | Reading from and writing to local files. | `FILE *`, `fputc`, `fgetc`, `fprintf`, `fscanf`. |
| **Function Prototypes and Definitions** | Structuring programs with modular, reusable code. | Function declarations, parameter passing. |
| **Games** | Command-line games and simulations. | Randomization, Game loop logic. |

---

## Compilation and Execution

All programs in this portfolio are standard C files (`.c`) and can be compiled using the GNU Compiler Collection (GCC) on most operating systems (Linux, macOS, Windows via MinGW/WSL)..

To compile any project file, navigate to the respective folder and use the following command:

```bash
gcc "Project_File_Name.c" -o output_name
