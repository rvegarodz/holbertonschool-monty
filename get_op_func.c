#include "monty.h"
/*
 *
 *
 */
void (*get_op_func(char **tokens))(stack_t **stack, unsigned int)
{
	static instruction_t in_fun[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL},
	};

	int i = 0;

	while (i < 2)
	{
		if (strcmp(tokens[0], in_fun[i].opcode) == 0)
		{
			return (in_fun[i].f);
		}
		i++;
	}
	exit(EXIT_SUCCESS);
}
