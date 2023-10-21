#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>


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

extern stack_t *stk_top;

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
	stack_t **stack;
} file_close;

extern file_close f_close;

/* stack operations */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);

/* arithmetic operations */
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void div(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);

/* other operations */
void nope(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, __attribute__((unused)) unsigned int line_number);

/* utility functions */
instruction_t instruction(char *line, unsigned int line_num, FILE *fd);
void free_dlistint(stack_t *head);
void free_stk(stack_t **head);

#endif
