#include "monty.h"

stack_t *stack = NULL;

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
			token = strtok(NULL, " \t\n");
			if (token == NULL)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			push(&stack, atoi(token), 0);
		}
		else if (strcmp(token, "pall") == 0)
		{

		} else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
			exit(EXIT_FAILURE);
		}

		token = strtok(NULL, " \t\n");
	}
}
