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

/* File reading - input.c */
int read_monty(char *path, stack_t **stack);
int check_number(char *number);

/* Free - free.c */
void free_error(char *line, FILE *file, stack_t **stack);
void free_stack(stack_t **stack);

/* Opcodes - opcodes_1.c */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);

/* Opcode selection - select_opcode.c */
int select_opcode(char *opcode, stack_t **stack, unsigned int line_number);

#endif