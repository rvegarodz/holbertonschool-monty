#include "monty.h"
/*
 *
 *
 */
void (*get_op_func(char **tokens))(stack_t **stack, unsigned int line_number, char *line, FILE *file)
{
	static instruction_t in_fun[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{NULL, unkn_func},
	};

	int i = 0;

	
	while (i < 3)
	{
		if (strcmp(tokens[0], in_fun[i].opcode) == 0)
		{
			return (in_fun[i].f);
		}
		i++;
	}
	return (in_fun[i].f);
}
