#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: pointer to the stack
 * @line_number: line number in the Monty file
 * Return: None
 */
void push(stack_s **stack, unsigned int line_number)
{
	stack_s *new_node = malloc(sizeof(stack_s));

	f_close.stack = &stk_top;
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_dlistint(*stack);
		free_dlistint(new_node);
		free(f_close.line);
		free(stk_top);
		fclose(f_close.file);
		exit(EXIT_FAILURE);
	}

	new_node->n = line_number;
	new_node->next = *stack;
	new_node->prev = NULL;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
	stk_top = *stack;
}

/**
 * pall - prints all the elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number in the Monty file
 * Return: None
 */
void pall(stack_s **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_s *curr = *stack;

	if (curr == NULL)
		return;

	while (curr)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}

/**
 * pint - prints the value at the top of the stack
 * @stack: pointer to the stack
 * @line_number: line number in the Monty file
 * Return: None.
 */
void pint(stack_s **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free(f_close.line);
		fclose(f_close.file);
		free_stk(f_close.stack);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element from the stack
 * @stack: pointer to the stack
 * @line_number: line number in the Monty file
 * Return: None
 */
void pop(stack_s **stack, unsigned int line_number)
{
	stack_s *temp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free(f_close.line);
		fclose(f_close.file);
		free_stk(f_close.stack);
		exit(EXIT_FAILURE);
	}

	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(temp);
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number in the Monty file
 * Return: None
 */
void swap(stack_s **stack, unsigned int line_number)
{
	stack_s *first = *stack;
	stack_s *sec = (*stack)->next;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free(f_close.line);
		fclose(f_close.file);
		free_stk(f_close.stack);
		exit(EXIT_FAILURE);
	}

	first->next = sec->next;
	first->prev = sec;
	sec->next = first;
	sec->prev = NULL;
	*stack = sec;
}
