# HW0.25 | Sorting `C` arrays

In this first in the "introduction to C" series of homeworks, we will write some code that **sorts** an array of integers (or `int`s in `C`). This will provide you with some familiarity with code constructs that you should be familiar with, _viz.,_)

1. loops (`for`, `while`, `do-while`)
2. conditionals (`if-else`)
3. arrays (`arr[x]`)

not to mention applying all of it to solve a problem you should know -- how to sort an array of integers.

## coding instructions

You must implement your sorting code in the following file: `sorting_function.c` inside the function,

```C
int sorting_function( int arr[], int count, int ascending )
{
    // Implement a sorting algorithm of your choice here
    // You can use any algorithm you like (e.g., bubble sort, selection sort, insertion sort, etc.)
    // The 'ascending' parameter indicates whether to sort in ascending (1) or descending (0) order
    // 
    // The function returns 0 on success (by default), You should return non-zero value on failure

    // <YOUR CODE HERE>

    return 0 ; // Return 0 to indicate success
}
```

**Note**: this is the **only** function and source file you should change. Do not modify **any** other `.c` or `.h` file! If you make any other changes, then the grading script will break and **you will lose points**!

As stated in the instructions in the code (the comments), you're welcome to use any _correct_ sorting method of your choice (though I highly recommend you pick the most efficient one). 

Some details:

|variable | type | description|
|---------|------|------------|
| `arr`   | array of `int`s | the "input" (the list of numbers fo be sorted) |
| `count` | `int` | the number of elements in `arr` __+__ |
| `ascending` | `int` | either `1` or `0` to depict whether the array should be sorted in ascending (`1`) or descending (`0`) order |
||

(__+__ why do we need this variable when we have the array itself?)

The **return** value is also an `int` with the following implications:

|value|meaning|
|-----|-------|
| `0` | all is well (default) |
| any other value | something failed |
||

**Note**: while you should not change any other files, feel free to explore the other `.c` and `.h` files. Try to understand how they're organized, what the various functions are doing, _etc._ Where is `main()`? 

## building/compiling your code

