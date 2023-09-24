#include "monty.h"

/**
 * tokenize - to tokenize the line of the source file
 * @line: line to tokenize
 * @line_number: line number
 * @stack: stack
 */
void tokenize(char *line, stack_t **stack, unsigned int line_number)
{
	unsigned int i = 0;
	char *token = strtok(line, " \t\n");
	instruction_t opcodes[] = {
		{"push", push}, {"pall", pall},
		{"pint", pint},	{"pop", pop},
		{"swap", swap}, {"add", add},
		{"nop", nop}, {"sub", sub},
		{"div", my_div}, {"mul", mul},
		{"mod", mod}, {"pchar", pchar},
		{"pstr", pstr}, {"rotl", rotl},
		{"rotr", rotr},	{"queue", queue},
		{"stack", my_stack}, {NULL, NULL}
	};


	if (token && token[0] == '#')
		return;
	bus.arg = strtok(NULL, " \n\t");
	while (opcodes[i].opcode && token)
	{
		if (strcmp(token, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(stack, line_number);
			return;
		}
		i++;
	}

	if (token && opcodes[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
		fclose(bus.file);
		free(line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}

/**
* free_stack - frees the stack -> a doubly linked list
* @stack: head of the stack
*/
void free_stack(stack_t *stack)
{
	stack_t *temp;

	temp = stack;
	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
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
