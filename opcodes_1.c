#include "monty.h"

/**
 * push - creates a stack and adds an int to the stack
 * @stack: the stack
 * @line_number: the line number of the script read to display on error
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node, *current;

	(void)line_number;

	new_node = malloc(sizeof(*new_node));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_all(stack, EXIT_FAILURE);
	}

	new_node->n = global_vars->push_number;

	/* Stack mode */
	if (global_vars->mode == 0)
	{
		new_node->prev = NULL;
		new_node->next = !*stack ? NULL : *stack;

		*stack = new_node;
		return;
	}

	/* Queue mode */
	new_node->next = NULL;
	current = *stack;
	if (!current)
	{
		new_node->prev = NULL;

		*stack = new_node;
		return;
	}

	while (current->next)
		current = current->next;

	new_node->prev = current;
	current->next = new_node;
}

/**
 * pall - prints the integers of the whole stack
 * @stack: the stack
 * @line_number: the line number of the script read to display on error
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

/**
 * pint - prints the integer at the top of the stack
 * @stack: the stack
 * @line_number: the line number of the script read to display on error
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_all(stack, EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - deletes the topmost node of the stack
 * @stack: the stack
 * @line_number: the line number of the script read to display on error
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	current = *stack;
	if (!current)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_all(stack, EXIT_FAILURE);
	}

	*stack = current->next;
	free(current);
}

/**
 * swap - swaps the order of the top two nodes of the stack
 * @stack: the stack
 * @line_number: the line number of the script read to display on error
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (stack == NULL || *stack == NULL || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_all(stack, EXIT_FAILURE);
	}

	current = (*stack)->next;
	(*stack)->next = current->next;

	if (current->next != NULL)
		current->next->prev = *stack;

	current->next = *stack;
	(*stack)->prev = current;
	current->prev = NULL;

	*stack = current;
}
