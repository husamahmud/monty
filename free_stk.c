#include "monty.h"

/**
 * free_dlistint - frees a doubly linked list
 * @head: pointer to the head of the doubly linked list
 * Return: void
 */
void free_dlistint(stack_s *head)
{
	stack_s *temp = head;

	while (temp)
	{
		head = temp->next;
		free(temp);
		temp = head;
	}
}

/**
 * free_stk - frees a stack (doubly linked list)
 * @head: double pointer to the head of the stack
 * Return: void
 */
void free_stk(stack_s **head)
{
	stack_s *temp = NULL;

	if (head == NULL)
		return;

	while (*head)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
	}
}
