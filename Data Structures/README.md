// Data Structures in C

This section focuses on understanding and implementing **data structures** using the C programming language.  
It explores how to organize, store, and manipulate related data efficiently through the use of **structures**, **unions**, and **pointers** all of which are foundational concepts in software design.



// What Are Data Structures?

A **data structure** is a way of organizing and storing data so it can be accessed and modified efficiently.  
In C, the most common ways to structure data include:
- **Structures (struct)** — to group variables of different types under a single name.  
- **Unions (union)** — to store different data types in the same memory space.  
- **Arrays of Structures** — to represent collections of related records (like a list of students or employees).  
- **Pointers to Structures** — to work dynamically with data in memory.

These techniques are widely used in applications such as databases, file systems, and embedded systems.



// Programs Included

| File | Description |
|------|--------------|
| **Structure Fundamentals.c** | Introduces the concept of structures, showing how to define and initialize them. |
| **'typedef' with Structures.c** | Demonstrates how `typedef` simplifies structure declarations and improves code readability. |
| **Passing Structures to Functions.c** | Shows how to pass entire structures or pointers to structures as function arguments. |
| **Structure Arrays and Pointers.c** | Explains how to use arrays of structures and access them through pointers. |
| **Union and Struct Demo.c** | Compares the behavior of unions and structures, highlighting how memory is shared in a union. |



// Key Concepts Practiced
- Defining and initializing `struct` and `union` types  
- Using `typedef` to create simpler, readable structure names  
- Passing structures by value and by reference  
- Managing arrays of structures for storing multiple records  
- Understanding memory usage differences between `struct` and `union`  
- Working with pointers to access and modify structure data



// How to Compile and Run

Use a terminal or command prompt to compile any of the programs in this folder.  
For example:

```bash
gcc "Structure Fundamentals.c" -o structure_fundamentals
./structure_fundamentals
