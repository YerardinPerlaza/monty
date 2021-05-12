#include "monty.h"

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *head;
	int a, b;

	head = *stack;
	if (!(head && head->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_error(stack);
	}

	b = head->n, a = head->next->n;
	pop(stack, line_number);

	head = *stack;
	head->n = a + b;
}

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *head;
	int a, b;

	head = *stack;
	if (!(head && head->next))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_error(stack);
	}

	b = head->n, a = head->next->n;
	pop(stack, line_number);

	head = *stack;
	head->n = a - b;
}

void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *head;
	int a, b;

	head = *stack;
	if (!(head && head->next))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_error(stack);
	}

	b = head->n, a = head->next->n;
	pop(stack, line_number);

	head = *stack;
	head->n = a * b;
}

void divi(stack_t **stack, unsigned int line_number)
{
	stack_t *head;
	int a, b;

	head = *stack;
	if (!(head && head->next))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_error(stack);
	}

	b = head->n, a = head->next->n;
	if (b == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_error(stack);
	}
	pop(stack, line_number);

	head = *stack;
	head->n = a / b;
}

void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *head;
	int a, b;

	head = *stack;
	if (!(head && head->next))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_error(stack);
	}

	b = head->n, a = head->next->n;
	if (b == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_error(stack);
	}
	pop(stack, line_number);

	head = *stack;
	head->n = a % b;
}
