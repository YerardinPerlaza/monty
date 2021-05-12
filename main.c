#include "monty.h"
/**
 * main - entry point
 * @argc: number of arguments
 * @argv: the list of arguments
 *
 * Return: 0 if success, 1 if failure
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
	global_vars->mode = 0;

	if (read_monty(argv[1], &stack) == 1)
		free_all(&stack, EXIT_FAILURE);
	else
		free_all(&stack, EXIT_SUCCESS);

	exit(EXIT_SUCCESS);
}
