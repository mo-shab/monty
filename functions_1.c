#include "monty.h"

/**
 * readfile - Open and read the command file
 * @file: The name of the file
 * Return: Nothing or EXIT_FAILURE on failure
 */
void readfile(char *file)
{
	char *buffer = NULL, *tmp = NULL, *token, command[100];
	FILE *fp;
	size_t len = 0;
	ssize_t read;
	void (*f)(stack_t **, unsigned int);
	int line_n = 0;
	stack_t *stack = NULL;

	fp = fopen(file, "r");
	if (fp == NULL)
	{	fprintf(stderr, "Error: Can't open file %s\n", file), freestack(stack);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&buffer, &len, fp)) != -1)
	{	line_n++;
		if (buffer[0] == '#')
			continue;
		if (tmp != NULL)
			free(tmp);
		tmp = strdup(buffer), token = strtok(tmp, " \t\n\r");
		if (token == NULL)
			continue;
		if (token[0] == '#')
			continue;
		strcpy(command, token), f = check_command(command);
		if (f == NULL)
		{	fprintf(stderr, "L%d: unknown instruction %s\n", line_n, command);
			free(tmp), free(buffer), freestack(stack), fclose(fp);
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, " \n\r\t");
		valnumber(command, token, stack, line_n);
		f(&stack, line_n);
	}
	fclose(fp), free(tmp), free(buffer), freestack(stack);
}

/**
 * valnumber - Integer
 * @command: The opcode command
 * @token: The string wit the number
 * @stack: The current stack
 * @line_n: The current line of the file
 * Return: EXIT_FAILURE on failure
 */

int valnumber(char *command, char *token, stack_t *stack, unsigned int line_n)
{
	char number[100];
	int i = 0;

	if (strcmp(command, "push") == 0)
	{
		if (token == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_n);
			freestack(stack);
			exit(EXIT_FAILURE);
		}

		strcpy(number, token);
		while (*token != '\0')
		{
			if (isdigit(*token) == 0)
			{
				if (i != 0 && *token != '-')
				{
					fprintf(stderr, "L%d: usage: push integer\n", line_n);
					freestack(stack);
					exit(EXIT_FAILURE);
				}
			}
			token++, i++;
		}
		glob.stack_n = atoi(number);
	}
	return (EXIT_SUCCESS);
}

/**
 * set_number - Set the number of line
 * @number: The number
 * Return: Nothing
 */
void set_number(char *number)
{
	int glob_n;

	if (strlen(number) > 0)
	{
		glob_n = atoi(number);
		printf("%d\n", glob_n);
	}
}

/**
 * freestack- Free the memory
 * @stack: The stack
 */
void freestack(stack_t *stack)
{
	stack_t *node = stack;

	while (stack != NULL)
	{
		node = stack;
		stack = stack->next;
		free(node);
	}
}

/**
 * check_command - CMonty command validation
 * @command: The command
 * Return: Nothing
 */
void (*check_command(char *command))(stack_t **, unsigned int)
{
	instruction_t ins_t[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"mul", mul},
		{"div", _div},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", stack},
		{"queue", queue}
	};
	unsigned int i;

	for (i = 0; i < (sizeof(ins_t) / sizeof(instruction_t)); i++)
	{
		if (strcmp(command, ins_t[i].opcode) == 0)
			return (ins_t[i].f);
	}
	return (NULL);
}

