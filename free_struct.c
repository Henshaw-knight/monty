#include "monty.h"

/**
 * free_struct - function that frees a stack_s data structure
 *
 * @head: pointer to the first node
 *
 * Return: Nothing (void)
 */
void free_struct(stack_t *head)
{
	stack_t *temp;

	if (head == NULL)
		return;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
