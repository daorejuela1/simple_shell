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

errno = -1;
err_message = _calloc(100, 1);
_strncpy(err_message, name, _strlen(name));
_strcat(err_message, ": 0: Can't open ");
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
 */
void errno_per(char *name, int line, char *error)
{
char *err_message, *storage_array;

err_message = _calloc(100, 1);
storage_array = _calloc(100, 1);
_strncpy(err_message, name, _strlen(name));
_strcat(err_message, ": ");
_strcat(err_message, c_number_to_arr(storage_array, line));
_strcat(err_message, ": ");
_strcat(err_message, error);
_strcat(err_message, ": Permission denied\n");
write(STDERR_FILENO, err_message, _strlen(err_message));
free(err_message);
exit(126);
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

err_message = _calloc(100, 1);
storage_array = _calloc(100, 1);
_strncpy(err_message, name, _strlen(name));
_strcat(err_message, ": ");
_strcat(err_message, c_number_to_arr(storage_array, line));
_strcat(err_message, ": ");
_strcat(err_message, error);
_strcat(err_message, ": not found\n");
write(STDERR_FILENO, err_message, _strlen(err_message));
free(err_message);
return (127);
}

