#include "monty.h"
#include <stdio.h>
arg_t *arguments = NULL;

/**
* main - The main function
* @argc: argument count
* @argv: argument vector
*
* Return: Always succes
*/

int main(int argc, char **argv)
{
	size_t n = 0;

	validate_argum(argc);
	init_args();
	get_stream(argv[1]);

	while (getline(&arguments->line, &n, arguments->stream) != -1)
		printf("%s", arguments->line);

	return (0);
}

