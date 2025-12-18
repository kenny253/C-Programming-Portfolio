// Trivia Game (Categorized Quiz System)

This project contains two distinct versions of a console-based trivia game written in C. The application challenges the user’s knowledge across various subjects, evolving from a simple hard-coded script to a sophisticated system utilizing advanced data structures.

---

// Version 1: Foundational Design

`Trivia Game v1.c` is the initial implementation of the quiz, focusing on the basic mechanics of user selection and scoring.

// Key Features of v1

- **Category Selection**: Allows users to choose between Sports, Geography, and Science categories using a standard switch-case menu.
- **Global State Management**: Utilizes global variables to track "correct" and "incorrect" scores across different function calls.
- **Procedural Functionality**: Each category is handled by a dedicated function (e.g., `sportquestions`) containing hard-coded questions and answers.
- **Platform-Specific Commands**: Employs Windows-specific headers like `<windows.h>` for screen clearing (`system("cls")`) and execution pauses (`Sleep`).

---

// Version 2: Advanced Data Structures & Modular Logic

`Trivia Game v2.c` represents a complete architectural overhaul, moving away from hard-coded functions toward a data-driven design.

// Key Features of v2

- **Struct-Based Database**: Implements a `Question` struct to store categories, question text, multiple-choice options, and correct indices in a centralized database array.
- **Modular Quiz Engine**: Features a generalized `run_category_quiz` function that dynamically filters and displays questions based on the user's selected category.
- **Robust Input Handling**: Includes a `clear_input_buffer` utility to prevent menu skipping and handle invalid non-numeric inputs gracefully.
- **Dynamic Results Display**: Replaces static functions with a unified logic flow that calculates scores and displays final totals upon exiting.
- **Scalability**: The database-driven approach allows for new questions or categories to be added simply by updating the array, without writing new functions.

---

// Technical Specifications

| Component | Implementation Details |
| :--- | :--- |
| **Language** | C (Standard C99/C11) |
| **Data Architecture** | Hard-coded functions (v1) vs. Struct-based arrays (v2) |
| **User Interface** | Console-based menu with input validation |
| **Memory Management** | Use of constants for fixed-length strings and database size |

---

// Compilation and Usage

// Requirements
A standard C compiler (e.g., GCC) and a Windows environment (for `<windows.h>` support).

// Compilation
To compile the advanced version (v2), use the following command:
`gcc "Trivia Game v2.c" -o trivia_game`

// Execution
Run the compiled executable:
`./trivia_game`

---

// Portfolio Note

This project highlights my ability to transition a software tool from a basic procedural script to a professional, data-driven application. The evolution from Version 1 to Version 2 demonstrates my proficiency with **C Structures (structs)**, **array filtering logic**, and **defensive programming**. By centralizing the data, I showcased an understanding of how to build maintainable and scalable software systems.