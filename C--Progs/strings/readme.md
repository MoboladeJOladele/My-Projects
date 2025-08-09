# strings.c

`strings.c` is a small collection of helper functions for analyzing and transforming the letter case of strings in C.  
It provides tools to:
- Convert strings entirely to lowercase or uppercase.
- Check whether a string is fully lowercase or fully uppercase.
- Detect whether a string is mixed case, fully lower, fully upper, or contains no letters.

These functions handle **non-alphabetic characters gracefully** (they are preserved unchanged) and return dynamically allocated strings for the case conversion functions.

---

## 📂 Files

- **`strings.c`** → Contains all the functions listed below.
- **`tryout.c`** → A test file showing example usage of `strings.c`.

---

## 📜 Functions Overview

### `_lower(char *s, int size)`
Converts all alphabetic characters in `s` to lowercase.  
Non-alphabetic characters remain unchanged.  
Returns a **newly allocated** string — remember to `free()` it when done.

### `_upper(char *s, int size)`
Converts all alphabetic characters in `s` to uppercase.  
Non-alphabetic characters remain unchanged.  
Returns a **newly allocated** string — remember to `free()` it when done.

### `_islowercase(char *s)`
Checks if the string contains only lowercase letters (ignoring non-alphabetic characters).  
- Returns `true` if all letters are lowercase.
- Prints a message if there are **no letters** in the string.

### `_isuppercase(char *s)`
Checks if the string contains only uppercase letters (ignoring non-alphabetic characters).  
- Returns `true` if all letters are uppercase.
- Prints a message if there are **no letters** in the string.

### `_case(char *s)`
Determines the **case classification** of the string:
- `"low"` → all letters lowercase
- `"upp"` → all letters uppercase
- `"both"` → mix of upper and lower
- `"None"` → no letters at all

> This is useful for quick string classification — especially when combined with `strcmp()` from `<string.h>`.

---

## 📌 Additional Helper Functions

- **`look_for_letters(char *s)`**  
  Returns `true` if the string contains at least one letter, `false` otherwise.

- **`found_no_letters(char *function)`**  
  Prints a standard message indicating no letters were found in the provided string.

---

## 📖 Documentation References

When using `_case()` with `strcmp()` for comparisons, you can refer to the official documentation here:  
🔗 [manual.cs50.io — strcmp()](https://manual.cs50.io/3/strcmp)

The same site also contains documentation for other header files used in this project (`<stdlib.h>`, `<string.h>`, `<ctype.h>`, etc.).  
You’re encouraged to explore it when working with these functions.

---

## 🚀 Example Usage

The included `tryout.c` demonstrates `_case()` in action:

```c
#include <stdio.h>
#include <string.h>
#include "strings.c"

int main(void)
{
    char *string1 = "John";
    char *string2 = "john";

    if (strcmp(_case(string1), "low") != 0)
    {
        printf("[%s] isn't lowercase\n", string1);
    }

    if (strcmp(_case(string1), "upp") != 0)
    {
        printf("[%s] isn't uppercase\n", string1);
    }

    if (strcmp(_case(string1), "both") == 0)
    {
        printf("[%s] has both lowercase and uppercase letters\n\n", string1);
    }

    if (strcmp(_case(string2), "low") == 0)
    {
        printf("[%s] isn't uppercase\n", string2);
        printf("It's lowercase\n");
    }
}
```

**Expected Output:**
```
[John] isn't lowercase
[John] isn't uppercase
[John] has both lowercase and uppercase letters

[john] isn't uppercase
It's lowercase
```

---

## ⚠️ Notes
- `_lower()` and `_upper()` allocate memory — always `free()` the returned string after use.
- These functions do not modify the original string.
- Non-alphabetic characters are ignored when determining case.

---

## This file is part of the **C--Progs** collection by Joe.
  
