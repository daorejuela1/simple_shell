#include "holberton.h"
/**
 * errno_lin_st - search for error messages
 * @error: pointer to error message
 * @name: string of err_message
 * Return: Nothing
 */
void errno_lin_st(char *name, char *error)
{
char *err_message;
int data_len = 0;
char *message = ": 0: Can't open ";

data_len = _strlen(name) + _strlen(error) + _strlen(message);
err_message = _calloc(data_len + 2, 1);
if (err_message == NULL)
	return;
_strncpy(err_message, name, _strlen(name));
_strcat(err_message, message);
_strcat(err_message, error);
_strcat(err_message, "\n");
write(STDERR_FILENO, err_message, _strlen(err_message));
free(err_message);
exit(127);
}

/**
 * errno_per - counts the line numbers
 * @name: the name of shell or sh
 * @line: number of lines
 * @error: pointer to error messages
 * Return: status code 126
 */
int errno_per(char *name, int line, char *error)
{
char *err_message, *storage_array;
int data_len = 0, num_digits = 0, position = 0;
char *message = ": Permission denied\n";

num_digits = line;
while (num_digits != 0)
{
	num_digits = num_digits / 10;
	position++;
}
data_len = _strlen(name) + _strlen(error) + _strlen(message);
err_message = _calloc(data_len + 5 + position, 1);
if (err_message == NULL)
	return (0);
storage_array = _calloc(position + 1, 1);
if (storage_array == NULL)
	return (0);
_strncpy(err_message, name, _strlen(name));
_strcat(err_message, ": ");
_strcat(err_message, c_number_to_arr(storage_array, line));
_strcat(err_message, ": ");
_strcat(err_message, error);
_strcat(err_message, message);
write(STDERR_FILENO, err_message, _strlen(err_message));
free(err_message);
free(storage_array);
return (126);
}

/**
 * errno_found - prints error depending on the case
 * @name: pointer to a string of error messages
 * @line: number of lines
 * @error: pointer to error
 * Return: error code 127
 */
int errno_found(char *name, int line, char *error)
{
char *err_message, *storage_array;
int data_len = 0, num_digits = 0, position = 0;
char *message = ": not found\n";

num_digits = line;
while (num_digits != 0)
{
	num_digits = num_digits / 10;
	position++;
}
data_len = _strlen(name) + _strlen(error) + _strlen(message);
err_message = _calloc(data_len + 5 + position, 1);
if (err_message == NULL)
	return (0);
storage_array = _calloc(position + 1, 1);
if (storage_array == NULL)
	return (0);
_strncpy(err_message, name, _strlen(name));
_strcat(err_message, ": ");
_strcat(err_message, c_number_to_arr(storage_array, line));
_strcat(err_message, ": ");
_strcat(err_message, error);
_strcat(err_message, message);
write(STDERR_FILENO, err_message, _strlen(err_message));
free(err_message);
free(storage_array);
return (127);
}

