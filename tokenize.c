#include "monty.h"

/**
 * tokenize - to tokenize the line of the source file
 * @line: line to tokenize
 * @line_number: line number
 */
void tokenize(char *line, int line_number)
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
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
			exit(EXIT_FAILURE);
		}

		token = strtok(NULL, " \t\n");
	}
}
