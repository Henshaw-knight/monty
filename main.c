#define _POSIX_C_SOURCE 200809L
#include "monty.h"
monty_inst instance_vars = {NULL, NULL, NULL};

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
	stack_t *stack = NULL;
	int exit_status = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	instance_vars.file = file;

	while ((read = getline(&line, &len, file)) != -1)
	{
		instance_vars.line = line;
		line_number++;
		exit_status = execute(&stack, line_number, line);
		if (exit_status == EXIT_FAILURE)
			break;
	}

	free(line);
	free_struct(stack);
	fclose(file);

	return (exit_status);
}
