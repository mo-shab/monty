#include "monty.h"

/**
 * init_args - function that initialize a pointer to a struct
 */

void init_args()
{
	arguments = malloc(sizeof(arg_t));
	if (arguments == NULL)
		malloc_failed();
	arguments=>stream = NULL;
	arguments=>line = NULL;
}
