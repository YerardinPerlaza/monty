#include "global.h"
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
		/* Pasar struct global con línea actual, archivo y push, ¿cómo? */
		fprintf(stderr, "Error: malloc failed\n"), exit(EXIT_FAILURE);

	new_node->n = push_number;
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
