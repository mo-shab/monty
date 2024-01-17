#include "monty.h"

/**
 * get_stream_fail - handle the error when reading a file failed
 * @fileName: The name of the File
 */

void get_stream_fail(char *fileName)
{
	fprintf(stderr, "Error: Can't open file %s\n", fileName);
	exit(EXIT_FAILURE);
}

/**
 * get_stream - get the stream from a file
 * @fileName: The name of the file
 */

void get_stream(char *fileName)
{
	int file;

	file = open(fileName, O_RDONLY);
	if (file == -1)
		get_stream_fail(fileName);
	arguments->stream = fdopen(file, "r");
	if (arguments->stream == NULL)
	{
		close(file);
		get_stream_fail(fileName);
	}
}
