#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	FILE *file;

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
		/* execute code */
	}

	free(line);
	fclose(file);

	return (0);
}
