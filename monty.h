#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_vars_s - a structure to hold some global variables
 * @file: the file opened
 * @current_line: the line read by getline
 * @push_number: the number to be pushed to the stack
 *
 * Description: a structure holding some global variables
 */
typedef struct global_vars_s
{
	FILE *file;
	char *current_line;
	int push_number;
} global_vars_t;

global_vars_t *global_vars;

/* File reading - input.c */
int read_monty(char *path, stack_t **stack);
int check_number(char *number);

/* Free - free.c */
void free_all(stack_t **stack, int exit_status);
void free_stack(stack_t **stack);

/* Opcode execution - exec_opcode.c */
int exec_opcode(char *opcode, stack_t **stack, unsigned int line_number);

/* Opcodes list, part 1 - opcodes_1.c */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);

/* Opcodes list, part 2 - opcodes_2.c */
void nop(stack_t **stack, unsigned int line_number);

/* Opcodes calculation - opcodes_calc.c */
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void divi(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);

#endif
