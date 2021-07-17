README file

— Homework 8 (Linked Lists, Pointers, Structures and Strings) Multiple File Code Template —


This folder contains template files to allow you to complete Homework 8 (Linked List, Pointers, Structures and Strings) in the C Programming class using multiple files.

The key to working with multiple files is the include file:  employees.h

It should be included in all your C files so that they all have access to
common constants, types, and function prototypes.   As you add new C files,
make sure this file gets updated to include any new function prototypes.

It is included as in your code as:

#include "employees.h"

I would suggest including it with the stdio.h file in all your C files

#include <stdio.h>
#include "employees.h"

... assumes the employees.h file is stored in the same directory as your other program C files.

If running these from the command line, such as in a UNIX system, a Makefile has been
provided to get you started.   Just click this command to start:

    make

If using a native compiler with an IDE, just load each of the C and *.h files into
you compiler environment and start your program from there.  All should compile and
you will get a basic print out of employee information to the screen that you can
continue on from there.

Note:  Multiple files will not work with the IDEOne site if you are using that one.