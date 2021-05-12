#include "monty.h"

/**
 * add - adds two numbers
 * @stack: the stack
 * @line_number: the line number of the script read to display on error
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *head;
	int a, b;

	head = *stack;
	if (!(head && head->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_all(stack, EXIT_FAILURE);
	}

	b = head->n, a = head->next->n;
	pop(stack, line_number);

	head = *stack;
	head->n = a + b;
}

/**
 * sub - subtracts two numbers
 * @stack: the stack
 * @line_number: the line number of the script read to display on error
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *head;
	int a, b;

	head = *stack;
	if (!(head && head->next))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_all(stack, EXIT_FAILURE);
	}

	b = head->n, a = head->next->n;
	pop(stack, line_number);

	head = *stack;
	head->n = a - b;
}

/**
 * mul - multiplies two numbers
 * @stack: the stack
 * @line_number: the line number of the script read to display on error
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *head;
	int a, b;

	head = *stack;
	if (!(head && head->next))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_all(stack, EXIT_FAILURE);
	}

	b = head->n, a = head->next->n;
	pop(stack, line_number);

	head = *stack;
	head->n = a * b;
}

/**
 * divi - divides two numbers
 * @stack: the stack
 * @line_number: the line number of the script read to display on error
 */
void divi(stack_t **stack, unsigned int line_number)
{
	stack_t *head;
	int a, b;

	head = *stack;
	if (!(head && head->next))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_all(stack, EXIT_FAILURE);
	}

	b = head->n, a = head->next->n;
	if (b == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_all(stack, EXIT_FAILURE);
	}
	pop(stack, line_number);

	head = *stack;
	head->n = a / b;
}

/**
 * mod - calculates the modulo of two numbers
 * @stack: the stack
 * @line_number: the line number of the script read to display on error
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *head;
	int a, b;

	head = *stack;
	if (!(head && head->next))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_all(stack, EXIT_FAILURE);
	}

	b = head->n, a = head->next->n;
	if (b == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_all(stack, EXIT_FAILURE);
	}
	pop(stack, line_number);

	head = *stack;
	head->n = a % b;
}
