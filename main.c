#include "holberton.h"
char **extract_string(char *string, int *data_length);
int _strlen(char *s);
char *_strncpy(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);
void free_grid(char ***grid, int height);
/**
 * main - reads the user input and checks if is valid
 *@argc: quantity of arguments
 *@argv: value of the arguments
 *Return: Always 0
 */
int main(int argc, char *argv[])
{
	int read, status, data_length = 0;
	char *line = NULL;
	char **command = NULL;
	char interactive = 0;
	struct stat st;
	size_t len = 0;

	if (argc > 1)
	{
		_puts(argv[0]);
		_puts(":");
		printf("%d\n", __LINE__);
		_puts(" : Can't open ");
		_puts(argv[1]);
		_puts("\n");
		exit(127);
	}
	if (isatty(fileno(stdin)))
		interactive = 1;
	else
		interactive = 0;
	while (1)
	{
		if (interactive)
			_puts("$ ");
		read =  getline(&line, &len, stdin);
		if (read == -1)
		{
			free_grid(&command, data_length);
			_puts("\n");
			break;
		}
		command = extract_string(line, &data_length);
		if (command[0] != NULL)
			{
			if (stat(command[0], &st) == 0 && access(command[0], X_OK) == 0)
			{
				process_selector(command, &status);
			}
			else
			{
				_puts(argv[0]);
				_puts(": 1:");
				_puts(command[0]);
				_puts(": not found");
				_puts("\n");
			}
			free_grid(&command, data_length);
			data_length = 0;
			if (interactive == 0)
				break;
			}
	}
	free(line);
	return (0);
}

/**
 *extract_string - extract string data
 *@string: quantity of arguments
 *@data_length: quantity of arguments in commands
 *Return: Always double pointer with commands
 */
char **extract_string(char *string, int *data_length)
{
	int i = 0;
	char *copy, *token, *copy2;
	const char *delim = " \n\t\r";
	char **command = NULL;

	copy = calloc(_strlen(string) + 1, 1);
	if (copy == NULL)
		return (NULL);
	_strncpy(copy, string, _strlen(string));
	token = strtok(copy, delim);
	while (token != NULL)
	{
		(*data_length)++;
		token = strtok(NULL, delim);
	}
	free(copy);
	command = calloc(((*data_length) + 1), sizeof(char *));
	if ((command) == NULL)
		return (NULL);
	copy2 = calloc(_strlen(string) + 1, 1);
	if (copy2 == NULL)
		return (NULL);

	_strncpy(copy2, string, _strlen(string));
	token = strtok(copy2, delim);
	for (i = 0; i < (*data_length); i++)
	{
		command[i] = calloc(strlen(token) + 1, 1);
		if (command[i] == NULL)
		{
			free_grid(&command, i);
			free(copy2);
			return (NULL);
		}
		_strncpy(command[i], token, _strlen(token));
		token = strtok(NULL, delim);
	}
	free(copy2);
	command[i] = NULL;
	return (command);
}

/**
 *_strlen - returns data len
 *@s: input string
 *
 *Return:an int number
 *
 */
int _strlen(char *s)
{
	int counter = 0;

	while (*(s + counter) != 0)
	{
	counter++;
	}
	return (counter);
}

/**
  *_strncpy - merge  two strings
  *
  *@dest: second string
  *@src: first string
  *@n: limit number
  *Return: a pointer, to dest
  */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != 0; i++)
		*(dest + i) = *(src + i);
	for (; i < n; i++)
		*(dest + i) = 0;
	return (dest);
}

/**
  *_strcmp - merge  two strings
  *
  *@s1: second string
  *@s2: first string
  *
  *Return: number with difference
  */
int _strcmp(char *s1, char *s2)
{
	int i;
	int differ;

	for (i = 0; s1[i] != 0; i++)
	{
		differ = *(s1 + i) - *(s2 + i);
		if (*(s1 + i) == *(s2 + i))
		{
			continue;
		}
		else
		{
			break;
		}
	}
	return (differ);
}

/**
 *free_grid - allocate matrix in the form of memory
 *@grid: 2d matrix
 *@height: matrix row
 *Return: None
 */
void free_grid(char ***grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
		free(*grid[i]);
	free(*grid);
	*grid = NULL;
}
