// Guessing Game

This section focuses on two versions of a Command-Line Interface (CLI) guessing game, demonstrating the progression from a simple, single-function program to a complex, modular application featuring persistent data storage and robust input validation.

---

// Overview: Design and Concepts

These programs illustrate key development concepts in C, specifically showcasing an increase in complexity and best practices from V1 to V2.

| Concept | Guessing Game v1.c (Basic) | Guessing Game v2.c (Advanced Suite) |
| :--- | :--- | :--- |
| **Structure** | Linear logic within the single `main(void)` function. | Modular design utilizing multiple **Function Prototypes** for I/O, scoring, and game logic. |
| **Input Handling** | Basic `scanf` usage. | Advanced input handling with `get_integer_input()` and `clear_input_buffer()` to prevent errors on non-numeric input. |
| **Game Features** | Single difficulty (1-10 range) and no attempt limit (single guess). | **Three Difficulty Levels** (Easy, Medium, Hard) with defined ranges (1-10, 1-50, 1-100) and attempt limits. |
| **Data Persistence** | None (game resets completely after each run). | **File I/O** is used to load and save the user's highest score to a designated file (`highscore.txt`). |
| **Utility** | Includes a simple character-to-digit check using `isdigit()`. | Includes a dedicated **Character Analyzer Utility** that checks for digit, uppercase letter, lowercase letter, or symbol. |

---

// Programs Included

| File | Description | Technical Concepts Demonstrated |
| :--- | :--- | :--- |
| **Guessing Game v1.c** | A foundational program that combines a simple character validation check and a single-guess number guessing game (range 1-10). | **`rand() % 10`** for range generation, `time(NULL)` for seeding, **`isdigit()`** from `<ctype.h>`. |
| **Guessing Game v2.c** | A full console suite featuring a main menu, multi-difficulty guessing game, score calculation, and a character analysis utility. | **Modular Functions**, **File I/O** (`fopen`, `fscanf`, `fprintf`), **Input Buffer Clearing** (`clear_input_buffer`), **Conditional Scoring** and High Score logic. |

---

// Key Functions in Guessing Game v2.c

This file is a strong example of applying modularity and robust error checking in C:

| Function | Purpose | Related Concepts |
| :--- | :--- | :--- |
| **`clear_input_buffer()`** | Ensures that residual characters (like the newline) from `scanf` do not interfere with subsequent inputs, preventing infinite loops. | Input Sanitization, `getchar()` loop control. |
| **`get_integer_input()`** | Handles user input and loops until a valid integer is provided, improving program stability. | **Error Handling**, `scanf` return value checking. |
| **`load_high_score()`** | Reads the saved high score from `highscore.txt` and handles cases where the file does not exist or is empty. | **`fopen(..., "r")`**, `fscanf()`, Null checks (`file != NULL`). |
| **`run_char_check()`** | Provides a dedicated utility to analyze a character input, reporting if it is a digit, uppercase letter, lowercase letter, or symbol. | **`isdigit()`, `isalpha()`, `isupper()`** from `<ctype.h>`. |
| **`run_guessing_game()`** | Contains the core game logic, including difficulty setup, attempt tracking, and providing **"HIGHER/LOWER"** hints to the player. | **`switch`** statements, **`do-while`** loop, Conditional feedback. |

---

// How to Compile and Run

Each game can be compiled using GCC or any C compiler:

```bash
# To compile the advanced game (Recommended)
gcc "Guessing Game v2.c" -o guessing_game_v2

# To run the advanced game
./guessing_game_v2