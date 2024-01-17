#ifndef _MONTY_H
#define _MONTY_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct arg_s - struct that hold variables
 * @stream: FIle that connect the file to stream
 * @line: string that get the line from the stream
 *
 * Description: get the variables that will be used as opcode
 */
typedef struct arg_s
{
	FILE *stream;
	char *line;
} arg_t;

extern arg_t *arguments;

void validate_argum(int argc);
void init_args();
void malloc_failed(void);
#endif
