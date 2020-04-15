#include "holberton.h"
/**
* isNumber - checks if string is just numbers
* @s: pointer to a string of error messages
* Return: error code 127
*/
int isNumber(char *s)
{
	int i;

	for (i = 0; s[i] != 0; i++)
	{
		if ((s[i] < '0' || s[i] > '9'))
			return (0);
	}
	return (1);
}

/**
* handle_error - handle exit behavior and error output
* @param: structure with the run state
* @command: user input
* @data_length: command length
* Return: error code 2 or previous if no new error
*/
int handle_error(creator_args param, char **command, int *data_length)
{
	int state;

	if (command[1] != NULL)
	{
		if (isNumber(command[1]))
		{
			*(param.status) = _atoi(command[1]);
			*(param.start) = 0;
			free_grid(command, *data_length);
			*data_length = 0;
			return (*(param.status));
		}
		else
		{
			state = errno_int(param.argv[0], *(param.counter), command[0], command[1]);
			free_grid(command, *data_length);
			*data_length = 0;
			return (state);
		}
	}
	*(param.start) = 0;
	free_grid(command, *data_length);
	*data_length = 0;
	return (*(param.status));
}
