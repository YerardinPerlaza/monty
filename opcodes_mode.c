#include "monty.h"

/**
 * stack_mode - converts the stack to stack mode (push to the head)
 * @stack: the stack
 * @line_number: the line number of the script read to display on error
 */
void stack_mode(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	global_vars->mode = 0;
}

/**
 * queue_mode - converts the stack to queue mode (push to the tail)
 * @stack: the stack
 * @line_number: the line number of the script read to display on error
 */
void queue_mode(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	global_vars->mode = 1;
}
