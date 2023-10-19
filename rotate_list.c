#include "monty.h"

/**
 * rotate_list - rotate a list
 *
 * Return: 0 if success
*/

int rotate_list(void)
{
	stack_t *last, *first;

	if (head == NULL)
		return (0);
	last = head;
	first = head;
	while (last->next != NULL)
		last = last->next;
	head = head->next;
	first->next = NULL;
	first->prev = last;
	last->next = first;
	return (0);
}
