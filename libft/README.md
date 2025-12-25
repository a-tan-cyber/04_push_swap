*This project has been created as part of the 42 curriculum by amtan.*

# Libft

## Description

Libft is a custom C library that re-implements a subset of the standard C library and adds a few extra utilities.
The goal of the project is to:

* Understand how low-level string, memory and list utilities actually work.
* Build a reusable static library (`libft.a`) that can be linked into future 42 projects instead of using the system libc directly.
* Practise writing clean, Norm-compliant C code and managing a small codebase with a Makefile.

At the end of the project you obtain a personal “standard library” that you will keep extending and reusing throughout the rest of the cursus.

---

## Library Overview

Libft is delivered as a static library:

* **Library name:** `libft.a`
* **Public header:** `libft.h`
* **Language:** C (compiled with `cc` and flags `-Wall -Wextra -Werror`)
* **Style:** 42 Norm

Functions are grouped into several parts.

### Libc re-implementations

These functions mirror the behaviour and prototypes of the corresponding C standard library functions (but are all prefixed with `ft_`):

* **Character classification & case:**

  * `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`
    → Return `1` if the character matches the predicate, `0` otherwise.
  * `ft_toupper`, `ft_tolower`
    → Convert characters between upper and lower case.
* **String length & copy/concatenation:**

  * `ft_strlen` — Compute the length of a C string (excluding the null terminator).
  * `ft_strlcpy`, `ft_strlcat` — Bounded copy/concatenate functions that always NUL-terminate when the buffer size is non-zero.
* **Raw memory operations:**

  * `ft_memset` — Fill a memory area with a byte value.
  * `ft_bzero` — Set a memory area to zero.
  * `ft_memcpy` — Copy `n` bytes from one memory area to another (no overlap).
  * `ft_memmove` — Safe copy that correctly handles overlapping regions.
* **Searching & comparison:**

  * `ft_strchr`, `ft_strrchr` — Find the first/last occurrence of a character in a string.
  * `ft_strncmp` — Compare up to `n` characters of two strings.
  * `ft_memchr` — Find a byte in a memory area.
  * `ft_memcmp` — Compare two memory areas.
  * `ft_strnstr` — Locate a substring inside a string, with a maximum search length.
* **Conversion:**

  * `ft_atoi` — Convert a C string to an `int`.
* **Allocation helpers:**

  * `ft_calloc` — Allocate zero-initialised memory for an array.
  * `ft_strdup` — Duplicate a C string into newly allocated memory.

### Additional string & I/O helpers

These higher-level utilities are not direct clones of libc functions, but are extremely useful in later projects:

* `ft_substr` — Create a substring from a given string, starting at index `start` and at most `len` characters long.
* `ft_strjoin` — Allocate and return a new string which is the concatenation of `s1` and `s2`.
* `ft_strtrim` — Trim all characters in `set` from the beginning and end of string `s1`.
* `ft_split` — Split a string `s` into an array of substrings separated by a delimiter character `c`. The array is terminated by a `NULL` pointer.
* `ft_itoa` — Convert an integer `n` to its string representation (including handling negative numbers).
* `ft_strmapi` — Map a function `f(index, char)` over each character of a string and return a newly allocated result string.
* `ft_striteri` — Apply a function `f(index, &char)` to each character of a string in-place.
* `ft_putchar_fd` — Write a single character to the given file descriptor.
* `ft_putstr_fd` — Write a C string to the given file descriptor.
* `ft_putendl_fd` — Write a string followed by a newline.
* `ft_putnbr_fd` — Write the decimal representation of an integer.

### Extra utility functions

These functions are custom additions on top of the subject's mandatory list:

* `ft_atoull` — Convert a string to an `unsigned long long`, ignoring leading whitespace, handling an optional `+`, and returning `0` if a negative sign is found.
* `ft_split_set` — Variant of `ft_split` that splits a string using any character from a set `d` as a delimiter, instead of a single delimiter character.

### Singly linked list API

The current Libft subject also includes a minimal singly-linked list API as part of the mandatory project. It is based on the following structure:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

List helpers:

* `ft_lstnew` — Allocate a new node with `content` and `next = NULL`.
* `ft_lstadd_front` / `ft_lstadd_back` — Insert a node at the front or back of a list.
* `ft_lstsize` — Count the number of nodes in a list.
* `ft_lstlast` — Get a pointer to the last node.
* `ft_lstdelone` — Delete a single node using a user-provided `del` function for its content.
* `ft_lstclear` — Delete and free an entire list.
* `ft_lstiter` — Apply a function `f` to the content of each node.
* `ft_lstmap` — Build a new list by applying `f` to each node’s content, using `del` on failure.

All of the above functions are implemented in this repository and compiled into `libft.a`.

---

## Instructions

### Requirements

* C compiler: `cc` (or `gcc`/`clang`)
* Make
* A Unix-like environment is recommended.

### Building the library

```bash
# Clone the repository
git clone <repository-url> libft
cd libft

# Build libft.a
make

# Optional maintenance targets
make clean   # remove object files
make fclean  # remove objects and libft.a
make re      # full rebuild
```

The default `make` target compiles all `ft_*.c` files using `-Wall -Wextra -Werror` and archives them into `libft.a`.

### Using Libft in another project

1. Copy `libft/` into your project or add it as a git submodule.
2. In your project’s `Makefile`, build Libft first (`make -C libft`).
3. Link against the library and include the header:

```c
/* example.c */
#include "libft.h"
#include <stdio.h>

int main(void)
{
    const char  *msg = "Hello, Libft!";
    size_t      len;

    len = ft_strlen(msg);
    printf("Length: %zu\n", len);
    return (0);
}
```

```bash
cc example.c -Llibft -lft -Ilibft -o example
./example
```

---

## Resources

### Documentation & references

Some classic references used while working on this project:

* **Linux man pages (section 3)** — Authoritative documentation for C library functions such as `strlen`, `memcpy`, `strlcpy`, etc. (`man 3 <function>` or online).
* **GNU C Library Reference Manual** — In-depth documentation on behaviour, corner-cases and portability notes for many libc functions.
* **C standard library overviews** — Articles and lecture notes explaining the purpose of the standard C library and categorising its functions (string/memory handling, I/O, math, etc.).
* **42 Libft guides and community write-ups** — High-level explanations of the project goals and examples of how people structure and grow their own `libft` over time.

(See the official subject PDF for the exact list of mandatory functions and technical constraints.)

### AI usage

AI tools (such as ChatGPT) were used in a limited and controlled way:

* To **draft and refine this README** (structure, wording, and section names), which was then reviewed and adapted manually.
* To **discuss design choices** for the library (e.g. how to organise files, how to structure helper functions while staying within the Norm).
* To **clarify behaviour of some C library functions** and edge cases by comparing the subject, `man` pages, and alternative explanations.
* To **get feedback on Norm style and Makefile organisation** (no AI-generated code was pasted blindly; all code was written, understood, and debugged by the author).

All final implementations, debugging, and tests were carried out by the student, who remains responsible for understanding and being able to explain every line of code.
