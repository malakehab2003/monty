#include "monty.h"

/**
 * print_head - print head node in the list
 *
 * Return: 0 if success
 *
 * @line: the line to execute
*/

int print_head(int line)
{
	if (head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		return (-1);
	}

	printf("%d\n", head->n);
	return (0);
}
