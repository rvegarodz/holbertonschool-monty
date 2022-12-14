#include "monty.h"

int main(int ac, char **av)
{
	FILE *file;
	char *line = NULL;
	size_t buffline = 0;
	
	char **result = malloc(sizeof(char *));
	char *token;
	int result_index = 0;

	/* checking number of argument */
	if (ac != 2)
		exit(EXIT_FAILURE);

	/* opening file */
	file = fopen(av[1], "r"); 

	/* getting text of open file */
	while (getline(&line, &buffline, file) != -1)
	{
		/* TOKENIZATION */
		token = strtok(line, " \n");
		while (token)
		{
			result[result_index] = token;
			result_index++;
			
			/* Condition to realloc memory space for result */
			if (result_index >= 2)
			{
			       result_index = result_index * 2;
			       result = realloc(result, result_index * sizeof(char *));
			}

			/* tokenize again from the last position */
			token = strtok(NULL, " \n");
		}

		/* printing for test */
		printf("%s\n", result[0]);
	}

	/* closing file */
	fclose(file);

	return (0);
}
