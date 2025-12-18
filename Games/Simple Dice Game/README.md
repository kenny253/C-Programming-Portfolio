// Simple Dice Game (Console Craps)

This project contains two distinct versions of a console-based dice game written in C. The application simulates the excitement of rolling dice, progressing from a simple single-roll mechanic to a complex, multi-stage game of Craps.

---

// Version 1: Foundational Design

`Simple Dice Game v1.c` is the initial version of the program, focusing on the core mechanics of random number generation and basic conditional win logic.

// Key Features of v1

- **Core Mechanics**: Simulates a single roll of two six-sided dice using the `rand()` function.
- **Procedural Logic**: The entire game sequence—initialization, user input, calculation, and win/loss determination—is executed within a single `main` function.
- **Randomized Outcomes**: Utilizes `srand(time(NULL))` to ensure that every execution results in a unique sequence of dice rolls.
- **Simplified Win Conditions**: Features a direct win/loss check based on the sum of the dice (6 or 12 for a win).

---

// Version 2: Modular & Multi-Stage Logic

`Simple Dice Game v2.c` represents a significant technical advancement, introducing modular architecture and a two-stage "Craps" rule system.

// Key Features of v2

- **Modular Architecture**: The code is organized into specialized functions such as `roll_dice()`, `display_roll()`, and `run_game_session()`, promoting clean and maintainable code.
- **Advanced Game States**: Implements a multi-stage logic system. Stage 1 (Come-out roll) determines an instant win/loss or establishes a "Point," while Stage 2 requires the player to match that Point before rolling a 7.
- **Pointer Implementation**: Utilizes pointers in the `roll_dice` function to return multiple values (the individual results of two dice) simultaneously.
- **Continuous Gameplay**: Includes a `do-while` loop in the `main` entry point, allowing users to play multiple rounds in a single session.
- **Defensive Input Handling**: Employs an input buffer clearing mechanism (`while (getchar() != '\n');`) to ensure the game doesn't crash from unexpected user input.

---

// Technical Specifications

| Component | Implementation Details |
| :--- | :--- |
| **Language** | C (Standard C99/C11) |
| **Randomization** | Seeded with `srand((unsigned int)time(NULL))` for non-repeating results |
| **Data Management** | Pointers used for memory-efficient value passing (v2) |
| **Logic Flow** | Boolean flags (`stdbool.h`) used to control multi-stage game states (v2) |

---

// Compilation and Usage

// Requirements
A standard C compiler such as GCC.

// Compilation
To compile the modular version (v2), use the following command:
`gcc "Simple Dice Game v2.c" -o dice_game`

// Execution
Run the compiled executable:
`./dice_game`

---

// Portfolio Note

This project demonstrates my ability to transition from a basic script to a robust, modular application. The evolution of the Dice Game highlights my mastery of **functional decomposition**, **pointer manipulation**, and the management of **complex state machines**. By implementing the multi-stage rules of Craps, I have shown the ability to translate detailed real-world rules into logical, bug-resistant code.
