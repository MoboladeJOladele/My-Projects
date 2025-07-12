# `arlen`: Array Length Calculator in C

`arlen` is a simple yet powerful function for **determining the number of elements in an array** in C. It works with a variety of types, including:

- `int`
- `float`
- `double`
- `char`
- `long`
- Strings (`char[]` and `char*[]`)

>  **IMPORTANT:** Always pass the `sizeof(array)` as the second argument when using `arlen`.

---

## How It WORKS

The `arlen` function uses a **generic selector "_Generic"** to determine the datatype to be passed into arlen. It then uses that information, along with the size of the array (passed as a parameter to the function) to calculate its length accordingly. It is ideal for measuring **ALL** the elements in an array.
Although it's extremely effective, the function has one limitation which we'll discuss later
```c
int arlen(type array, int array_size);  **For clarity, I used `type` to represent the datatype(s); it's not the exact keyword used in the actual code.**

```

> **NOTE:** Currently, there is no standard header file for `arlen`. To use it, **copy the function definition into your `.c` file.**

---

## Key Notes and Behavior

### arlen Works With

* Primitive arrays like:

  ```c
  int arr[] = {1, 2, 3};
  ```

* String arrays like:

  ```c
  char *org[] = {"Github", "Youtube", "Google", "Meta"};
  ```

---

### Special Case for `char[]`

If you're measuring the length of a `char[]`, such as:

```c
char name[] = "Joseph";
```

`arlen` will **include the NULL terminator** (`'\0'`), resulting in a count of **7**, not 6.

```c
printf("%i\n", arlen(name, sizeof(name))); // Output: 7
```

---

### Limitations with `char*[]`

When you pass a **string array of pointers**, such as:

```c
char *org[] = {"Github", "Youtube", "Google", "Meta"};
```

`arlen(org, sizeof(org))` will return `4` – the number of strings (pointers to `char[]`) in the array.

However, to get the length of a specific string (e.g., `"Google"`), you need to use `strlen()`:

```c
printf("%lu\n", strlen(org[2])); // Output: 6 (not 7, as '\0' is not included)
```

> **Reminder:** `strlen()` returns the number of useful characters, **excluding** the NULL terminator.

---

## Practical Examples

```c
#include <stdio.h>
#include <string.h>

// Assume arlen is defined above or included

int main() {
    char *org[] = {"Github", "Youtube", "Google", "Meta"};

    for (int i = 0, n = arlen(org, sizeof(org)); i < n; i++) {
        printf("Word: %s\n", org[i]);

        printf("Length: %lu characters (excluding NULL terminator)\n", strlen(org[i]));
    }

    return 0;
}
```

---

## In Summary

* `arlen` helps to compute the number of elements in most C arrays.
* Always pass the `sizeof(array)` as the second parameter.
* Use `strlen()` to count characters in string elements, excluding the NULL character.
* Combine `arlen()` and `strlen()` for powerful string array iteration.

---

## 🙏 Thanks & Happy Coding!

Feel free to copy and tweak `arlen` for your personal or project use.  
A dedicated header file may be released in the future.

---

> Powered by the Holy Spirit 🔥🔥
