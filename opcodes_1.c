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
/**
 * pint - print int at the top of stack
 * @stack: stack
 * @line_number: unsigned int
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - delete in the stack
 * @stack: stack
 * @line_number: unsigned int
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	current = *stack;
	if (!current)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = current->next;
	free(current);
}
/**
 * pop - delete in the stack
 * @stack: stack
 * @line_number: unsigned int
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
        stack_t *current;

	if (stack == NULL || *stack == NULL || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
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
