#include "monty.h"

/**
 * mod - function to computes the rest of the division of the second top
 *		element of the stack by the top element of the stack
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


/**
 * pchar - Prints the character at the top of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number of the opcode in the Monty file.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int value;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = (*stack)->n;

	if (value < 0 || value > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	putchar(value);
	putchar('\n');
}


/**
 * pstr - Prints the string starting at the top of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: line number
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current && current->n != 0 && (current->n >= 0 && current->n <= 127))
	{
		putchar(current->n);
		current = current->next;
	}

	putchar('\n');
}


/**
 * rotl - Rotates the stack to the top.
 * @stack: Double pointer to the stack.
 * @line_number: line number
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second, *current;
	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	first = *stack;
	second = first->next;
	current = second;

	while (current->next)
		current = current->next;

	*stack = second;
	current->next = first;
	first->prev = current;
	second->prev = NULL;
	first->next = NULL;
}


/**
 * rotr - Rotates the stack to the bottom.
 * @stack: Double pointer to the stack.
 * @line_number: line number
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;


	if (*stack == NULL || (*stack)->next == NULL)
		return;

	current = *stack;

	while (current->next != NULL)
		current = current->next;

	current->prev->next = NULL;
	current->next = *stack;
	current->prev = NULL;
	(*stack)->prev = current;
	*stack = current;
}
