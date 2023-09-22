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


/**
 * sub - function to subtract the top element from the second top element
 * @stack: structure for the stack
 * @line_number: line number
 *
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n - (*stack)->n;

	temp = *stack;
	*stack = (*stack)->next;

	if (*stack)
		(*stack)->prev = NULL;

	free(temp);

	(*stack)->n = result;
}


/**
 * my_div - function to divide the second top element by the top element
 * @stack: structure for the stack
 * @line_number: line number
 *
 */
void my_div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	double result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n / (*stack)->n;

	temp = *stack;
	*stack = (*stack)->next;

	if (*stack)
		(*stack)->prev = NULL;

	free(temp);

	(*stack)->n = result;
}



/**
 * nop - function for the nop opcode (does nothing)
 * @stack: structure for the stack
 * @line_number: line number
 *
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
