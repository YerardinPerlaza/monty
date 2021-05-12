#include "monty.h"

/**
 * nop - doesn't do anything
 * @stack: the stack
 * @line_number: the line number of the script read to display on error
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * pchar - print a character
 * @stack: stack
 * @line_number: unsigned int
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int c;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	c = (*stack)->n;
	if (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')))
		printf("%c\n", c);
	else
		fprintf(stderr, "L%d: can't pchar, value out of range'\n", line_number);
}
