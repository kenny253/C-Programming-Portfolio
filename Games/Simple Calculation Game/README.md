// Simple Calculation Game 

This project contains two distinct versions of a console-based arithmetic quiz program written in C. The goal of the application is to challenge and improve a user's mental math skills through randomized calculation problems.

---

// Version 1: Foundational Design

`Simple Calculation Game v1.c` is the initial version of the program, focusing on the fundamental implementation of a loop-based quiz system.

// Key Features of v1

- **Fixed Operation**: Exclusively generates multiplication problems.
- **Procedural Logic**: All game operations, including randomization, user input, and score tracking, are contained entirely within the `main` function.
- **Basic Randomization**: Generates operands between 0 and 9 to keep the difficulty consistent.
- **Session Scoring**: Tracks the total number of correct and incorrect answers for a single session and displays the final tally upon completion.

---

// Version 2: Modular & Feature-Rich

`Simple Calculation Game v2.c` represents a major technical upgrade, introducing complex data structures, file persistence, and modular software architecture.

// Key Features of v2

* **Modular Architecture**: The codebase is organized into specialized functions such as `run_quiz_session()`, `run_single_question()`, and `init_game()`, following professional software engineering practices.
**Expanded Operations**: Introduces an `enum` to handle multiple operations, including addition, subtraction (with non-negative result logic), and multiplication.
**Persistent High Scores**: Implements File I/O to save and retrieve the user's best score (`math_quiz_score.txt`), allowing for progress tracking across different play sessions.
**Defensive Programming**: Utilizes advanced input handling to clear the buffer (`while (getchar() != '\n');`), preventing program crashes from invalid non-numeric user input.
**Dynamic Feedback**: Provides real-time percentage-based scoring and recognizes when a new personal record is achieved.

---

// Technical Specifications

| Component | Implementation Details |
| :--- | :--- |
| **Language** | C (Standard C99/C11) |
| **Data Types** | Enumerations (v2) and standard integer/double types |
| **File Persistence** | Standard File I/O (fopen/fprintf) for high score tracking (v2) |
| **Randomization** | Seeded with `srand(time(NULL))` for diverse problem sets |

---

// Compilation and Usage

// Requirements
* A standard C compiler such as GCC.

// Compilation
To compile the modular version (v2), use the following command:
`gcc "Simple Calculation Game v2.c" -o math_quiz`

// Execution
Run the compiled executable:
`./math_quiz`

---

// Portfolio Note

This project illustrates my ability to evolve a simple utility into a complete application. The transition from Version 1 to Version 2 highlights my proficiency in **File I/O**, **Modular Design**, and the use of **Custom Data Types (Enums)**. These enhancements ensure the program is not only more functional for the user but also easier to maintain and extend for future development.
