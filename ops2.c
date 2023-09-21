#include "monty.h"


/**
 * add - function to add the top two elements of the stack
 * @stack: structure for the stack
 * @line_number: line number
 *
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->n + (*stack)->next->n;

	temp = *stack;
	*stack = (*stack)->next;

    if (*stack)
		(*stack)->prev = NULL;

	free(temp);

	(*stack)->n = result;
}