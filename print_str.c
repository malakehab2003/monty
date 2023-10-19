#include "monty.h"

/**
 * print_str - print string in ascii in list
 *
 * Return: 0 if success
*/

int print_str(void)
{
	stack_t *new;

	if (head == NULL)
	{
		printf("\n");
		return (0);
	}

	new = head;
	while (new != NULL)
	{
		if (new->n > 127 || new->n <= 0)
			break;
		printf("%c", new->n);
		new = new->next;
	}
	printf("\n");
	return (0);
}
