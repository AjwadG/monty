#ifndef _MONTY_H
#define _MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>

#define USAGE 0
#define OPEN 1
#define COMMAND 2
#define PUSH 20
#define PINT 21
#define POP 22
#define SWAP 23
#define ADD 24
#define SUB 26
#define DIV 27
#define MUL 28
#define MOD 29
#define PCHAR 30
#define PCHEMP 301
#define PSTR 31
#define ZERO 33
#define MEMORY 3

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
 * struct all_struct - astruct that have everything in the program
 * @fs: fils discriptor
 * @err: error number
 * @file_name: file name
 * @list: pointer to the double linked list
 * @opcode: pointer to instruction_s structure
 * @line: line number
 */
typedef struct all_struct
{
	FILE *fs;
	int err;
	char *file_name;
	stack_t *list;
	char *opcode;
	int line;
} all_t;


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
	void (*f)(all_t *all);
} instruction_t;


/* validate.c */
FILE *validate(int argc, all_t *all);
void handle_err(all_t *all, int errno);
void free_all(all_t *all);
void free_list(stack_t *head);

/* process.c */
void process(all_t *all);
void handle_commands(all_t *all);
void push(all_t *all);
void pall(all_t *all);

/* 1-commands.c */
void add(all_t *all);
void sub(all_t *all);
void mul(all_t *all);
void divi(all_t *all);
void mod(all_t *all);

/* 2-commands.c */
void pint(all_t *all);
void swap(all_t *all);
void pop(all_t *all);
void pchar(all_t *all);
void pstr(all_t *all);

/* lists.c */
stack_t *push_start(stack_t **head, const int n);
stack_t *push_end(stack_t **head, const int n);
void plist(stack_t *h);
int get_len(stack_t *h);
int del_first(stack_t **head);

#endif	/* _MONTY_H */
