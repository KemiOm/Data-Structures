
## The Assignment
In the last assignment, you created an application that reads in a list of pirate names and sorts them before printing out their names as a list. This time, your swashbuckling clientele has finally concluded their market research and now they have full profiles for the pirates in their HookBook. The information they need you to store includes:
- Their current vessel of employ
- Their current captain (who is another pirate!)
- The number of treasures they've found
- Their favorite port of call
- All of the pirating skills they possess.

As in the previous assignment, your job will be to display each pirate's profile in sorted order, this time with the full complement of profile information.

There are two additional requirements for this assignment, however. First, you will be given two input files: one as formatted before, with a list of pirate profiles, and another containing pirate/captain pairs. Second, the sort order won't be predefined for you. Instead, you must accept a command-line argument to define the sorting order. Precisely how you must handle this is described below.

### To summarize
Your program must:
1. Load a list of pirate profiles from a file whose name is given to you as a command-line argument.
2. Load a list of pirate/captain pairs from a file whose name is given to you as a command-line argument.
3. Accept a third command-line argument, which is the sorting order for your output.
4. Add those pirates into a list and sort that list in the specified order.
5. Display the profiles of the pirates, sorted according to the argument.

## Files you are given
- `skills_list.h` (Interface)
- `pirate.h` (Interface)
- `pirate_list.h` (Interface)
- `libhookbook.h` (Interface)
- `libhookbook.c` (Implementation)
- `makefile`

## Files you must create
- `hookbookb.c` (Driver)
- `skills_list.c` (Implementation)
- `pirate.c` (Implementation)
- `pirate_list.c` (Implementation)

## Other requirements
- The implementation of `skills_list` must be as a singly-linked list.
- Each header and source file must use `#include` directives to include things that are directly used by that file&mdash;no more, no less.
- You may not use the standard library's `qsort` function to sort anything, nor any other pre-implemented sorting function. You must implement every sorting algorithm that you use on your own.
- You must create at most one pirate for each name in the input file&mdash;you may not create copies of pirates (copies of pointers to pirates is OK).
- It is possible that you will not use every function you implemented, but you still must implement every function identified in this README!
- Now that you're managing memory yourself, we will test your submission with `valgrind`, a tool to help identify memory leaks.

## Input Format
The input to the program is three command-line arguments, which represent the name of the profiles file, the name of the captains file, and a flag indicating the method by which to sort the output.

The profiles file is organized as described in the previous assignment. The captains file contains pirate/captain pairs, with one name per line.

## Output Format
The output from your program must be a list of pirate profiles, sorted in the order defined by the user at the command line.

### Examples
For detailed examples, refer to the full README.
```




