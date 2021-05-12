#include "monty.h"

/**
 * push - Create a stack and add an int to stack
 * @stack: double pointer to stack
 * @line_number: int
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	(void)line_number;

	new_node = malloc(sizeof(*new_node));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_error(stack);
	}

	new_node->n = global_vars->push_number;
	new_node->prev = NULL;

	if (!*stack)
	{
		new_node->next = NULL;
		*stack = new_node;
		return;
	}

	new_node->next = *stack;
	*stack = new_node;
}

/**
 * pall - Print all the stack
 * @stack: double pointer to stack
 * @line_number: int
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;

	current = *stack;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	current = *stack;
	if (!current)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_error(stack);
	}

	*stack = current->next;
	free(current);
}
