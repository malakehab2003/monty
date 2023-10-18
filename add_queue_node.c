#include "monty.h"

/**
 * add_queue_node - add node to queue
 *
 * Return: void
 *
 * @arg: the data of the point
 *
 * @line: the line of the node
*/

void add_queue_node(char *arg, int line, FILE *fp)
{
	fclose(fp);
	printf("%s, %d", arg, line);
}
