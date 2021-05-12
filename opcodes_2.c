#include "monty.h"

/**
 * nop - doesn't do anything
 * @stack: the stack
 * @line_number: the line number of the script read to display on error
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * pchar - print a character
 * @stack: stack
 * @line_number: unsigned int
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int c;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_all(stack, EXIT_FAILURE);
	}

	c = (*stack)->n;
	if (!(((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z'))))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_all(stack, EXIT_FAILURE);
	}
	printf("%c\n", c);
}


/**
 * pstr - prints a string of characters
 * @stack: the stack
 * @line_number: the line number of the script read to display on error
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;

	current = *stack;
	while (current && (current->n > 0 && current->n <= 127))
	{
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
}

/**
 * rotl - sends the head of the stack to the tail
 * @stack: the stack
 * @line_number: the line number of the script read to display on error
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *current, *rot, *head;

	(void)line_number;

	if (!stack || !*stack || !(*stack)->next)
		return;

	current = rot = *stack;
	head = (*stack)->next;

	while (current->next)
		current = current->next;

	current->next = rot;
	rot->prev = current;
	rot->next = NULL;

	*stack = head;
}

/**
 * rotr - sends the tail of the stack to the head
 * @stack: the stack
 * @line_number: the line number of the script read to display on error
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tail, *head, *rot;

	(void)line_number;

	if (!stack || !*stack || !(*stack)->next)
		return;

	tail = head = *stack;

	while ((tail->next)->next)
		tail = tail->next;
	rot = tail->next;

	tail->next = NULL;
	rot->prev = NULL;

	rot->next = head;
	head->prev = rot;

	*stack = rot;
}
