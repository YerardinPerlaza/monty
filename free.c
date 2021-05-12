#include "monty.h"

/**
 * free_all - frees all malloc'ed structs, closes file and exits
 *            program if on error.
 * @stack: the stack.
 * @exit_status: the exit status to exit if 1.
 */
void free_all(stack_t **stack, int exit_status)
{
	if (global_vars->current_line)
		free(global_vars->current_line);
	if (global_vars->file)
		fclose(global_vars->file);
	free(global_vars);

	if (stack)
		free_stack(stack);

	if (exit_status)
		exit(EXIT_FAILURE);
}

/**
 * free_stack - frees all malloc'ed nodes in the stack.
 * @stack: the stack
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
