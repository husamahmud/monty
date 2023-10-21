#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>

#define TRUE  (1==1)

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
} stack_s;

extern stack_s *stk_top;

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

	void (*f)(stack_s **stack, unsigned int line_number);
} instruction_t;

/**
 * struct Fileclose - Structure for file closing operation
 * @file: pointer to the file to be closed
 * @line: pointer to the current line of the file
 * @stack: pointer to the stack for related operations
 * Description: used to facilitate the closing of a file
 */
typedef struct file_close
{
	FILE *file;
	char *line;
	stack_s **stack;
} file_close;

extern file_close f_close;

/* stack operations */
void push(stack_s **stack, unsigned int line_number);

void pall(stack_s **stack, __attribute__((unused)) unsigned int line_number);

void pint(stack_s **stack, unsigned int line_number);

void pop(stack_s **stack, unsigned int line_number);

void swap(stack_s **stack, unsigned int line_number);

/* arithmetic operations */
void add(stack_s **stack, unsigned int line_number);

void sub(stack_s **stack, unsigned int line_number);

void mul(stack_s **stack, unsigned int line_number);

void _div(stack_s **stack, unsigned int line_number);

void mod(stack_s **stack, unsigned int line_number);

/* other operations */
void nope(stack_s **stack, unsigned int line_number);

void pchar(stack_s **stack, unsigned int line_number);

void pstr(stack_s **stack, __attribute__((unused)) unsigned int line_number);

/* utility functions */
instruction_t instruction(char *line, unsigned int line_num, FILE *fd);

void free_dlistint(stack_s *head);

void free_stk(stack_s **head);

#endif
