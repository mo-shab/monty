#include "monty.h"

struct global glob;

/**
 * push - function to push the value on top of the stack
 * @stack: The stack
 * @line_number: The current file line number
 * Return: Nothing or EXIT_FAILURE on failure
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	stack_t *tail;

	(void) line_number;
	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		freestack(*stack);
		exit(EXIT_FAILURE);
	}

	if (glob.stack_mode == PUSH_STACK || !*stack)
	{
		node->next = *stack;
		node->prev = NULL;
		node->n = glob.stack_n;
		*stack = node;
	}
	else if (glob.stack_mode == PUSH_QUEUE)
	{
		tail = *stack;
		while (tail->next)
		{
			tail = tail->next;
		}
		node->next = NULL;
		node->prev = tail;
		node->n = glob.stack_n;
		tail->next = node;
	}
}

/**
 * pall - print the elements on the stack
 * @stack: The stack
 * @line_number: The current file line number
 * Return: Nothing
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	(void) line_number;
	node = *stack;
	while (node)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}
