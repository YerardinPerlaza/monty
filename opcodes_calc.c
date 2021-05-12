#include "monty.h"

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *head;
	int a, b;

	head = *stack;
	if (!(head && head->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	a = head->n, b = head->next->n;
	pop(stack, line_number);

	head = *stack;
	head->n = a + b;
}
