#include "monty.h"

/**
 * queue - prints the top
 * @head: stack head
 * @line_number: line number
*/
void queue(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
	bus.lifi = 1;
}

/**
 * addqueue - add node to the tail stack
 * @n: new value to be added
 * @head: head of the stack
*/
void addqueue(stack_t **head, int n)
{
	stack_t *new_node, *temp;

	temp = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->next = NULL;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
	}
	if (!temp)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		temp->next = new_node;
		new_node->prev = temp;
	}
}
