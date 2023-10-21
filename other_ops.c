#include "monty.h"

/**
 * nope - does nothing
 * @stack: pointer to the stack
 * @line_number: line number of the instruction
 * Return: None
 */
void nope(stack_s **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

/**
 * pchar - prints the character at the top of the stack
 * @stack: pointer to the stack
 * @line_number: line number of the instruction
 * Return: None
 */
void pchar(stack_s **stack, unsigned int line_number)
{
	int c;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free(f_close.line);
		fclose(f_close.file);
		free_stk(f_close.stack);
		exit(EXIT_FAILURE);
	}

	c = (*stack)->n;
	if (c < 0 || c > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free(f_close.line);
		fclose(f_close.file);
		free_stk(f_close.stack);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", c);
}

/**
 * pstr - prints the string starting from the top of the stack
 * @stack: pointer to the stack
 * @line_number: line number of the instruction
 * Return: None
 */
void pstr(stack_s **stack, __attribute__((unused)) unsigned int line_number)
{
	char buff[100];
	int i = 0;
	stack_s *curr = *stack;

	if (*stack == NULL)
	{
		putchar('\n');
		return;
	}


	while (curr != NULL && curr->n != 0 && curr->n >= 0 && curr->n <= 127)
	{
		buff[i++] = curr->n;
		curr = curr->next;
	}

	buff[i] = '\0';
	printf("%s\n", buff);
}
