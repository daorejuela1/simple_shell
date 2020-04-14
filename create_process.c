#include "holberton.h"
/**
 *create_process - executes the shell main logic checking
 *if a file is worth
 *@line: getline buffer argument
 *@counter: line counter
 *@envariable: enviroment variable
 *@argv: main parameters
 *Return: modified path or null if failed
 */
int create_process(char *line, int counter, char *en_variable, char *argv[], char *start, int *status)
{
	int data_length = 0;
	char **command = NULL;
	char *full_path = NULL;
	struct stat st;

	command = extract_string(line, &data_length);
	if (command[0] != NULL)
		{
		if (_strcmp(command[0], "exit") == 0)
		{
			free_grid(command, data_length);
			*start = 0;
			return (*status);
		}
		else if (stat(command[0], &st) == 0 && access(command[0], X_OK) == 0)
			process_selector(command[0], command, status);
		else if (stat(command[0], &st) == 0 && access(command[0], X_OK) != 0)
			*status = errno_per(argv[0], counter, command[0]);
		else if (stat(command[0], &st) != 0)
		{
			full_path = path_searcher(command, en_variable);
			if (full_path == NULL)
				*status = errno_found(argv[0], counter, command[0]);
			else if (stat(full_path, &st) == 0 && access(full_path, X_OK) != 0)
				*status = errno_per(argv[0], counter, command[0]);
			else if (stat(full_path, &st) == 0 && access(full_path, X_OK) == 0)
				process_selector(full_path, command, status);
		free(full_path);
		}
		free_grid(command, data_length);
		data_length = 0;
		}
	else
		free_grid(command, data_length);
	return (*status);
}
