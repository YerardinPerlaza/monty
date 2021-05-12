#include "monty.h"
/**
 * free_error - free, close and exit for an error
 * @line: command line
 * @file: file commands
 * @stack: stack
 * Return: void
 */
void free_error(char *line, FILE *file, stack_t **stack)
{
	free(line);
	fclose(file);
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
