#ifndef HEADER_FILE
#define HEADER_FILE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>

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
 * struct all_struct - astruct that have everything in the program
 * @fd: fils discriptor
 * @err: error number
 * @file_name: file name
 * @list: pointer to the double linked list
 * @inst: pointer to instruction_s structure
 * @line: line number
 */
typedef struct all_struct
{
	FILE *fs;
	int err;
	char *file_name;
	stack_t *list;
	instruction_t *inst;
	int line;
} all_t;





FILE *validate(int argc, all_t *all);
void handle_err(all_t *all, int errno);
void free_all(all_t *all);
void process(all_t *all);

#endif
