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
        int line, is_stack = 1;

        fp = fopen(file_read, "r");
        if (fp == NULL)
        {
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
		free(buffer);
		choose_func(command, arg, line, is_stack, fp);
        }
	fclose(fp);
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

void choose_func(char *command, char *arg, int line, int is_stack, FILE *fp)
{
	if (strcmp(command, "push") == 0 && is_stack == 1)
		add_stack_node(arg, line);
	else if (strcmp(command, "push") == 0 && is_stack == 0)
		add_queue_node(arg, line);
	else if (strcmp(command, "pall") == 0)
		print_nodes();
	else
	{
		fclose(fp);
		free_list(head);
		fprintf(stderr, "L %d:  unknown instruction %s\n", line, command);
		exit (EXIT_FAILURE);
	}
}

