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
				push_error(line_number);
			value = strtol(token, &endptr, 10);
			if (*endptr != '\0')
				push_error(line_number);
			push(&stack, value);
		} else if (strcmp(token, "pall") == 0)
			pall(&stack);
		else if (strcmp(token, "pint") == 0)
			pint(&stack, line_number);
		else if (strcmp(token, "pop") == 0)
			pop(&stack, line_number);
		else if (strcmp(token, "swap") == 0)
			swap(&stack, line_number);
		else if (strcmp(token, "add") == 0)
			add(&stack, line_number);
		else if (strcmp(token, "sub") == 0)
			sub(&stack, line_number);
		else if (strcmp(token, "div") == 0)
			my_div(&stack, line_number);
		else if (strcmp(token, "mul") == 0)
			mul(&stack, line_number);
		else if (strcmp(token, "mod") == 0)
			mod(&stack, line_number);
		else if (strcmp(token, "nop") == 0)
			nop(&stack, line_number);
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, " \t\n");
	}
}

/**
 * push_error - function to print error for push opcode
 * @line_number: error line number
 */
void push_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
}


/**
 * cleanup - frees the stack
 */
void cleanup(void)
{
	stack_t *temp;

	temp = stack;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
