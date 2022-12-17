#include "monty.h"
/**
 * unkn_func - print error message and free memory
 * @stack: stack
 * @line_number: number of line
 * @line: pointer to line
 * @file: opened file
 */
void unkn_func(stack_t **stack, unsigned int line_number, char *line, FILE *file)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, tokens[0]);
	free(tokens[1]);
	free(tokens[0]);
	free(tokens);
	free(line);
	free_listint(*stack);
	fclose(file);
	exit(EXIT_FAILURE);
}

