#include "monty.h"

/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 - success; otherwise - error
 */
int main(int argc, char *argv[])
{
	int line_number = 0;
	char *file_path = argv[1];
	FILE *file = fopen(file_path, "r");
	char line[256];

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_path);
		exit(EXIT_FAILURE);
	}


	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;
		tokenize(line, line_number);
	}

	fclose(file);



	return (0);
}

