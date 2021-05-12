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
