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

	stack_t *node = malloc(sizeof(stack_t));

	node->prev = NULL;
	node->n = atoi(tokens[1]);
	node->next = (*stack);
	*stack = node;
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

/*int main(void)
{
	stack_t *stack;

	push(&stack, 0);
	push(&stack, 1);
	push(&stack, 2);
	push(&stack, 3);
	return (EXIT_SUCCESS);
	
}*/
