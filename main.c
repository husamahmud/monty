#include "monty.h"

file_close f_close = {NULL};


/**
 * main - entry point of the Monty interpreter
 * @argc: the number of command-line arguments
 * @argv: an array of command-line argument strings
 * Return: the exit status of the program
 */
int main(int argc, char *argv[])
{
	FILE *fd;
	size_t n = 0;
	char *line = NULL;
	unsigned int line_num = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");
	f_close.file = fd;
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if (fd)
	{
		while (getline(&line, &n, fd) != -1)
		{
			line_num++;
			f_close.line = line;
			instruction(line, line_num, fd);
		}

		free(f_close.line);
		fclose(fd);
		free_stk(f_close.stack);
	}

	free_stk(f_close.stack);
	return (0);
}
