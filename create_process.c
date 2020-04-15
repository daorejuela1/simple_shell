#include "holberton.h"
/**
 *create_process - executes the shell main logic checking
 *if a file is worth
 *@param: structure with all arguments
 *Return: modified path or null if failed
 */
int create_process(creator_args param)
{
	int data_length = 0;
	char **command = NULL;
	char *full_path = NULL;
	struct stat st;

	command = extract_string(*(param.line), &data_length);
	if (command[0] != NULL)
		{
		if (_strcmp(command[0], "exit") == 0)
		{
			*(param.start) = 0;
			if (command[1] != NULL)
				*(param.status) = _atoi(command[1]);
			free_grid(command, data_length);
			return (*(param.status));
		}
		else if (_strcmp(command[0], "env") == 0)
			print_env();
		else if (stat(command[0], &st) == 0 && access(command[0], X_OK) == 0)
			process_selector(command[0], command, param.status);
		else if (stat(command[0], &st) == 0 && access(command[0], X_OK) != 0)
			*(param.status) = errno_per(param.argv[0], *(param.counter), command[0]);
		else if (stat(command[0], &st) != 0)
		{
			full_path = path_searcher(command, *(param.en_variable));
			if (full_path == NULL)
				*(param.status) = errno_found(param.argv[0], *(param.counter), command[0]);
			else if (stat(full_path, &st) == 0 && access(full_path, X_OK) != 0)
				*(param.status) = errno_per(param.argv[0], *(param.counter), command[0]);
			else if (stat(full_path, &st) == 0 && access(full_path, X_OK) == 0)
				process_selector(full_path, command, param.status);
		free(full_path);
		}
		free_grid(command, data_length);
		data_length = 0;
		}
	else
		free_grid(command, data_length);
	return (*(param.status));
}