The repository includes a `Makefile`. While you may not understand all of it (if you're not familiar with makefiles), such files are **very** important -- especially in large projects or to carry out multiple tasks (_e.g.,_ building/compiling code, running tests, _etc._ as we do here). 

1. to **compile** ("build" -- which include more than just compilation, it includes "linking" as well -- you will learn more later), type the following at the **command line**:

```$> make```

**Note:** you should **not** type the `$>` part -- that is just to indicate that whatever **follows** it should be typed on the command line. In this case, just `make`. 

Run the above in the main directory of your project. 

This will compile and build your code using `gcc` -- one of the most popular `C` compilers. If your code has errors, then that will show up as well. Once your code is complete, and free of _compile-time errors_ (there may still be _runtime/logic errors_ in your code) the makefile will create an _executable_, named `sort`. 

2. to **run** your code:

```$> ./sort```

The `./` is just to indicate that the executable/binary is in the _current_ directory. 

If you run it as mentioned above, you will see the following message:

```
Usage: ./sort <a/d> <input file> <output file>
 
where `a` or `d` stand for ascending/descending
```

Don't be worried. This is expected behavior. What this means is that your program is expecting some **command line arguments/inputs**, _viz.,_

- the **type** of sorting being requested, _i.e.,_ one of `a` (for ascending) or `d` (for descending). 
- an `input_file_name` -- that lists the numbers to be sorted (see the format below)
- an `output_file_name` -- where the sorted numbers are to be written

As you may have already guessed, your code should be able to sort the array in one of two wayss:

- ascending or
- descending

depending on the type of the "first" argument, `a` or `d` respectively. 

Here is an example:

```$> ./sort a tests/test1.txt tests/test_outputs/test1.output.a.txt```

So, we're saying,

- sort in ascending order 
- the inputs are in the file `test1.txt` in the `tests` folder
- write the output to the `test1.output.a.txt` file in the `tests/test_outputs` folder.


### I/O file formats

You can use the **five** public test cases in the `tests` folder to test your code but **you must write other test cases of your own** to make sure you properly capture all sorts of edge cases for the sorting algorithm (_e.g.,_ what if there exist negative numbers in the list?) __*__.

(__*__ what other edge cases can exist?)

To run _all_ of the public test cases, type:

```$> make tests```

It will go through all the test cases in the `tests` folder, run each one twice (once for ascending, once for descending) and write the outputs in the `tests\test_outputs` folder. Files that end in `.a` are the attempts for ascending order and those that end in `.d` are the outputs for the descending order tests.

### input file format

The input file is a **text** file with the following format:

```
<number of integers>
<integer 1>
<integer 2>
<integer 3>
...
<integer n>
```

The **first** number in the file is the **count** of how many numbers (the actual input) must be sorted. 

For example, `test1.txt` in the public tests:

```
10
2
45
9
949
7860
21
0
098
-93
2020208
```

We have `10` numbers, 

```
2
45
9
949
7860
21
0
098
-93
2020208
```

Note that `10` itself is **not** one of the numbers to be sorted -- that's just a count. You don't need to worry about all this as the framework will read in the file (as long as the proper name is provided) and give you the `count` and the list of numbers in `arr`. 

(Look at `helper_functions.c` and `sort.c` to peek under the hood -- to see how this "magic" happens.)

You can (and **should**) write your own test cases in the above format. You can either call them directly as follows:

```$> ./sort a my_test1.txt my_test.a.output.txt```

OR place the input file `my_test1.txt` in the `tests` folder. As long as the format is correct and the file has a `.txt` extension, when you run `make tests`, it will be automatically run with the other tests and output written to `tests/test_outputs` folder.


### output file format 

The output file is also a **text** file with the following format. 

Either,

```
Array is SORTED in <ascending/descending> order!

<list of sorted numbers separated by spaces>
```

OR

```
Array is NOT sorted in <ascending/descending> order!

<list of unsorted numbers separated by spaces>
```

depending on whether your sorting code worked or not.

(In the second case -- NOT sorted -- the _order_ of the list of numbers _may not_ match the original order from the input file. Why?)



## 2-step submission instructions

### Step 1:

You must submit the following via `git`:

1. `sorting_function.c` &rarr; your implementation of the sorting code
2. any additional test cases you have created -- place them in the `tests` folder

**Note:** **DO NOT** modify/submit any other code/files. 

Once you have checked everything in via git, _i.e.,_
- `$> git add`
- `$> git commit -m <message>`
- `$> git pull`
- `$> git push`

### Step 2:

You must submit the following via the **[submit server](https://submit.cs.seas.gwu.edu):**

1. **ONLY** `sorting_function.c`&rarr; your implementation of the sorting code (__Do not submit any other files__)

## important details

- You can receive up to **5% extra credit** on your grade for submitting up to 3 days before the deadline
- **do not** modify any other code/file than the one from the aformentioned instructions
- **remove all `printf()` statements** you have added in the `sorting_function()`. You can use `printf()` calls to help debug your code but before you submit your fina version, please remove/comment them out
- **comment** and **indent** your code properly
- remember that you must `git push` and submit on the submit server for your code to be "submitted" -- make sure that you are on the `main`/`master` branch of your repo
- **do not** use any standard library sorting function! You must implement **your own** code.

If you do not follow the instructions in a precise manner, then you will likely **lose major parts of your grade**!


## grading rubric

|score | phase |
|------|-------|
| `0`  | code does **not compile/build** |
| `+5` | code compiles and builds but **does not run** |
| `+95`| `+9.5` for **each** run (`a`/`d`)of the public test cases (`10` test cases) |
|||
|**`100`**| Total Score |
||

**Note:**

- as mentioned in the [class policies](https://jiezhoucs.github.io/courses/csci-2410/fall-2026/) **do not** cheat/copy code and **do not** use any AI/code generation/LLM tools for assignment content creation!
- if we detect any of this, your grade for this homework will be `0` and you will be reported for an academic integrity violation!