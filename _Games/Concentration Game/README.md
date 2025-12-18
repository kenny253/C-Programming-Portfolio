// Concentration Game (Number Recall)

This folder contains two distinct versions of a simple console-based memory game written in C. The goal of the game is for the player to memorize a sequence of random numbers displayed for a short period and then correctly recall them.

// Concentration Game v1 (Concentration Game v1.c)

This is the initial, foundational version of the game. It is designed to be straightforward but has platform-specific dependencies.

// Key Features of v1

Difficulty Tiers: Offers three fixed difficulty levels:

- **Easy**: 3 digits in 5 seconds

- **Intermediate**: 5 digits in 5 seconds

- **Hard**: 5 digits in 2 seconds

| DESIGN | FUNCTION |
|------|--------------| 
| Procedural Design |  All core game logic and level implementation are handled directly within the main function using nested switch and while statements. |
| **Platform Dependency** | This version utilizes the Windows-specific Sleep() function from the <windows.h> library for time delays, making it less portable to Linux or macOS without modification. |
| **Score Tracking** | Tracks correct and incorrect answers across rounds. |

// Compilation Notes (v1)

This file requires a compiler environment that supports the <windows.h> header for the Sleep() function.

// Concentration Game v2 (Concentration Game v2.c)

This version represents an improvement in modularity, portability, and robust input handling over the first version.

// Key Features of v2

|------|-------------|
| **Modular Design** | The game logic is cleanly separated into reusable functions |
| **delay(milliseconds)** | Implements a platform-independent delay using clock() from <time.h>. |
| **clear_screen()** | Clears the console screen (using system("cls") or system("clear")). |
| **clear_input_buffer()** | Ensures stable input handling by clearing residual characters from the input buffer. |
| **play_level(digits, seconds)** | A generalized function to run any game level based on the digits and time specified. |
| **Improved Portability** | By using clock() for the delay, the program is more standard and works across a wider range of C environments without needing specific OS headers like <windows.h>. |
| **Centralized Control Flow** | Uses the goto statement to provide a clear, single exit point (end_game) from the main game loop for final score display. |

// Compilation Notes (v2)

This file relies on standard C libraries and should compile and run successfully using most modern C compilers (e.g., GCC).