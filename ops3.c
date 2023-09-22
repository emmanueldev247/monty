#include "monty.h"

/**
 * mod - function to computes the rest of the division of the second top
 			element of the stack by the top element of the stack
 * @stack: structure for the stack
 * @line_number: line number
 *
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	double result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n % (*stack)->n;

	temp = *stack;
	*stack = (*stack)->next;

	if (*stack)
		(*stack)->prev = NULL;

	free(temp);

	(*stack)->n = result;
}
