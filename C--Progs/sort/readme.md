# `sort.c`

Sort, oh my. This was a dream come true. I had had this idea for a long time, but I was too cowardly to do it. I give glory to God though, that I got it finished — and I hope you love it.

So `sort`, like its name implies, is a sorting algorithm for C arrays. It works not just with numeric arrays — ints, floats, doubles, etc. — but also with chars and strings. It's fast, reliable, and efficient — well, because it uses a merge sort algorithm. So you need not worry about large data.

For the string sorting (be it `char` or `char*` strings), it compares the two values and sorts them by alphabetical ranking. In a case where two similar strings with different casings are found, the lowercase string is pushed first.

Like in the real code, where we have:

```c
char* strings[] = {"Jasmine", "jasmine", "JAMES", "Oli", "Adam"};
```

The output is:

```
Adam
JAMES
jasmine
Jasmine
Oli
```

Showing that lowercase `"jasmine"` comes before the uppercase one.

I forgot to mention — you can specify the order in which the sorting occurs, whether it's `"ascending"` or `"descending"`. Do take note that both are lowercase.

For the function call, you simply write:

```c
sort(arrayname, "order", size);
```

Where:
- `arrayname` is the name of your array,  
- `"order"` is either `"ascending"` or `"descending"`,  
- and `size` is the size of the array — which you can get using `sizeof(arrayname)`.

> ⚠️ To use the `sizeof()` function properly, make sure you include `stdio.h`.

With that said, enjoy sorting — have some fun. And if you'd like to reach out to me for any improvements, don't hesitate to do so.

Till next time, bye.
