#  `arlen`: Array Length Calculator in C

`arlen` is a flexible function for **determining the number of elements in arrays and strings** in C.  
It works with:

- `int[]`
- `long[]`
- `float[]`
- `double[]`
- Strings → `char*` (e.g., `"Hello"`)
- String sets → `char*[]` (e.g., `{"Yes", "No"}`)

> 📝 **Note:** Always pass `sizeof(array)` as the second argument to arlen().

---

##  How It Works

The `arlen` function uses C's **`_Generic`** keyword to select the correct function depending on the array's type. It then uses the element size to compute the count:

```c
#define arlen(array, size) _Generic((array), \
    int*: arlen_ints, \
    long*: arlen_longs, \
    float*: arlen_floats, \
    double*: arlen_doubles, \
    char*: arlen_string, \
    char**: arlen_string_set \
)(array, size)
```

Internally, the calculation is based on:

```c
size / sizeof(array[0])
---

## 📌 arlen Works With

### ✅ Numeric Arrays

```c
int num[] = {12, 13, 26, 0, 1, 1};
arlen(num, sizeof(num)); // → 6
```

Same applies for `long[]`, `float[]`, and `double[]`.

---

### ✅ Single String (`char*`)

```c
char *text = "hello, world!";
arlen(text, sizeof(text)); // → 12
```

This counts the **visible characters only** — `arlen_string` does **not** include the null terminator (`'\0'`).

> It’s equivalent to `strlen()`, but built into the `arlen` system.

---

### ✅ String Sets (`char*[]`)

```c
char *set[] = {"yes", "no", "maybe"};
arlen(set, sizeof(set)); // → 3
```

Counts how many strings are in the array.

---

### 🧪 String Inside a String Set

```c
arlen(set[2], sizeof(set[2])); // → 5 ("maybe")
```

> The correct handler (`char*`) is selected, returning the  visible character count (like `strlen()`).

---

## 🧪 Example Program

```c
#include <stdio.h>

int main(void)
{
    char *string = "hello, world!";
    char *string_set[] = {"yes", "no", "maybe"};
    int num[] = {12, 13, 26,  0,  1, 1};

    printf("Length of string: %i\n", arlen(string, sizeof(string)));
    printf("Length of string set: %i\n", arlen(string_set, sizeof(string_set)));
    printf("Length of number array: %i\n", arlen(num, sizeof(num)));

    // Length of an element in the string set
    printf("\nLength of Element: %i\n", arlen(string_set[2], sizeof(string_set[2])));
}
```

---

## ⚠️ Limitation

`arlen` uses `sizeof(array)`, which only works reliably for **statically declared arrays**. It **cannot** calculate lengths of:

- Arrays passed as function parameters
- Dynamically allocated arrays (`malloc`, etc.)

This is a **general limitation of C**, not `arlen` specifically.

---

## ✅ Summary

- `arlen` supports arrays of most primitive types.
- Handles both `char*` (strings) and `char*[]` (array of strings).
- `arlen(char*, size)` counts **only visible characters**, like `strlen()`.
- You must always pass `sizeof(array)` correctly.
- Not intended for dynamically allocated memory or parameters.

---

## 🙏 Thanks & Happy Coding!

Feel free to copy and tweak `arlen` in your own C projects.  
A dedicated header file may be released in the future.

> Powered by the Holy Spirit 🔥
