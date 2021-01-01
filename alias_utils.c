#include "holberton.h"
/**
 * print_alias - prints the linked list containing the alias information
 * @param: structure with the used variables
 * @command: array of array with the input commands
 * @data_length: quantity of commands as input
 *
 * Return: 0 on success and -1 in any error case
 */
static int print_alias(creator_args *param, char **command, int *data_length)
{
	alias_l *temp = NULL;
	int i = 0;

	UNUSED(command);
	UNUSED(data_length);
	temp = param->aliases;
	if (*data_length == 1)
	{
		while (temp)
		{
			printf("%s='%s'\n", temp->name, temp->value);
			temp = temp->next;
		}
	}
	else
	{
		for (i = 1; i < *data_length; i++)
		{
			temp = param->aliases;
			while (temp)
			{
				if (_strcmp(command[i], temp->name) == 0)
					printf("alias %s='%s'\n", temp->name, temp->value);
				temp = temp->next;
			}
		}

	}
	return (0);
}

/**
 * replace_value - replace the assigned value if name is found
 * @head: root of the linked list
 * @name: name of the alias
 * @value: quantity of commands as input
 *
 * Return: 0 on success and -1 if name not found
 */
static int replace_value(alias_l **head, char *name, char *value)
{
	alias_l *temp = NULL;

	temp = *head;
	while (temp)
	{
		if (_strcmp(temp->name, name) == 0)
		{
			free(name);
			free(temp->value);
			temp->value = value;
			return (0);
		}
		temp = temp->next;
	}
	return (-1);
}
/**
 * alist_insert - insert couple name value in list
 * @head: root of the linked list
 * @name: name of the alias
 * @value: quantity of commands as input
 *
 * Return: 0 on success and -1 in any error case
 */
static alias_l *alist_insert(alias_l **head, char *name, char *value)
{
	alias_l *new_list, *clone;

	if (head == NULL)
		return (NULL);
	new_list = malloc(sizeof(alias_l));
	if (new_list == NULL)
		return (NULL);
	new_list->name = name;
	new_list->value = value;
	new_list->next = NULL;
	if (*head == NULL)
	{
		*head = new_list;
		return (new_list);
	}
	else
	{
		clone = *head;
		while ((*head)->next != NULL)
		{
			*head = (*head)->next;
		}
	}
	(*head)->next = new_list;
	*head = clone;
	return (new_list);
}

/**
 * create_alias - creates a new alias
 * @param: structure with the used variables
 * @command: array of array with the input commands
 * @data_length: quantity of commands as input
 *
 * Return: 0 on success and -1 in any error case
 */
static int create_alias(creator_args *param, char **command, int *data_length)
{
	int i = 0;
	char *delim = "=", *name = NULL, *value = NULL, *left = NULL, *right = NULL;

	for (i = 1; i < *data_length; i++)
	{
		left = strtok(command[i], delim);
		name = _calloc(_strlen(left) + 1, 1);
		_strncpy(name, left, _strlen(left));
		right = strtok(NULL, delim);
		value = _calloc(_strlen(left) + 1, 1);
		_strncpy(value, right, _strlen(left));
		if (replace_value(&param->aliases, name, value) == -1)
			alist_insert(&param->aliases, name, value);
	}
	return (0);
}


/**
 * alias_logic - selector to know if alias should be printed or stored
 * @param: structure with the used variables
 * @command: array of array with the input commands
 * @data_length: quantity of commands as input
 *
 * Return: 0 on success and -1 in any error case
 */
int alias_logic(creator_args *param, char **command, int *data_length)
{
	if (!command[1] || str_srch(command[1], '=') == -1)
		print_alias(param, command, data_length);
	else
		create_alias(param, command, data_length);
	free_andnext(param);
	return (0);
}
