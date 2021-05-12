#include "monty.h"

/**
 * check_number
 */
int check_number(char *number)
{
	int i;

	for (i = 0; number[i]; number++)
		if (!(number[i] >= '0' && number[i] <= '9'))
			return (1);
	return (0);
}

/* void print_number(void) */
/* { */
/* 	printf("Number = %d\n", push_number); */
/* } */

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int read_monty(char *path, stack_t **stack)
{
	FILE *file;
	char *line, *opcode, *number, *err_1, *err_2, *err_3;
	size_t line_size;
	int l_num;

	err_1 = "Error: Can't open file ";
	err_2 = ": usage: push integer\n";
	err_3 = ": unknown instruction ";
	line = opcode = number = NULL;
	file = global_vars->file = fopen(path, "r");
	if (file == NULL)
		fprintf(stderr, "%s%s\n", err_1, path), exit(EXIT_FAILURE);
	l_num = 0;
	while (getline(&line, &line_size, file) != EOF)
	{
		opcode = strtok(line, " \t\n");
		number = strtok(NULL, " \t\n");
		l_num++;
		if (opcode && strcmp(opcode, "push") == 0)
		{
			if (!number)
				fprintf(stderr, "L%d%s", l_num, err_2), free_error(line, file, stack);
			if (number && check_number(number) == 1)
				fprintf(stderr, "L%d%s", l_num, err_2), free_error(line, file, stack);
			global_vars->push_number = atoi(number);
		}
		printf("opcode = %s, number = %d\n", opcode, global_vars->push_number);
		/* print_number(); */

		if (opcode && select_opcode(opcode, stack,  l_num) == 1)
		{
			fprintf(stderr, "L%d%s%s\n", l_num, err_3, opcode);
			free_error(line, file, stack);
		}
	}
	free(line), fclose(file);
	return (0);
}
