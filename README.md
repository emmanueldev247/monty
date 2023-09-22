# Monty ByteCode Interpreter Documentation

## Introduction

The Monty ByteCode Interpreter is a program that executes Monty ByteCode files. Monty ByteCode is a simple programming language that operates on a stack data structure.

## Usage

To run the Monty ByteCode Interpreter, use the following command:
` $ ./monty <file>`


- `<file>`: The path to a Monty ByteCode file containing a sequence of Monty instructions.

## Supported Opcodes

The Monty ByteCode Interpreter supports the following opcodes:

- `push <int>`: Pushes an integer onto the stack.
- `pop`: Removes the top element from the stack.
- `swap`: Swaps the top two elements of the stack.
- `add`: Adds the top two elements of the stack.
- `sub`: Subtracts the top element from the second top element.
- `div`: Divides the second top element by the top element.
- `mul`: Multiplies the top two elements of the stack.
- `mod`: Computes the remainder of the division of the second top element by the top element.
- `pall`: Prints all the values on the stack.
- `pint`: Prints the value at the top of the stack.
- `nop`: No operation (does nothing).

## Error Handling

The Monty ByteCode Interpreter handles errors gracefully:

- Division by zero: If division by zero is attempted, the interpreter produces a "division by zero" error and exits.
- Stack underflow: If an operation requires more elements on the stack than available, a "stack too short" error occurs.
- Unrecognized opcodes: If an unrecognized opcode is encountered, the interpreter produces an "unknown instruction" error.
- File-related errors: If the Monty ByteCode file cannot be opened, the interpreter produces a "can't open file" error.

## File Format

Monty ByteCode files should adhere to the following format:

- Each line in the file represents one Monty instruction.
- Lines starting with a '#' character are treated as comments and are ignored.

Example Monty ByteCode file:
* Push integers onto the stack
<br>    `push 10` <br>
    `push 20`

* Perform arithmetic operations
<br>    `add`<br>
    `pall`



## Compilation

To compile the Monty ByteCode Interpreter, use the following command:

`$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty`


## Dependencies

The Monty ByteCode Interpreter depends on the following:

- Standard C library

## Usage Example

$ ./monty sample.m


## Contributors

- [Emmanuel Ademola](https://github.com/emmanueldev247)
