#include"monty.h"
/**
 * main - interpreter of monty
 * @ac: counting of arguments
 * @av: vector of arguments
 * Return: 
 */

int main(int ac, char **av)
{
	FILE *file;
	char *line = NULL;
	size_t buffline = 0;
	stack_t *stack = NULL;
	unsigned int line_number = 1;

	/* CHECKING NUMBER OF ARGUMENTS */
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	/* OPENING FILE */
	file = fopen(av[1], "r"); 

	/* GETTING TEXT LINE OF OPEN FILE */
	while (getline(&line, &buffline, file) != -1)
	{
		/* TOKENIZATION */
		tokens = tokenization(line, " \n");
		
		/* COMPARE TOKEN AND CALL FUNCTION */
		get_op_func(tokens)(&stack, line_number);

		/* COUNT LINES OF THE FILE PROCESS */
		line_number++;

		free(tokens[1]);
		free(tokens[0]);
		free(tokens);
		/* FREE MEMORY SPACE */
		/*free(tokens);
		free(line);*/
	}
	/* CLOSING FILE */
	free_listint(stack);

	free(line);
	fclose(file);
	return (0);
}
