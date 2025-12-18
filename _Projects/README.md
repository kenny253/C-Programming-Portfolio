// Projects In C

A collection of **Command-Line Interface (CLI)** applications developed in C to demonstrate core programming concepts, including data structures, file input/output (I/O) for data persistence, basic algorithm implementation (like the Caesar Cipher), and user interaction.


// Featured Project: CLI Secure Account Manager

This project serves as the highlight of the portfolio, demonstrating robust **File I/O** and practical security concepts within a functional application.

| Feature | Description | Concepts Demonstrated |
| ---- | ---- | ---- |
| **User Authentication** | Allows users to create a single account and log in. | strcmp(), fgets(), input sanitization, program state management. |
| **Data Persistence** | Account credentials and balance are stored in a file (Bank.dat). | fopen(), fprintf(), fscanf(), UpdateAcc() function logic. |
| **Basic Security** | User passwords are **encrypted** using a **Caesar Cipher** (shift = x) before being written to the file. | **Caesar Cipher algorithm**, modulo arithmetic, `ctype.h` functions (`isupper`, `islower`). |
| **Banking Operations** | Users can check balance, deposit, withdraw funds, and reset the password. | Conditional logic, error handling (e.g., checking for insufficient funds). |


// Projects Overview

This repository showcases projects focusing on data handling and simulation in a CLI environment.

// Data Management & File I/O
These projects demonstrate reading, writing, and manipulating structured data stored in local files.

| File | Description | Concepts Demonstrated |
| ---- | ---- | ---- |
| **CLI-Secure-Account-Manager.c** | **(Featured)** A full banking simulator emphasizing file persistence and basic password encryption (Caesar Cipher). | File I/O, Encryption, Global State. |
| **Simple ATM Simulator.c** | A basic banking interface focusing purely on transactions and balance logic. | switch statements, arithmetic operations. |
| **Name Record Program.c** | Manages a list of names. | switch statements, do while loops. |
| **Simple Phonebook.c** | A foundational contact management tool (add). | Structures (struct), string operations. |
| **Phonebook Program v2.c** | An improved version of the phonebook, potentially adding features like modification/deletion or better I/O. | Advanced File Handling. |
| **Vehicle Data Structure.c** | Demonstrates defining and using a custom C `struct` to model complex real-world data (e.g., car make, model, year). | `struct` definition, Data Modeling. |

### Simulators & Algorithms
These projects focus on randomness, mathematical calculations, and game logic implementation.

| File | Description | Concepts Demonstrated |
| ---- | ---- | ---- |
| **Dice Rolling.c** | A simple program to simulate rolling one or more dice. | **`rand()`, `srand()`**, `time.h`, basic loops and conditional output. |
| **Deck Cards Simulator.c** | Simulates a deck of cards, Including shuffling and dealing. | Arrays, Randomization algorithms. |
| **Student GPA Calculator.c** | Calculates a student's Grade Point Average based on inputted grades and credits. | Floating-point arithmetic, Loops, User input validation. |


## Compilation and Execution

All programs can be compiled using the GNU Compiler Collection (GCC) on Linux, macOS, or Windows (via MinGW/WSL).

To compile a project:

// bash
gcc "Project_File_Name.c" -o output_name
