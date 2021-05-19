# Monty 

Monty is an interpreter for bytecode files for Holberton School's Monty 0.98 scripting language. Its files consist of an opcode and, in case of the `push` instruction, also an integer. This project showcases one application of doubly-linked lists. Namely stacks (FIFO) and queues (LIFO). Each instruction of the bytecode is processed sequentially and exits only when an error occured or if the bytecode instruction doesn't exist.

# Table of contents

- [Monty](#monty)
- [Table of contents](#table-of-contents)
  * [Compilation](#compilation)
  * [Usage](#usage)
  * [Opcode instruction list](#opcode-instruction-list)
    + [stack/queue](#stack-queue)
    + [push](#push)
    + [pall](#pall)
    + [pint](#pint)
    + [pop](#pop)
    + [swap](#swap)
    + [nop](#nop)
    + [add/sub/mul/div/mod](#add-sub-mul-div-mod)
    + [pchar](#pchar)
    + [pstr](#pstr)
    + [rotl/rotr](#rotl-rotr)
  * [Examples of Monty bytecodes](#examples-of-monty-bytecodes)
- [Brainfuck](#brainfuck)
- [File list and descriptions](#file-list-and-descriptions)
- [Authors](#authors)

## Compilation

To compile the program, you must have gcc version 4.8.4. Compile with the following command on your terminal:

```bash
$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```

## Usage

```bash
$ ./monty bytecode_file_name
```

## Opcode instruction list

### stack/queue <a name="stack-queue"></a>

The `stack`/`queue` opcodes determine the behavior of the doubly linked list structure. If the `queue` opcode is not specified, then Monty operates with the `stack` mode by default. You can switch between modes without any inconvenients.

### push

The `push` opcode inserts an element to the doubly linked list structure. If there's no structure, it inserts the first element. Depending on the mode, the `push` opcode inserts the new element to the head (`stack`), or to the tail (`queue`) of the list.

### pall

The `pall` opcode prints all the elements of the doubly linked list from the head. If the list doesn't exist, it won't print anything.

### pint

The `pint` opcode prints only the first value of the doubly linked list.

### pop

The `pop` opcode removes the first element of the doubly linked list.

### swap

The `swap` opcode swaps the order of the first two elements of the douby linked list.

### nop

The `nop` opcode does nothing.

### add/sub/mul/div/mod <a name="add-sub-mul-div-mod"></a>

These five are the five arithmetic opcode operations. All the operations are done with the first two numbers of the stack. The first element is removed and the result is replaced in the second. As their name implies, the `add` opcode adds two numbers, the `sub` opcode subtracts two numbers, the `mul` opcode multiplies two numbers, the `div` opcode divides two numbers and the `mod` opcode saves the modulo of two numbers.

### pchar

The `pchar` opcode prints as character the ASCII value saved of the first element of the doubly linked list.

### pstr

The `pstr` opcode prints all characters saved from the head of the doubly linked list. It stops when there's nothing in the stack, the value of the element is 0 or is not in the ASCII table.

### rotl/rotr <a name="rotl-rotr"></a>

These two opcodes rotates the first or the last element of the list. The `rotl` opcode sends the first element of the doubly linked list to the end while the `rotr` opcode sends the last element of the doubly linked list to the beginning.

## Examples of Monty bytecodes

### Example 1

```
push 20
push 40
push 100
pall
pint
pop
add
mul
pall
```

### Example 2

```
push -10
pint
queue
push 10
push 20
push 10
stack
push 1
push 20
pall
add
pall
```

### Example 3

```
queue
push 72
push 101
push 108
push 108
push 111
push 44
push 32
push 87
push 111
push 114
push 108
push 100
push 33
push 0
pstr
```

# Brainfuck

**Brainfuck** is an esoteric programming language, created in 1993 by Urban Müller. It is noted for its extreme minimalism, using only 8 symbols.

# File list and descriptions

- **bf**: Folder with Brainfuck exercises.
- **bytecodes**: Folder with tests and some examples about Monty.
- *exec_opcode.c*: Holds the function that selects and executes each opcode.
- *free.c*: Holds the functions that frees memory allocated during the execution of the program.
- *input.c*: Holds the functions that controls the input of the program (the file entered as argument).
- *opcodes_1.c*: Holds the functions for the `push`, `pall`, `pop`, `pint` and `swap` opcodes.
- *opcodes_2.c*: Holds the functions for the `nop`, `pchar`, `pstr`, `rotl` and `rotr` opcodes.
- *opcodes_mode.c*: Holds the functions for the changing mode (`stack` and `queue` opcodes).
- *opcodes_calc.c:* Holds the arithmetic functions: `add`, `sub`, `mul`, `div` and `mod`.

# Authors

## 👤 Alfredo Delgado Moreno

[![GitHub Badge](https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white)](https://github.com/AlfredPianist/) [![Twitter Badge](https://img.shields.io/badge/Twitter-1DA1F2?style=for-the-badge&logo=twitter&logoColor=white)](https://twitter.com/Alfred_Pianist) [![LinkedIn Badge](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/alfredo-delgado-moreno-75b65290/)

## 👤 Yerardin Perlaza

[![GitHub Badge](https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white)](https://github.com/YerardinPerlaza/) [![Twitter Badge](https://img.shields.io/badge/Twitter-1DA1F2?style=for-the-badge&logo=twitter&logoColor=white)](https://twitter.com/YerardinPerlaza) [![LinkedIn Badge](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/yerardin-perlaza-medina-5135b8a6)