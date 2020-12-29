#include "holberton.h"
static int command_end;

/**
 *command_separator - gets the commands to do separed by ;
 *@string: Input line from the user
 *Return: Always double pointer with commands
 */
char *command_separator(char *string)
{
	char *line = NULL;
	int i = 0;

	if (!string)
		return (NULL);
	for (i = command_end; i < _strlen(string); i++)
	{
		if (string[i] == *";")
		{
			break;
		}
	}
	if (i == command_end)
		return (NULL);
	line = _calloc(i - command_end + 1, 1);
	if (!line)
		return (NULL);
	line = _strncpy(line, string + command_end, i - command_end);
	command_end = i + 1;
	return (line);
}

/**
 *command_getter - gets the commands to do separed by ;
 *@string: Input line from the user
 *@params: structure with command information
 *Return: Always double pointer with commands
 */
c_list *command_getter(char *string, creator_args *params)
{
	c_list *new_command = NULL, *initial = NULL;
	char *line = NULL;
	int counter = 0, data_len = 0;

	command_end = 0;
	while ((line = command_separator(string)))
	{
		free(line);
		new_command = malloc(sizeof(c_list));
		new_command->next = NULL;
		if (!new_command)
			return (NULL);
		counter++;
		if (counter == 1)
		{
			params->com_list = new_command;
			initial = params->com_list;
		}
		else
		{
			params->com_list->next = new_command;
			params->com_list = params->com_list->next;
		}
	}
	command_end = 0;
	params->com_list = initial;
	while ((line = command_separator(string)))
	{
		data_len = 0;
		params->com_list->command = extract_string(line, &data_len);
		(params->com_list)->data_len = data_len;
		free(line);
		params->com_list = params->com_list->next;
	}
	return (initial);
}

/**
 *free_andnext - frees the linked list and past to next command;
 *@params: Structure with the command to clean
 *Return: Nothing
 */
void free_andnext(creator_args *params)
{
	c_list *temp = NULL;

	free_grid((params->com_list)->command, params->com_list->data_len);
	temp = params->com_list->next;
	free(params->com_list);
	params->com_list = temp;
}
