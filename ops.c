#include "monty.h"

/**
 * push - Function to push an element onto the stack or queue
 * @stack: structure for the stack
 * @value: value to push
 * @is_queue: is queue flag
 *
 */
void push(stack_t **stack, int value, int is_queue)
{
	stack_t *last, *new_node;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;

	if (is_queue)
	{
		new_node->prev = NULL;
		new_node->next = NULL;

		if (*stack == NULL)
			*stack = new_node;
		else
		{
			last = *stack;

			while (last->next)
				last = last->next;

			last->next = new_node;
			new_node->prev = last;
		}
	}
	else
	{
		new_node->prev = NULL;
		new_node->next = *stack;

		if (*stack)
			(*stack)->prev = new_node;

		*stack = new_node;
	}
}


/**
 * pint - function to print the top element of the stack
 * @stack: structure for the stack
 * @line_number: line number
 *
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}


/**
 * pop - function to remove the top element of the stack
 * @stack: structure for the stack
 * @line_number: line number
 *
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack)
	{
		(*stack)->prev = NULL;
	}

	free(temp);
}
