#include "monty.h"

stack_t *stack = NULL;

/**
 * tokenize - to tokenize the line of the source file
 * @line: line to tokenize
 * @line_number: line number
 */
void tokenize(char *line, unsigned int line_number)
{
	int value;
	char *endptr, *token = strtok(line, " \t\n");

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

			value = strtol(token, &endptr, 10);
			if (*endptr != '\0')
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}

			/**
		*	value = atoi(token);
		*	if (value == 0 && strcmp(token, "0") != 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			*/
			push(&stack, value);
		}
		else if (strcmp(token, "pall") == 0)
			pall(&stack);
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
			exit(EXIT_FAILURE);
		}

		token = strtok(NULL, " \t\n");
	}
}
