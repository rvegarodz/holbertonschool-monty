#include "monty.h"
/**
 * main - read command arguments, opens file
 *
 */

int main(int ac, char **av)
{
	FILE *file;
	char *line = NULL;
	size_t buffline = 0;
	stack_t *stack = NULL;
	unsigned int line_number = 0;


	/* checking number of argument */
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	/* opening file */
	file = fopen(av[1], "r"); 

	/* getting text of open file */
	while (getline(&line, &buffline, file) != -1)
	{
		/* TOKENIZATION */
		tokens = tokenization(line, " \n");

		if (strcmp(tokens[0], "push") == 0)
		{
			push(&stack, line_number);
		}
		if (strcmp(tokens[0], "pall") == 0)
		{
			pall(&stack, line_number);
		}
	}

	/* closing file */
	fclose(file);

	return (0);
}