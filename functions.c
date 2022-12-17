#include "monty.h"
char **tokens = NULL;
/**
 * push - push a new node to the stack
 * @stack: linked list of nodes
 * @line_number: line number
 * @line: pointer to string of getline function
 * @file: file in use
 */
void push(stack_t **stack, unsigned int line_number, char *line, FILE *file)
{
	(void) line_number;
	int p_int;

	stack_t *node = malloc(sizeof(stack_t));

	if (node == NULL || tokens[1] == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(tokens[1]);
		free(tokens[0]);
		free(tokens);
		free(line);
		free(node);
		free_listint(*stack);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	if (node != NULL)
	{
		if (tokens[1] != NULL)
		{
			p_int = atoi(tokens[1]);
		}

		if (strcmp(tokens[1], "0") != 0 && p_int == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free(tokens[1]);
			free(tokens[0]);
			free(tokens);
			free(line);
			free(node);
			free_listint(*stack);
			fclose(file);
			exit(EXIT_FAILURE);
		}
		node->prev = NULL;
		node->n = p_int;
		node->next = (*stack);
		if (node->next != NULL)
		{
			node->next->prev = node;
		}
			*stack = node;
	}

}
/**
 * pall - print all on the stack
 * @stack: linked list of nodes
 * @line_number: line number for errors
 * @line: pointer to string of getline function
 * @file: file in use
 */
void pall(stack_t **stack, unsigned int line_number, char *line, FILE *file)
{
	stack_t *temp = *stack;
	(void)line_number;
	(void)line;
	(void)file;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/**
 * free_listint - free struct
 * @stack: linked list of nodes
 */
void free_listint(stack_t *stack)
{
	stack_t *newnode;

	while (stack != NULL)
	{
		newnode = stack;
		stack = newnode->next;
		free(newnode);
	}
}
/**
 * pint - prints the value at the top of the stack
 * @stack: linked list of nodes
 * @line_number: line number for errors
 * @line: pointer to string of getline function
 * @file: file in use
 */
void pint(stack_t **stack, unsigned int line_number, char *line, FILE *file)
{
	(void)line_number;

	if (*stack != NULL)
	{
		printf("%d\n", (*stack)->n);
	}
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free(tokens[1]);
		free(tokens[0]);
		free(tokens);
		free(line);
		fclose(file);
		exit(EXIT_FAILURE);
	}
}

