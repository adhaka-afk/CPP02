# CPP02


## Description:

This module focuses on implementing a fixed-point number class in C++ that adheres to the Orthodox Canonical Form. Fixed-point numbers are a valuable numeric representation in computer science, offering a balance between performance, accuracy, range, and precision.
## Overview:

The module consists of three exercises:

## Exercise 00:
Implementing the basic structure of a fixed-point number class with default constructor, copy constructor, copy assignment operator, destructor, and member functions to get and set the raw value.
## Exercise 01:
Expanding the functionality of the fixed-point number class to include constructors that accept integers and floating-point numbers, conversion functions to convert the fixed-point value to float or int, and an overload of the insertion (<<) operator to print the fixed-point number.
## Exercise 02: 
Adding operator overloads for comparison, arithmetic, and increment/decrement operations, as well as static member functions to find the minimum and maximum values of fixed-point numbers.
## Files Structure: 
. Each exercise is contained in its own directory (ex00, ex01, ex02).

. The class definition is split into a header file (Fixed.hpp) and its implementation is in a separate source file (Fixed.cpp).

. The main.cpp file in each directory contains the test cases for the implemented functionality.

## Compilation and Execution:

1. Navigate to the Exercise Directory: Open a terminal and change to the directory of the exercise you want to run.
 ```bash
cd ex00  # Replace 'ex00' with the exercise directory you want to run
```
2. Compile the Code: Use the provided Makefile to compile the code.
 ```bash
make
```
3. Run the Executable: After successful compilation, run the generated executable.
```bash
./Fixed  # Replace 'Fixed' with the name of the executable for the exercise
```
4. Verify Output: Check the output in the terminal to verify the correctness of the program.
   
5. Clean Up (Optional): To clean up the compiled files, you can use the clean/fclean target in the Makefile.
 ```bash
make clean
```
or 
 ```bash
make fclean
```

## Exercise Specifics:

. Exercise 00: Implements the basic structure of the fixed-point number class.

. Exercise 01: Expands the functionality to include constructors and conversion functions.

. Exercise 02: Adds operator overloads for comparison, arithmetic, and increment/decrement operations.

## 🚀 Next Project

[CPP03](https://github.com/adhaka-afk/CPP03)

## ⏳ Previous Project

[CPP01](https://github.com/adhaka-afk/CPP01)


