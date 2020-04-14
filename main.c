#include "holberton.h"

/**
 * main - reads the user input and checks if is valid
 *@argc: quantity of arguments
 *@argv: value of the arguments
 *Return: Always 0
 */
int main(int argc, char *argv[])
{
	int read, status = 0, data_length = 0, counter = 0;
	char interactive = 0, *line = NULL, **command = NULL;
	char *variable, **full_path = NULL;
	struct stat st;
	size_t len = 0;

	if (argc > 1)
	{
		errno_lin_st(argv[0], argv[1]);
	}
	variable = _getenv("PATH");
	if (isatty(fileno(stdin)))
		interactive = 1;
	else
		interactive = 0;
	while (1)
	{
		if (interactive)
			_puts("$ ");
		read =  getline(&line, &len, stdin);
		counter++;
		if (read == -1)
		{
			_puts("\n");
			break;
		}
		command = extract_string(line, &data_length);
		if (command[0] != NULL)
			{
			if (stat(command[0], &st) == 0 && access(command[0], X_OK) == 0)
				process_selector(command, &status);
			else if (stat(command[0], &st) == 0 && access(command[0], X_OK) != 0)
				status = errno_per(argv[0], counter, command[0]);
			else if (stat(command[0], &st) != 0)
			{
				full_path = path_searcher(command, &data_length, variable);
				if (full_path == NULL)
					status = errno_found(argv[0], counter, command[0]);
				else if (stat(full_path[0], &st) == 0 && access(full_path[0], X_OK) != 0)
					status = errno_per(argv[0], counter, command[0]);
				else if (stat(full_path[0], &st) == 0 && access(full_path[0], X_OK) == 0)
					process_selector(full_path, &status);
			}
			free_grid(command, data_length);
			data_length = 0;
			if (interactive == 0)
				break;
			}
	}
	free(line);
	return (status);
}
