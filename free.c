#include "monty.h"

void free_error(stack_t **stack)
/**
 * free_error - free, close and exit for an error
 * @stack: stack
 * Return: void
 */
{
	free(global_vars->current_line);
	fclose(global_vars->file);
	free(global_vars);

	free_stack(stack);

	exit(EXIT_FAILURE);
}
/**
 * free_stack - free stack
 * @stack: stack
 * Return: void
 */
void free_stack(stack_t **stack)
{
	stack_t *current;

	current = *stack;
	while (current)
	{
		*stack = current->next;
		free(current);
		current = *stack;
	}
}
