#include "holberton.h"
/**
* get_op_func - returns the function acording to the input string
* @string: shell command input
*
* Return: pointer to function
*/
int (*get_op_func(char *string))(creator_args *, char **, int *)
{
	int i = 0;
	builtin_t command[] = {
	{"exit", handle_error},
	{"setenv", _setenv},
	{"unsetenv", _unsetenv},
	{"alias", alias_logic},
	{"cd", cd_logic},
	{NULL, NULL}
	};

	for (i = 0; i < 5; i++)
	{
		if (_strcmp(string, command[i].command) == 0)
			return (command[i].f);
	}
	return (NULL);
}
