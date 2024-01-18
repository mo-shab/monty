#include "monty.h"

/**
 * main - The main function
 * @argc: count of arguments
 * @argv: vector of arguments
 * Return: EXIT_SUCCESS on sucess
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	glob.stack_n = 0;
	glob.stack_mode = PUSH_STACK;

	readfile(argv[1]);
	return (EXIT_SUCCESS);
}
