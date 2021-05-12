#include "monty.h"

/**
 * exec_opcode - finds opcode and executes the command
 * @opcode: the string with instruction
 * @stack: the stack
 * @line_number: the line number of the script read to display on error
 *
 * Return: 0 if success, 1 if failure
 */
int exec_opcode(char *opcode, stack_t **stack, unsigned int line_number)
{
	instruction_t opcodes[] = {
		{"push", push}, {"pall", pall}, {"pint", pint}, {"pop", pop}, {"swap", swap},
		{"add", add}, {"sub", sub}, {"mul", mul}, {"div", divi}, {"mod", mod},
		{"nop", nop},
		{NULL, NULL}
	};
	int counter;

	for (counter = 0; opcodes[counter].opcode; counter++)
		if (strcmp(opcode, opcodes[counter].opcode) == 0)
		{
			opcodes[counter].f(stack, line_number);
			return (0);
		}
	return (1);
}
