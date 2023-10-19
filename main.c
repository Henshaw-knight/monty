#include <stdio.h>
#include <stdlib.h>
char *monty_arg = NULL;

/**
 * main - Entry point, interpreter for Monty bytecodes files
 *
 * @argc: argument count
 * @argv: argument vector, monty file location
 *
 * Return: 0 (on Success)
 */

int main(int argc, char *argv[])
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	FILE *file;
	size_t line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		EXIT(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		/* execute code */
	}

	free(line);
	fclose(file);

	return (0);
}
