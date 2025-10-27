// Dynamic Memory Allocation in C

This section demonstrates how to work with **dynamic memory** in C using functions like `malloc()`, `calloc()`, and `realloc()`.  
Dynamic memory allocation allows a program to request and manage memory while it is running, making it possible to handle variable amounts of data efficiently.


// What Is Dynamic Memory Allocation?

Unlike static memory allocation, where memory size is fixed at compile time, dynamic memory is allocated during runtime.  
This gives programs the flexibility to:
- Create and resize arrays or structures as needed  
- Handle large or unknown amounts of input data  
- Optimize memory usage by freeing unused memory with `free()`

Key functions used:
- `malloc()` — Allocates a specific number of bytes.  
- `calloc()` — Allocates and clears memory for multiple elements.  
- `realloc()` — Resizes previously allocated memory.  
- `free()` — Releases memory once it is no longer needed.


// Programs Included

| File | Description |
|------|--------------|
| **Character counting using calloc.c** | Uses `calloc()` to dynamically count and store characters efficiently. |
| **Dynamic Memory Resizing with realloc.c** | Demonstrates how to expand memory blocks dynamically using `realloc()`. |
| **Dynamic Movie title converter using malloc.c** | Allocates memory with `malloc()` to handle user-defined movie titles of any length. |


// Key Concepts Practiced
- Understanding the purpose of the heap in memory management  
- Using `malloc()`, `calloc()`, and `realloc()` correctly  
- Preventing memory leaks by freeing memory  
- Handling user input dynamically without predefined limits  
- Working safely with pointers and allocated blocks


// How to Compile and Run

Each file can be compiled and executed separately in a terminal:

```bash
gcc "Character counting using calloc.c" -o char_count
./char_count
