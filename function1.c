#include "monty.h"

/**
 * malloc_failed - hanles the error when malloc failed to allocate memory
 */

void malloc_failed(void)
{
	dprintf(2, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}
