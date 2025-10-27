// Cryptography in C

This section explores basic cryptography concepts implemented in the C programming language.  
It focuses on demonstrating how simple encryption and decryption techniques work, particularly through the **Caesar Cipher** one of the earliest and most well known encryption methods.



// About the Caesar Cipher

The Caesar Cipher is a type of **substitution cipher** where each letter in the plaintext is shifted by a fixed number of positions in the alphabet.  
For example, with a key of 3:
- 'A' becomes 'D'
- 'B' becomes 'E'
- 'Z' wraps around to 'C'

This cipher is named after **Julius Caesar**, who reportedly used it to encode military messages.  
Although easy to break by modern standards, it serves as an excellent introduction to cryptographic logic and string manipulation in programming.



// Program Included

| File | Description |
|------|--------------|
| **Simple Cryptography Using Caesar Cipher.c** | A program that encrypts and decrypts text using the Caesar Cipher. It takes a key (shift value) as input and applies it to transform the message. |



// Features Demonstrated
- String manipulation and ASCII character arithmetic  
- Modular arithmetic for wrapping characters (‘Z’ → ‘A’)  
- Command-line or user-input key handling  
- Understanding of encryption and decryption logic  
- Input validation and simple error handling



// How to Compile and Run

You can compile and run the Caesar Cipher program using GCC or any C compiler:

```bash
gcc "Simple Cryptography Using Caesar Cipher.c" -o caesar_cipher
./caesar_cipher
