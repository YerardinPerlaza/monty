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
 * pstr - prints a string of characters
 * @stack: the stack
 * @line_number: the line number of the script read to display on error
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;

	current = *stack;
	while (current && (current->n > 0 && current->n <= 127))
	{
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
}
