# 🎯 ft_printf

A lightweight, custom implementation of the standard C `printf` function created as part of the 42 School curriculum. This project recreates the core functionality of formatted output while handling various conversion specifiers and edge cases.

[![C Language Badge](https://img.shields.io/badge/Language-C-blue?style=flat-square&logo=c)](https://en.cppreference.com/w/c)
[![42 School](https://img.shields.io/badge/School-42-000000?style=flat-square)](https://42.fr)
[![Norminette](https://img.shields.io/badge/Norminette-Compliant-brightgreen?style=flat-square)](https://github.com/42School/norminette)
[![License](https://img.shields.io/badge/License-MIT-green?style=flat-square)](LICENSE)
[![Status](https://img.shields.io/badge/Status-Complete-success?style=flat-square)]()

---

## 📚 Table of Contents

- [Overview](#overview)
- [What You'll Learn](#what-youll-learn)
- [Features](#features)
- [Supported Conversions](#supported-conversions)
- [How It Works](#how-it-works)
- [Code Examples](#code-examples)
- [Project Structure](#project-structure)
- [Installation & Compilation](#installation--compilation)
- [Error Handling](#error-handling)
- [Resources](#resources)

---

## Overview

`ft_printf` is a faithful recreation of the standard library `printf()` function. It parses a format string and processes variadic arguments, converting them according to specified format specifiers and writing the output to standard output (stdout).

**Key Characteristics:**
- Handles multiple format specifiers (`%c`, `%s`, `%d`, `%i`, `%u`, `%x`, `%X`, `%p`, `%%`)
- Returns the total number of characters printed (matching `printf` behavior)
- Manages memory efficiently with custom helper functions
- Fully compliant with 42 School Norminette standards
- Minimal dependencies (only standard POSIX functions)

---

## What You'll Learn

### 🧠 Core Concepts

**Variadic Functions**
Understanding how functions accept a variable number of arguments using `va_list`, `va_start()`, `va_arg()`, and `va_end()`. This is fundamental to implementing `printf`-like functions.

**Format String Parsing**
Learning to parse a format string character-by-character, identifying conversion specifiers (prefixed with `%`), and dispatching to appropriate handler functions based on the specifier type.

**Type Conversion**
Converting various data types (integers, unsigned integers, characters, strings, pointers) into their string representations for output.

**Hexadecimal & Pointer Representation**
Understanding how to work with different number bases (base 16 for hex) and properly formatting memory addresses with the `0x` prefix.

**Memory Management**
Safe allocation, deallocation, and usage of dynamically allocated memory. Avoiding memory leaks while handling edge cases like NULL pointers.

**Recursive Functions**
Using recursion elegantly in conversion functions to build numbers and hexadecimal strings digit-by-digit or hex-digit-by-hex-digit.

---

## Features

✅ **Complete Format String Support** — Parse and process format strings with conversion specifiers

✅ **Multiple Data Types** — Handle characters, strings, integers, unsigned integers, and pointers

✅ **Hexadecimal Conversion** — Convert integers to both lowercase and uppercase hexadecimal

✅ **Pointer Formatting** — Display memory addresses in standard `0x...` notation

✅ **Accurate Character Count** — Return the exact number of characters printed

✅ **Null-Safe** — Gracefully handle NULL pointers in strings and other edge cases

✅ **Norminette Compliant** — Follows 42 School coding standards

---

## Supported Conversions

| Specifier | Type | Description | Example |
|-----------|------|-------------|---------|
| `%c` | `int` | Single character | `ft_printf("%c", 'A')` → `A` |
| `%s` | `char*` | String (null-terminated) | `ft_printf("%s", "hello")` → `hello` |
| `%p` | `void*` | Pointer address (hex) | `ft_printf("%p", ptr)` → `0x7fff5fbff8c0` |
| `%d` | `int` | Signed decimal integer | `ft_printf("%d", -42)` → `-42` |
| `%i` | `int` | Signed decimal integer (same as `%d`) | `ft_printf("%i", 100)` → `100` |
| `%u` | `unsigned int` | Unsigned decimal integer | `ft_printf("%u", 42u)` → `42` |
| `%x` | `unsigned int` | Unsigned hex (lowercase) | `ft_printf("%x", 255)` → `ff` |
| `%X` | `unsigned int` | Unsigned hex (uppercase) | `ft_printf("%X", 255)` → `FF` |
| `%%` | — | Literal percent sign | `ft_printf("%%")` → `%` |

### Special Cases

- **NULL String** — `%s` with NULL pointer outputs `(null)`
- **NULL Pointer** — `%p` with NULL pointer outputs `(nil)`
- **Negative Numbers** — `%d` and `%i` correctly display the minus sign
- **Unsigned Overflow** — `%u` wraps around as per unsigned integer behavior

---

## How It Works

```
┌─────────────────────────────────────────────────────────────┐
│                    ft_printf(format, ...)                  │
└──────────────────────┬──────────────────────────────────────┘
                       │
                       ▼
        ┌──────────────────────────────┐
        │  Validate format string      │
        │  Initialize va_list          │
        └──────────────────────────────┘
                       │
                       ▼
        ┌──────────────────────────────┐
        │  Loop through each character │
        │  in format string            │
        └──────────────────────────────┘
                       │
        ┌──────────────┴──────────────┐
        │                             │
        ▼                             ▼
    [Regular Char]              [% Found]
        │                             │
        ▼                             ▼
    Write char              Get conversion specifier
    Increment count                 │
                    ┌────────────────┼────────────────┐
                    │                │                │
                    ▼                ▼                ▼
                [%c, %s]        [%d, %i, %u]    [%x, %X, %p]
                    │                │                │
                    ▼                ▼                ▼
              handle_conversion dispatches to appropriate
              helper function (ft_putchar, ft_putstr, etc.)
                    │                │                │
                    └────────────────┼────────────────┘
                                     │
                                     ▼
                    Update character count & continue
                                     │
                       ┌─────────────┴──────────────┐
                       │                            │
                  [More chars]                   [End]
                       │                            │
                       └──────────────┬─────────────┘
                                      ▼
                         ┌──────────────────────────┐
                         │  va_end(args)            │
                         │  Return total count      │
                         └──────────────────────────┘
```

### Core Flow

1. **Initialization** — Set up the variadic argument list and character counter
2. **String Parsing** — Iterate through the format string character by character
3. **Specifier Detection** — When `%` is encountered, peek at the next character (the conversion specifier)
4. **Dispatch** — Call the appropriate handler function based on the specifier type
5. **Argument Extraction** — Use `va_arg()` to get the next argument from the variadic list
6. **Output** — Write the formatted result to stdout and update the character count
7. **Finalization** — Clean up the variadic argument list and return the total character count

---

## Code Examples

### Basic Usage

```c
#include "ft_printf.h"

int main(void)
{
    int count;
    
    // Simple string and integer
    count = ft_printf("Hello, World!\n");
    // Output: Hello, World!
    // count = 14
    
    // Multiple specifiers
    ft_printf("Character: %c, String: %s, Number: %d\n", 'X', "test", 42);
    // Output: Character: X, String: test, Number: 42
    
    return (0);
}
```

### All Specifiers

```c
#include "ft_printf.h"

int main(void)
{
    char        *str = "42 School";
    int         num = -1337;
    unsigned int unum = 4294967295;
    void        *ptr = (void *)0x7fff5fbff8c0;
    
    ft_printf("String:        %s\n", str);
    // Output: String:        42 School
    
    ft_printf("Signed int:    %d or %i\n", num, num);
    // Output: Signed int:    -1337 or -1337
    
    ft_printf("Unsigned int:  %u\n", unum);
    // Output: Unsigned int:  4294967295
    
    ft_printf("Hex lowercase: %x\n", 255);
    // Output: Hex lowercase: ff
    
    ft_printf("Hex uppercase: %X\n", 255);
    // Output: Hex uppercase: FF
    
    ft_printf("Pointer:       %p\n", ptr);
    // Output: Pointer:       0x7fff5fbff8c0
    
    ft_printf("Percent:       %%\n");
    // Output: Percent:       %
    
    ft_printf("Character:     %c\n", 'A');
    // Output: Character:     A
    
    return (0);
}
```

### Edge Cases

```c
#include "ft_printf.h"

int main(void)
{
    // NULL string
    ft_printf("Null string: %s\n", NULL);
    // Output: Null string: (null)
    
    // NULL pointer
    ft_printf("Null pointer: %p\n", NULL);
    // Output: Null pointer: (nil)
    
    // Negative number with %u (wraps around)
    ft_printf("Negative as unsigned: %u\n", (unsigned int)-1);
    // Output: Negative as unsigned: 4294967295
    
    // Zero
    ft_printf("Zero as int: %d, as hex: %x\n", 0, 0);
    // Output: Zero as int: 0, as hex: 0
    
    return (0);
}
```

---

## Project Structure

```
ft_printf/
├── ft_printf.c          # Main function - format string parser
├── ft_printf.h          # Header file with function declarations
├── ft_putchar.c         # Output single character
├── ft_putstr.c          # Output null-terminated string
├── ft_putnbr.c          # Convert signed integer to string
├── ft_putunbr.c         # Convert unsigned integer to string
├── ft_puthexa.c         # Convert unsigned int to hexadecimal
├── ft_putaddr.c         # Format and output memory addresses
├── Makefile             # Build automation
└── README.md            # This file
```

### File Responsibilities

| File | Purpose |
|------|---------|
| `ft_printf.c` | Main entry point; parses format string and dispatches conversions |
| `ft_putchar.c` | Writes a single character to stdout |
| `ft_putstr.c` | Writes a string to stdout; handles NULL case |
| `ft_putnbr.c` | Recursively converts signed integers to decimal |
| `ft_putunbr.c` | Recursively converts unsigned integers to decimal |
| `ft_puthexa.c` | Recursively converts integers to hexadecimal (base 16) |
| `ft_putaddr.c` | Formats pointers with `0x` prefix and calls `ft_puthexa_ul` |

---

## Installation & Compilation

### Requirements

- GCC or Clang compiler
- `make` utility
- Standard C library (libc)

### Compilation

```bash
# Clone or download the project
cd ft_printf

# Compile the library
make

# This generates:
# - libftprintf.a (static library)
# - .o object files
```

### Clean Up

```bash
# Remove object files
make clean

# Remove object files and library
make fclean

# Clean and recompile
make re
```

### Using in Another Project

1. **Copy the library:**
   ```bash
   cp libftprintf.a /path/to/your/project/
   cp ft_printf.h /path/to/your/project/
   ```

2. **Include in your code:**
   ```c
   #include "ft_printf.h"
   ```

3. **Compile with the library:**
   ```bash
   gcc main.c -L. -lftprintf -o program
   ```

   Or add to your Makefile:
   ```makefile
   LIBS = -L./ft_printf -lftprintf
   gcc $(CFLAGS) main.c $(LIBS) -o program
   ```

---

## Error Handling

### Invalid Format String

```c
ft_printf(NULL)  // Returns -1
```

### Unterminated Conversion Specifier

```c
ft_printf("Hello %")  // Returns -1 (% at end of string)
```

### NULL Pointers

All functions gracefully handle NULL inputs:
- `%s` with NULL → outputs `(null)`
- `%p` with NULL → outputs `(nil)`

### Buffer Overflow Protection

The implementation uses `write()` system call for direct output, avoiding buffer overflow risks associated with fixed-size buffers.

---

## Resources

### Learning References

- [Man page: printf(3)](https://linux.die.net/man/3/printf) — Standard printf documentation
- [C Variadic Functions](https://en.cppreference.com/w/c/variadic) — cppreference guide to varargs
- [Printf Format Specifiers](https://cplusplus.com/reference/cstdio/printf/) — Complete format specifier reference
- [Hexadecimal Number System](https://en.wikipedia.org/wiki/Hexadecimal) — Understanding base-16 notation
- [42 School Norminette](https://github.com/42School/norminette) — Code style guidelines

### Helpful Topics

- **Recursion in C** — Understand how `ft_putnbr` and `ft_puthexa` work recursively
- **Memory Management** — Learn about `write()` and direct I/O vs buffered I/O
- **Type Casting** — Converting `void*` to `unsigned long` for pointer manipulation
- **Variadic Arguments** — How `va_list`, `va_start()`, `va_arg()`, and `va_end()` work together

### Similar Projects at 42

- **libft** — Core string and utility functions
- **get_next_line** — Buffered file reading
- **minitalk** — Signal-based IPC using similar concepts
- **philosopher** — Process management and synchronization

---

## Tips for Future Students

🎓 **Start Simple** — Implement `%c` and `%s` before tackling numeric conversions

🎓 **Test Incrementally** — Build and test each conversion specifier individually

🎓 **Handle Edge Cases** — Don't forget NULL pointers, negative numbers, and empty strings

🎓 **Use Printf for Debugging** — Once your ft_printf works, use it to debug other projects!

🎓 **Understand Recursion** — The recursive approach in numeric functions is elegant and teaches important concepts

🎓 **Study the Standard** — Compare your output with the real `printf()` to catch subtle differences

---

## Author

Created as part of the 42 School curriculum.

**Repository:** [Your GitHub Link]

**License:** MIT

---

**Last Updated:** November 2025 | **Status:** ✅ Complete & Functional
