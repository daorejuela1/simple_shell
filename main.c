#include "holberton.h"
/**
 * main - reads the user input and checks if is valid
 *@argc: quantity of arguments
 *@argv: value of the arguments
 *Return: Always 0
 */
int main(int argc, char *argv[])
{
	int read, status, len = 0;
	char *line = NULL;
	const char *delim = " \n\t\r";
	char *command[1024];
	struct stat st;
	/*argv = "hola" "mundo" 0*/
	while (1)
	{
		_puts("$ ");
		read =  getline(&line, &len, stdin);
		if (read == -1)
		{
			_puts("\n");
			break;
		}
		command[0] = strtok(line, delim);
		command[1] = NULL;
		if (stat(line, &st) == 0 && access(line, X_OK) == 0)
		{
			_puts("Valid file\n");
			process_selector(&command, &status);
		}
	}
	free(line);
	return (0);
}
