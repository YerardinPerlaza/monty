#include "monty.h"
/**
 * main - Entry point
 * @argc: number of command
 * @argv: command line
 * Return: 0
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;

	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);

	global_vars = malloc(sizeof(*global_vars));
	if (global_vars == NULL)
		fprintf(stderr, "Error: malloc failed\n"), exit(EXIT_FAILURE);

	global_vars->file = NULL;
	global_vars->current_line = NULL;
	global_vars->push_number = 0;

	read_monty(argv[1], &stack);

	free(global_vars);
	free_stack(&stack);

	exit(EXIT_SUCCESS);
}
