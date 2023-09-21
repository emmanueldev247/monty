#include "monty.h"

/**
 * tokenize - to tokenize the line of the source file
 * @line: line to tokenize
 */
void tokenize(char *line)
{
	char *token = strtok(line, " \t\n");

	while (token != NULL)
	{
		if (strcmp(token, "push") == 0)
		{

		} else if (strcmp(token, "pall") == 0)
		{

		} else
		{
			fprintf(stderr, "L<line_number>: unknown instruction %s\n", token);
			exit(EXIT_FAILURE);
		}

		token = strtok(NULL, " \t\n");
	}
}
