#include "monty.h"

/**
 * rotate_last - make last element the first
 *
 * Return: void
*/

int rotate_last(void)
{
	stack_t *last, *before_last, *first;

	if (head == NULL)
		return (0);
	if (head->next == NULL)
		return (0);

	last = head;
	while (last->next != NULL)
		last = last->next;
	first = head;
	before_last = last->prev;
	before_last->next = NULL;
	last->prev = NULL;
	last->next = head;
	first->prev = last;
	head = last;
	return (0);
}
