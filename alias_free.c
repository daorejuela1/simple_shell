#include "holberton.h"

/**
 * alias_free - frees the alias strings inside param
 * @param: structure that contains the aliases
 *
 * Returns: Nothing
 */
void alias_free(creator_args param)
{
	alias_l *temp = NULL;

	while (param.aliases)
	{
		temp = param.aliases->next;
		free(param.aliases->name);
		free(param.aliases->value);
		free(param.aliases);
		param.aliases = temp;
	}
}

/**
 * replace_aliases - replace the command with the corresponding alias if found
 * @param: structure that contains the aliases
 *
 * Returns: Nothing
 */
void replace_aliases(creator_args param)
{
	alias_l *temp = NULL;
	char *new_string = NULL;

	temp = param.aliases;
	while (temp)
	{
		if (_strcmp(temp->name, param.com_list->command[0]) == 0)
		{
			free(param.com_list->command[0]);
			new_string = _calloc(_strlen(temp->value) + 1, 1);
			strncpy(new_string, temp->value, _strlen(temp->value));
			param.com_list->command[0] = new_string;
		}
		temp = temp->next;
	}
}
