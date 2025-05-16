# curly-adventure
First repository

# Big Integer Project

## Overview
The Big Integer Project implements a `BigInt` class in C++ to handle integers beyond the standard 20-digit limit of typical data types. It supports arithmetic operations (addition, subtraction, multiplication, division, modulo, power), comparison operators, and advanced mathematical functions (Fibonacci, Catalan, factorial). Two versions of the script are provided:

- **Version 1 (Original)**: Uses a `std::string` to store digits, focusing on basic functionality.
- **Version 2 (Updated)**: Enhances the original by using a `std::vector<int>` for digits, adding explicit memory management, and incorporating basic logging for operations.

This project demonstrates advanced data structures, algorithms, memory management, and operating systems principles, aligning with requirements for roles emphasizing C/C++ programming and software development lifecycle (SDLC).

## Files
- `BigInt.cpp`: Original implementation using `std::string` for digit storage.
- `BigInt_SDLC.cpp`: Updated implementation using `std::vector<int>`, with memory optimization and logging.

## Features
- Handles integers exceeding 20 digits with a custom `BigInt` class.
- Supports arithmetic operations: addition (`+`), subtraction (`-`), multiplication (`*`), division (`/`), modulo (`%`), and power (`^`).
- Includes increment (`++`) and decrement (`--`) operators, both pre- and post-fix.
- Provides comparison operators: `==`, `!=`, `<`, `>`, `<=`, `>=`.
- Implements mathematical functions: square root (`sqrt`), Nth Fibonacci (`NthFibonacci`), Nth Catalan (`NthCatalan`), and factorial (`Factorial`).
- **Version 2 Enhancements**:
  - Uses `std::vector<int>` for digit storage, showcasing advanced data structures.
  - Optimizes memory usage with pre-allocation (`reserve`) and explicit resizing.
  - Adds basic logging to track operations, simulating OS-style monitoring.

## Requirements
- C++ compiler (e.g., g++ with C++11 or later).
- Standard C++ libraries (`<bits/stdc++.h>`, `<vector>`, `<string>`).

## Usage
1. **Compile the Code**:
   - For Version 1:
     ```bash
     g++ BigInt.cpp -o BigInt
     ```
   - For Version 2:
     ```bash
     g++ BigInt_SDLC.cpp -o BigInt_SDLC
     ```

2. **Run the Program**:
   - For Version 1:
     ```bash
     ./BigInt
     ```
   - For Version 2:
     ```bash
     ./BigInt_SDLC
     ```

3. **Example Output** (Version 2):
   ```
   Log: Initialized BigInt from string: 12345
   The number of digits in first big integer = 5
   Log: Initialized BigInt from number: 0
   first and second are equal!
   Zero test passed!
   Log: Performed multiplication operation (in Factorial)
   Factorial of 50 = 30414093201713378043612608166064768844377641568960512000000000000
   ```

## SDLC Phases
The project followed a structured Software Development Lifecycle (SDLC):

- **Design**:
  - Planned the `BigInt` class to handle large integers using a digit storage mechanism (`std::string` in V1, `std::vector<int>` in V2).
  - Defined supported operations and mathematical functions.
- **Implementation**:
  - Coded constructors, operators, and helper functions.
  - Version 2 added memory optimization and logging features.
- **Testing**:
  - Tested basic functionality (e.g., arithmetic operations, comparisons) in `main`.
  - Added edge cases in Version 2 (e.g., zero, large factorials).
  - Verified memory management by monitoring vector resizing and logging operations.

## Testing
The `main` function includes test cases to verify functionality:
- **Basic Operations**: Checks equality of two `BigInt` objects (`12345`).
- **Edge Cases**: Tests zero (`Null` function) and large numbers (factorial of 50).
- **Logging (Version 2)**: Outputs logs for initialization and operations.

To extend testing, you can modify `main` to include:
- Division and modulo with edge cases (e.g., division by zero).
- Very large inputs for Fibonacci and Catalan numbers.

