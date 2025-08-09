# C--Progs

Hello there 👋  
I'm **Joe**, and welcome to **C--Progs**.

---

## Before you begin
All the projects here were built by me, though I had some assistance along the way.  

Each folder has a test file (`tryout.c`) for you to try out the `.c` functions.  
So try them out, tell me what you feel, and have a wonderful time.

---

## Function list
This will help you navigate the repo better.

---

### 1. `arlen()`
**Purpose:** Used for array length calculation.  
**Compatibility:** Works with all basic datatypes, including chars and strings.  
👉 [link](https://github.com/MoboladeJOladele/My-Projects/tree/main/C--Progs/arlen)

---

### 2. `sort()`
**Purpose:** Sorts arrays. Works with strings, integers, and any other basic datatype.  
**Note:** Ensure you’re using conventional arrays, not pointers.

**Examples:**
    
    int name[];     // integers
    char name[];    // characters
    char *name[];   // strings (string sets)

👉 [let's start sorting](https://github.com/MoboladeJOladele/My-Projects/tree/main/C--Progs/sort)

---

### 3. `merge_sort()` — **"THE FATHER OF SORT"**
Just like `sort()`, this function is for array sorting, but it’s restricted to ints alone.  
It inspired `sort()` and was a real game changer for me.  
It’s a great function, and I know you’ll love it.  
👉 [link](https://github.com/MoboladeJOladele/My-Projects/tree/main/C--Progs/merge_sort)

---

## `strings.c`
The last man — drum roll please 🥁 — **strings.c**.

I know, I know… it sounds like `string.c` from the `string.h` header file.  
I really tried to come up with something better, but I couldn’t — so just bear with me.

Unlike the others, `strings.c` is a **C source file** containing a bunch of meaningful functions:

- `_lower()` → Converts strings to lowercase.  
- `_upper()` → Converts lowercase strings to uppercase.  
- `_islowercase()` → Returns `true` if a string is completely lowercase.  
- `_isuppercase()` → Returns `true` if a string is completely uppercase.  
- `_case()` → Detects the case of a string and returns:
  - `"upp"` for uppercase strings
  - `"low"` for lowercase strings
  - `"both"` for a mix of both cases

**Example:**
    
    char *string = "joe";
    if (strcmp(_case(string), "low") == 0)
    {
        printf("It's lowercase\n");
    }

**Tip:** To use `_case()` effectively, check its return value with [`strcmp()`](https://manual.cs50.io/3/strcmp) from `string.h`.

---

## More resources
When working through these projects, you’ll come across other header files like:
- `string.h`
- `stdlib.h`
- and many others

You can use [manual.cs50.io](https://manual.cs50.io) to learn more about them.  
This site has documentation for many standard C library functions and headers — perfect for expanding your knowledge beyond what’s covered here.

---

## Final words
I wish you the best of luck on your journeys.  
To all the young men out there — anything is possible if you set your mind to it.  
And most importantly, have a strong relationship with God, because without Him, you can do nothing.

I truly appreciate your time, and I thank my Teacher and Friend — **The Holy Spirit** — who has helped me a lot.  

Thanks once again for your time. I wish you all the best.