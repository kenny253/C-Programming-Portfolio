// Manipulating File Input and Output in C

This section demonstrates how to read from, write to, and manage data files in the C programming language.  
File Input/Output (I/O) is an essential part of real-world programming, allowing data to be stored permanently and retrieved when needed.


// Overview

In C, file I/O is handled through functions like:
- **fopen()** – opens a file for reading, writing, or appending  
- **fprintf()** and **fscanf()** – write and read formatted data  
- **fgets()** and **fputs()** – handle string-based file operations  
- **fclose()** – closes the file and ensures data is saved  

These programs explore how to:
- Create and open files
- Write and append data to files
- Read and display stored records
- Manage structured data such as student records or contact lists


// Programs Included

| File | Description |
|------|--------------|
| **Appending information to a file.c** | Demonstrates how to open an existing file in append mode and add new entries without deleting previous data. |
| **File IO for Student Data (Writing and Reading).c** | Shows how to record student details (name, ID, GPA) and read them back from a data file for display. |
| **Phonebook manager Using File IO.c** | Implements a simple phonebook that allows adding, viewing, modifying, and deleting contacts stored in a file. |
| **Reading the Data of a File Using IO.c** | Introduces reading data from a text file line by line using `fscanf()` and displaying it on screen. |
| **Reading the Data of a File Using IO v2.c** | An improved version that adds better error handling and a cleaner output format. |


// How to Compile and Run

Each program can be compiled and executed using a C compiler such as GCC:

```bash
gcc "File IO for Student Data (Writing and Reading).c" -o student_data
./student_data
