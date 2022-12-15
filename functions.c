#include "monty.h"
char **tokens = NULL;
/**
 * push - push a new node to the stack
 * @stack: list of structs
 * @nine_number: line number
 * Return: node;
 */
void push(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	int p_int;

	stack_t *node = malloc(sizeof(stack_t));

	if (node != NULL)
	{
		p_int = atoi(tokens[1]);

		if (tokens[1] == NULL || !p_int)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free(node);
			free(tokens[0]);
			free(tokens[1]);
			free(tokens);
			exit(EXIT_FAILURE);
		}
		node->prev = NULL;
		node->n = p_int;
		node->next = (*stack);
		*stack = node;
	}
}
/**
 * pall - print all fucntion
 * @stack: linked list of nodes stack
 * @line_number: line number for errors
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void)line_number;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
