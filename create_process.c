#include "holberton.h"
/**
 *new_pro - executes the shell main logic checking
 *if a file is worth
 *@param: structure with all arguments
 *Return: modified path or null if failed
 */
int new_pro(creator_args param)
{
	int data_length = 0;
	char **command = NULL, *en_variable = NULL;
	char *full_path = NULL;
	int (*built_infunc)(creator_args, char **, int *);
	struct stat st;

	command = extract_string(*(param.line), &data_length);
	if (command[0] != NULL)
	{
		built_infunc = get_op_func(command[0]);
		if (built_infunc != NULL)
			return (built_infunc(param, command, &data_length));
		en_variable = _getenv("PATH");
		if (stat(command[0], &st) == 0
				&& access(command[0], X_OK) == 0 &&
				(en_variable || str_srch(command[0], '/') != -1))
			process_selector(command[0], command, param.status);
		else if (stat(command[0], &st) == 0 && access(command[0], X_OK) != 0)
			*(param.status) = errno_per(param.argv[0], *(param.counter), command[0]);
		else
		{
			full_path = path_searcher(command, en_variable);
			if (full_path == NULL)
				*(param.status) = errno_found(param.argv[0], *(param.counter), command[0]);
			else if (stat(full_path, &st) == 0 && access(full_path, X_OK) != 0)
				*(param.status) = errno_per(param.argv[0], *(param.counter), command[0]);
			else if (stat(full_path, &st) == 0 && access(full_path, X_OK) == 0)
				process_selector(full_path, command, param.status);
		}
		free(en_variable);
		en_variable = NULL;
		free(full_path);
		free_grid(command, data_length);
		data_length = 0;
	}
	else
		free_grid(command, data_length);
	return (*(param.status));
}
