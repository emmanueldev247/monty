#include "monty.h"

bus_t bus = {NULL, NULL, NULL, 0};

/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 - success; otherwise - error
 */
int main(int argc, char *argv[])
{
	const char *file_path = argv[1];
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	read_file(file_path, stack);

	return (EXIT_SUCCESS);
}

/**
  *read_file - function to open and read the Monty ByteCode file
  * @file_path: file to be read
  * @stack: stack
  */
void read_file(const char *file_path, stack_t *stack)
{
	FILE *file = fopen(file_path, "r");
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;

	bus.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_path);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &len, file) != -1)
	{
		bus.line = line;
		line_number++;
		tokenize(line, &stack, line_number);
		free(line);
		line = NULL;
	}
	free_stack(stack);

	fclose(file);
	if (line != NULL)
		free(line);
}
