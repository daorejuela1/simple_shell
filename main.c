#include "holberton.h"

/**
 * main - reads the user input and checks if is valid
 *@argc: quantity of arguments
 *@argv: value of the arguments
 *Return: Always 0
 */
int main(int argc, char *argv[])
{
	int counter = 0, read = 0, status = 0;
	char *en_variable = NULL, start = 1;
	char *line = NULL;
	size_t len = 0;

	en_variable = _getenv("PATH");
	if (argc > 1)
	{
		errno_lin_st(argv[0], argv[1]);
	}
	if (isatty(fileno(stdin)))
	{
		/*interactive mode*/
		while (start)
		{
			_puts("$ ");
			read =  getline(&line, &len, stdin);
			counter++;
			if (read == -1)
			{
				_puts("\n");
				break;
			}
			status = create_process(line, counter, en_variable, argv, &start, &status);
		}
	}
	else
	{
		/*non interactive mode*/
		while ((read = getline(&line, &len, stdin)) != -1)
		{
			counter++;
			status = create_process(line, counter, en_variable, argv, &start, &status);
		}
	}
	free(en_variable);
	free(line);
	return (status);
}
