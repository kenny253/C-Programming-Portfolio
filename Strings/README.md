// String Manipulation & Utilities

A collection of focused C programs demonstrating proficiency in handling, processing, and modifying **null-terminated character arrays (strings)** using both standard library functions (`<string.h>`, `<ctype.h>`, `<stdlib.h>`) and custom algorithmic logic.


// Key Concepts Demonstrated

This repository section explores essential string operations critical for C development.

| File | Description | Concepts Demonstrated |
| ---- | ---- | ---- |
| **Finding String Length with strlen.c** | Demonstrates the fundamental operation of calculating the length of a null-terminated string using the standard C library function. | strlen(), Null termination. |
| **Copying Strings with strcpy.c** | Shows the proper and careful use of the `strcpy()` function to duplicate the contents of one string to a destination buffer. | **`strcpy()`,** Safe buffer handling, `string.h` library usage. |
| **String Addition with strcat.c** | Demonstrates string concatenation (appending one string to the end of another) using the standard C function. | **`strcat()`,** Buffer overflow risks, `string.h` library usage. |
| **Case Conversion of Strings.c** | Illustrates manual character-by-character iteration and modification to implement custom case conversion logic without relying entirely on `ctype.h`. | **Custom string processing**, ASCII values, `for` loops. |
| **String Manipulation to upper and lower.c** | Utilizes the powerful standard library functions to efficiently convert all characters in a string to uppercase or lowercase. | **`toupper()`, `tolower()`,** `ctype.h` library usage. |
| **Substring Search with strstr.c** | Locates the first occurrence of a specified substring within a larger string using the efficient standard library function. | **`strstr()`,** Pointer returns, String searching algorithms. |
| **Substrings with strstr.c** | A supplementary example or implementation focusing on identifying and extracting substrings, often using the results of `strstr()`. | Advanced usage of `strstr()` or manual search and extraction logic. |
| **Selection Sort on Strings.c** | Implements the **Selection Sort** algorithm to alphabetically sort an array of strings. | **Selection Sort**, **`strcmp()`** for string comparison, String swapping logic. |
| **String to Number Conversion.c** | Converts a string representation of a numerical value (e.g., "42", "3.14") into its native C data type equivalent (`int`, `float`). | **`atoi()`, `atof()`,** Input parsing, Data type conversion (`stdlib.h`). |
| **String Pointers and Memory.c** | Explicitly explores the relationship between pointers and strings, demonstrating how string literals and character arrays are stored and accessed in memory. | `char *` vs `char []`, Read-only memory for string literals. |


// Compilation and Execution

All programs can be compiled using the GNU Compiler Collection (GCC) on Linux, macOS, or Windows (via MinGW/WSL).

To compile a project:

// bash
gcc "Project_File_Name.c" -o output_name