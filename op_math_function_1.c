#include "monty.h"

/**
 *_sub- sustration
 *@head: stack head
 *@counter: line_number
 *Return: Nothing
 */
void _sub(stack_t **head, unsigned int counter)
{
	stack_t *current;
	int sus, nodes;

	current = *head;
	for (nodes = 0; current != NULL; nodes++)
		current = current->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	current = *head;
	sus = current->next->n - current->n;
	current->next->n = sus;
	*head = current->next;
	free(current);
}


/**
 * _div - divides the top two elements of the stack.
 * @head: head of the stack
 * @counter: line_number
 * Return: Nothing
 */

void _div(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, current;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	current = h->next->n / h->n;
	h->next->n = current;
	*head = h->next;
	free(h);
}

/**
 * _mul - multiplies the top two elements of the stack.
 * @head: head of the stack
 * @counter: line_number
 * Return: Nothing
 */
void _mul(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, current;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	current = h->next->n * h->n;
	h->next->n = current;
	*head = h->next;
	free(h);
}

/**
 * _mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @head: head of the stack
 * @counter: line_number
 * Return: Nothing
 */
void _mod(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, current;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	current = h->next->n % h->n;
	h->next->n = current;
	*head = h->next;
	free(h);
}
