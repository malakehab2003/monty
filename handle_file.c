#include "monty.h"

/**
 * handle_file - open and read the file
 *
 * Return: void
 *
 * @file: the file to handle
*/

void handle_file(char *file_read)
{
        FILE *fp;
        char *buffer = NULL, *command, *arg;
        size_t size = 0;
        int line, is_stack = 1, error;

        fp = fopen(file_read, "r");
        if (fp == NULL)
        {
		if (head != NULL)
			free_list(head);
                fprintf(stderr, "Error: Can't open file %s\n", file_read);
                exit (EXIT_FAILURE);
        }
        for (line = 1; getline(&buffer, &size, fp) != -1; line++)
        {
		command = strtok(buffer, " \n");
		if (strcmp(command, "queue") == 0)
		{
			is_stack = 0;
			free(buffer);
			continue;
		}
		arg = strtok(NULL, " ");
		error = choose_func(command, arg, line, is_stack, fp);
		if (error == -1)
			break;
        }
	free(buffer);
	fclose(fp);
	if (error == -1)
	{
		free_list(head);
		exit (EXIT_FAILURE);
	}
}

/**
 * choose_func - choose the function to execute
 *
 * Return: void
 *
 * @command: the command to execute
 *
 * @arg: the args to the command
 *
 * @line: the number of the line executing
 *
 * @is_stack: if queue or stack
 *
*/

int choose_func(char *command, char *arg, int line, int is_stack, FILE *fp)
{
	if (strcmp(command, "push") == 0 && is_stack == 1)
		return (add_stack_node(arg, line));
	else if (strcmp(command, "push") == 0 && is_stack == 0)
		add_queue_node(arg, line, fp);
	else if (strcmp(command, "pall") == 0)
		return (print_nodes());
	else
	{
		fprintf(stderr, "L %d:  unknown instruction %s\n", line, command);
		return (-1);
	}
	return (0);
}

