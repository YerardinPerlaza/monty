#include "monty.h"

void free_error(stack_t **stack)
{
	free(global_vars->current_line);
	fclose(global_vars->file);
	free(global_vars);

	free_stack(stack);

	exit(EXIT_FAILURE);
}

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
