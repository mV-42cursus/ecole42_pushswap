
# Push Swap

## Overview
Push Swap is a 42 School project that involves sorting data on a stack, with a limited set of instructions, using the lowest possible number of actions. The goal is to learn and implement sorting algorithms and to optimize the solution for the least number of operations.

## Problem Description
- You have two stacks named A and B.
- Stack A is given a random list of integers (without duplicates).
- The goal is to sort the numbers in ascending order into stack A.
- You can use a limited set of operations to manipulate the stacks.

## Operations
- `sa`: Swap the first two elements of stack A.
- `sb`: Swap the first two elements of stack B.
- `ss`: `sa` and `sb` at the same time.
- `pa`: Push the top element from stack B onto stack A.
- `pb`: Push the top element from stack A onto stack B.
- `ra`: Rotate stack A upwards.
- `rb`: Rotate stack B upwards.
- `rr`: `ra` and `rb` at the same time.
- `rra`: Rotate stack A downwards.
- `rrb`: Rotate stack B downwards.
- `rrr`: `rra` and `rrb` at the same time.

## Usage

### Compilation
To compile the program, use:
```bash
gcc -Wall -Wextra -Werror *.c -o push_swap
```

### Execution
Run the program with:
```bash
./push_swap [list of integers]
```

## Goal
- The main goal is to sort the numbers in stack A in as few operations as possible.
- The project should be efficient and should be able to handle a large number of elements.

## Notes
- Choosing the right sorting algorithm and optimizing it for this specific problem is key.
- Handling edge cases and ensuring efficient manipulation of stack elements is crucial.

