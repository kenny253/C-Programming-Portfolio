// Word Search Game (Pattern Recognition)

This project contains two distinct versions of a console-based word search game written in C. The application challenges the user to identify and memorize hidden words within a randomized character grid before the display is cleared.

---

// Version 1: Foundational Design

`Word Search Game v1.c` establishes the core mechanics of the challenge, focusing on timed visibility and substring validation.

// Key Features of v1

- **Core Gameplay**: Displays a 2D array of character strings (grids) for a fixed duration of 3 seconds.
- **Timed Display**: Utilizes a `while` loop with `time.h` to manage the concentration window before clearing the console.
- **Input Validation**: Employs the `strstr()` function to check if the user's input exists within the specific character grid.
- **Normalization**: Automatically converts user input to uppercase using `toupper()` to ensure comparisons are case-insensitive.
- **Basic Sequential Flow**: Iterates through a fixed set of 5 puzzles in a linear progression.

---

// Version 2: Modular & Data-Driven Architecture

`Word Search Game v2.c` represents a significant technical upgrade, introducing structured data, dynamic difficulty levels, and improved memory safety.

// Key Features of v2

- **Struct-Based Puzzle Database**: Replaces simple string arrays with a `Puzzle` struct that pairs character grids with specific target words for more precise validation.
- **Dynamic Difficulty Levels**: Features a main menu where users can choose between Easy (6s), Medium (4s), and Hard (2s) time limits.
- **Modular Software Design**: The application logic is decomposed into specialized functions such as `display_menu()`, `run_game()`, and `normalize_input()`.
- **Enhanced Memory Safety**: Replaces the unsafe `gets()` function with safer input handling and explicit buffer management to prevent overflows.
- **Randomized Challenge**: Uses `rand()` to select puzzles from a larger database, ensuring a unique experience across different game sessions.
- **Interactive Scoring**: Provides real-time feedback with current score tallies and a final performance summary upon completion.

---

// Technical Specifications

| Component | Implementation Details |
| :--- | :--- |
| **Language** | C (Standard C99/C11) |
| **Data Architecture** | 2D Pointer Arrays (v1) vs. Struct-based Arrays (v2) |
| **Timing Logic** | Epoch time comparison using `time_t` and `time(NULL)` |
| **Input Safety** | Buffer-safe normalization and newline stripping |
| **String Logic** | Pointer-based substring searching and character mapping |

---

// Compilation and Usage

// Requirements
A standard C compiler such as GCC.

// Compilation
To compile the advanced version (v2), use the following command:
`gcc "Word Search Game v2.c" -o word_search`

// Execution
Run the compiled executable:
`./word_search`

---

// Portfolio Note

This project demonstrates my ability to take a simple concept and apply professional software engineering principles to create a scalable application. The transition to Version 2 highlights my mastery of **C Structures**, **Defensive Programming**, and **User Experience (UX) Design**. By implementing varied difficulty tiers and modularizing the code, I have shown that I can write software that is both highly functional and easy to maintain.