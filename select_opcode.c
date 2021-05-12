#include "monty.h"
/**
 * select_opcode - find opcode and execute
 * @opcode: string with instruction
 * @stack: stack
 * @line_number: unsigned int
 * Return: 0-Success / 1-Fail
 */
int select_opcode(char *opcode, stack_t **stack, unsigned int line_number)
{
	instruction_t opcodes[] = {
		{"push", push}, {"pall", pall}, {"pint", pint}, {"pop", pop}, {"swap", swap},
		{"add", add}, {"sub", sub}, {"mul", mul}, {"div", divi}, {"mod", mod},
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
