#include "monty.h"

/**
 * print_char - print char by its ascii number in list
 *
 * Return: 0 if success
 *
 * @line: the line of the node
*/

int print_char(int line)
{
	if (head == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line);
		return (-1);
	}

	if (head->n > 127 || head->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line);
		return (-1);
	}

	printf("%c\n", head->n);
	return (0);
}
