// Math Quiz Game

This section presents two versions of a Command-Line Interface (CLI) math quiz, highlighting the critical evolution from a basic, single-operation program using raw arrays to a professional, multi-functional application built with structures, enumerations, and robust input handling.

---

// Overview: Progressive Design

The comparison below demonstrates the progression of features and best practices implemented between the two versions.

| Feature Area | Math Quiz Game v1.c (Basic) | Math Quiz Game v2.c (Advanced Suite) |
| :--- | :--- | :--- |
| **Arithmetic Operations** | **Addition** only. | **Addition, Subtraction, and Multiplication** (controlled by an `enum`). |
| **Data Structure** | Separate dynamically allocated arrays for each piece of data (`op1`, `op2`, `answer`, `result`). | Single **`struct QuizProblem`** to encapsulate all data for a question (operands, operation, user/correct answers). |
| **Memory Management** | Dynamic allocation using `calloc()` based on user input, followed by `free()` cleanup. | Dynamic allocation using `calloc()` for an array of **structs**, managed by dedicated `allocate_quiz_memory()` and `free_quiz_memory()` functions. |
| **Modularity** | Single, linear execution logic within `main(void)`. | **Modular functions** for setup, quiz execution (`run_quiz`), and result display (`display_results`). |
| **Quiz Logic** | Operands are simple random numbers (0-99). | Includes logic to prevent negative results in **Subtraction** problems and uses smaller operands (0-9) for **Multiplication** problems. |
| **Input Validation** | Basic `scanf` for problem count; minimal error handling during quiz. | Dedicated logic (`while (getchar() != '\n')`) to **clear the input buffer** and validate the user's requested number of problems. |

---

// Programs Included

| File | Description | Technical Concepts Demonstrated |
| :--- | :--- | :--- |
| **Math Quiz Game v1.c** | A basic quiz that dynamically generates a user-defined number of **addition** problems. Results are scored and displayed using four separate dynamically allocated arrays. | **`calloc()`** for dynamic memory allocation, **`free()`** to prevent leaks, `rand() % 100`, Array indexing. |
| **Math Quiz Game v2.c** | A multi-operation quiz that uses a custom `struct` to organize data, an `enum` to select problem types, and functions to ensure modularity and robust input checking. | **`struct`** and **`enum`** usage, **Function Prototypes** (Modular Design), **Input Validation**, Safe subtraction logic, Formatted results table. |

---

// Key Implementations in Math Quiz Game v2.c

This version demonstrates advanced C features for cleaner, more maintainable code:

| Component | Purpose | Related Concepts |
| :--- | :--- | :--- |
| **`typedef enum { ... } Operation;`** | Defines the types of math problems (Addition, Subtraction, Multiplication) using readable names instead of magic numbers. | **Enumerations** for code clarity. |
| **`typedef struct { ... } QuizProblem;`** | Encapsulates all data related to a single question, making it easy to pass and manage problem sets. | **Structures** for data modeling. |
| **`allocate_quiz_memory()`** | Handles dynamic allocation and includes a critical check for `NULL` to prevent program crash if memory is unavailable. | **`calloc()`** and **Error Handling**. |
| **`run_quiz()`** | Contains logic to randomly select an operation and generate operands, ensuring logical constraints (e.g., non-negative subtraction results). | **`switch`** statements, Randomization, Defensive programming. |

---

// How to Compile and Run

The advanced version, `Math Quiz Game v2.c`, is the recommended demonstration:

```bash
# To compile the advanced game (Recommended)
gcc "Math Quiz Game v2.c" -o math_quiz_v2

# To run the advanced quiz
./math_quiz_v2