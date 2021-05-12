#include "global.h"
#include "monty.h"

int main(int argc, char *argv[])
{
	/* stack_t *stack = NULL; */

	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);

	read_monty(argv[1]);

	exit(EXIT_SUCCESS);
}
