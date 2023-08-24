# Monty Bytecode Interpreter

Monty is a simple bytecode interpreter that reads Monty byte code files and executes instructions to manipulate a stack data structure.

## Table of Contents

- [Description](#description)
- [Features](#features)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [File Format](#file-format)
- [Supported Opcodes](#supported-opcodes)

## Description

Monty is a project that implements a bytecode interpreter for executing operations on a stack data structure. The interpreter reads a file containing Monty byte code instructions and performs various stack manipulation operations based on those instructions.

## Features

- Interpret and execute Monty byte code instructions.
- Handle various stack manipulation operations, such as push, pop, swap, add, etc.
- Proper error handling and exit status based on specified requirements.
- Tokenize input lines to identify opcodes and arguments.

## Getting Started

To get started with the Monty interpreter, follow these steps:

1. Clone this repository to your local machine.
2. Ensure you have the required dependencies installed (e.g., `gcc`).
3. Compile the Monty interpreter using the provided compilation command.
4. Run the interpreter by providing the path to a Monty byte code file.

## Usage

```
sh
./monty <file>
```

Where <file> is the path to the Monty byte code file you want to execute.

## File Format
Monty byte code files contain instructions that are executed line by line. Each line consists of an opcode and an optional argument. Opcodes are case-sensitive and must be followed by their corresponding arguments if required.

## Supported Opcodes
The Monty interpreter supports various opcodes, including:

1. [push] <int>: Push an integer onto the stack.
2. [pop]: Remove the top element from the stack.
3. [swap]: Swap the top two elements of the stack.
4. [add]: Add the top two elements of the stack.
5. [pint]: Print the value at the top of the stack.
6. [pall]: Print all values in the stack.