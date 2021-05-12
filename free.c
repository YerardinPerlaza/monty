#include "monty.h"

void free_error(char *line, FILE *file, stack_t **stack)
{
	free(line);
	fclose(file);
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
