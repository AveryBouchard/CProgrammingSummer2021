README file

— Homework 4 (Functions) Multiple File Code Template —


This folder contains template files to allow you to complete Homework 4 (Functions) in the C Programming class using multiple files.   See Option 1 folder for homework template files needed for a design that implements functions with a combination of Call by Value and Call by Reference.  See Option 2 folder for homework template files needed using a Call by Reference design.  

Choose whatever folder that has the design your prefer to start with for your 
homework assignment.

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
provided to get you started.  Just type the make command to start.

    make

If using a native compiler with an IDE, just load each of the C and *.h files into
you compiler environment and start your program from there.  All should compile and
you will get a basic print out of employee information to the screen that you can
continue on from there.

Note:  Multiple files will not work with the IDEOne site if you are using that one.