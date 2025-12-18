// Memorization Challenge

This project contains two distinct versions of a console-based memory game written in C. The objective is to challenge the player's short-term memory by requiring them to recall a sequence of random numbers after a brief viewing period.

---

// Version 1: Foundational Design

`Memorization Challenge v1.c` serves as the initial implementation of the game logic, focusing on core mechanics through a procedural approach.

// Key Features of v1

- **Fixed Difficulty**: Challenges the user with a set sequence of 3 numbers between 0 and 99.
- **Procedural Design**: All core game logic, from random number generation to answer validation, is handled directly within the `main` function.
- **Time-Based Concentration**: Implements a 3-second delay using a `do-while` loop and the `time.h` library to control the memorization window.
- **Console Control**: Utilizes `system("cls")` to clear the screen after the delay to ensure the numbers are hidden during the recall phase.

---

// Version 2: Modular & Improved

`Memorization Challenge v2.c` represents a significant architectural evolution, transitioning from a single procedural script to a robust, function-oriented application.

// Key Features of v2

- **Modular Design**: The program logic is refactored into specialized, reusable functions such as `init_game()`, `get_game_length()`, `run_game()`, and `custom_sleep()`.
- **Difficulty Tiers**: Offers user-selectable difficulty levels: Easy (3 numbers), Medium (4 numbers), and Hard (5 numbers).
- **Array Management**: Utilizes arrays (`correct_sequence` and `user_response`) to handle the sequence dynamically based on the chosen difficulty.
- **Input Buffer Management**: Implements a clearing mechanism (`while (getchar() != '\n');`) to ensure stable input handling and prevent errors from residual characters.
- **Enhanced Portability**: Uses standard C libraries and custom timing functions to work across a wider range of environments without relying on OS-specific headers.

---

// Technical Specifications

| Component | Implementation Details |
| :--- | :--- |
| **Language** | C (Standard C99/C11) |
| **Randomization** | Seeded with `srand(time(NULL))` for unique sequences |
| **Data Structures** | Individual integer variables (v1) vs. Integer arrays (v2) |
| **User Interface** | Standard I/O with manual buffer clearing and screen refresh |

---

// Compilation and Usage

// Requirements
* A standard C compiler such as GCC.

// Compilation
To compile the modular version (v2), use the following command:
`gcc "Memorization Challenge v2.c" -o memorization_challenge`

// Execution
Run the compiled executable:
`./memorization_challenge`

---

// Portfolio Note

This project demonstrates a clear progression from basic procedural programming to advanced modular software design. By refactoring the initial codebase, I have showcased proficiency in functional decomposition, array iteration, and defensive programming techniques—skills that are essential for developing scalable and maintainable software.
