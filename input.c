#include <stdio.h>
/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int read_monty(char *path)
{
	FILE *file;
	int line_number;

	file = fopen(path,"r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: file not open\n");
		exit(EXIT_FAILURE);
	}

	return (0);
}
