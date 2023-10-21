#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number in the Monty file
 * Return: None
 */
void add(stack_s **stack, unsigned int line_number)
{
	int sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free(f_close.line);
		fclose(f_close.file);
		free_stk(f_close.stack);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->n + (*stack)->next->n;
	pop(stack, line_number);
	(*stack)->n = sum;
}

/**
 * sub - subtracts the top element from the second top element of the stack
 * @stack: pointer to the stack
 * @line_number: line number in the Monty file
 * Return: None
 */
void sub(stack_s **stack, unsigned int line_number)
{
	int sum = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free(f_close.line);
		fclose(f_close.file);
		free_stk(f_close.stack);
		exit(EXIT_FAILURE);
	}

	sum = -((*stack)->n) + (*stack)->next->n;
	pop(stack, line_number);
	(*stack)->n = sum;
}

/**
 * _div - _divides the second top element by the top element of the stack
 * @stack: pointer to the stack
 * @line_number: line number in the Monty file
 * Return: None
 */
void _div(stack_s **stack, unsigned int line_number)
{
	int sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't _div, stack too short\n", line_number);
		free(f_close.line);
		fclose(f_close.file);
		free_stk(f_close.stack);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: _division by zero\n", line_number);
		free(f_close.line);
		fclose(f_close.file);
		free_stk(f_close.stack);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->next->n / (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = sum;
}

/**
 * mul - multiplies the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number in the Monty file
 * Return: None
 */
void mul(stack_s **stack, unsigned int line_number)
{
	int sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free(f_close.line);
		fclose(f_close.file);
		free_stk(f_close.stack);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->n * (*stack)->next->n;
	pop(stack, line_number);
	(*stack)->n = sum;
}

/**
 * mod - computes the modulus of the second top element by the top element
 * @stack: pointer to the stack
 * @line_number: line number in the Monty file
 * Return: None
 */
void mod(stack_s **stack, unsigned int line_number)
{
	int sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free(f_close.line);
		fclose(f_close.file);
		free_stk(f_close.stack);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: _division by zero\n", line_number);
		free(f_close.line);
		fclose(f_close.file);
		free_stk(f_close.stack);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->next->n % (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = sum;
}

