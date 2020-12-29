#include "holberton.h"
/**
 * remove_comments - removes the comments in the line by detecting # char
 * @line: string that contains comments
 *
 * Return: line of null if error
 */
static char *remove_comments(char *line)
{
	int i = 0, line_len = 0;
	char *new_line = NULL;

	line_len = _strlen(line);
	for (i = 0; i < line_len; i++)
	{
		if (line[i] == *"#")
			break;
	}
	if (!i)
	{
		free(line);
	}
		return (NULL);
	new_line = _calloc(i + 1, 1);
	if (!new_line)
		return (NULL);
	_strncpy(new_line, line, i);
	free(line);
	return (new_line);
}

/**
 * line_parser - removes comments and interpretate line content
 * @line: raw input line
 *
 * Return: None if error ocurs, Parsed line otherwise
 */
char *line_parser(char *line)
{
	line = remove_comments(line);
	return (line);
}
