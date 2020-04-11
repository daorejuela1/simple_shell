#include "holberton.h"

/**	
 * main - reads the user input and checks if is valid	
 *@argc: quantity of arguments	
 *@argv: value of the arguments	
 *Return: Always 0	
 */	
int main(int argc, char *argv[])	
{	
	int read, status;	
	char *line = NULL;	
	char interactive = 0;	
	const char *delim = " \n\t\r";	
	char *command[1024];	
	struct stat st;	
	size_t len = 0;	
	/*argv = "hola" "mundo" 0*/	

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
			_puts("\n");	
			break;	
		}	
		command[0] = strtok(line, delim);	
		command[1] = NULL;	
		if (stat(line, &st) == 0 && access(line, X_OK) == 0)	
		{	
			_puts("Valid file\n");	
			process_selector(command, &status);	
		}	
		else	
		{	
			_puts(argv[0]);	
			printf("%d\n", __LINE__);	
			_puts(command[0]);	
			_puts(": not found");	
			_puts("\n");	
		}	
		if (interactive == 0)	
			break;	
	}	
	free(line);	
	return (0);	
}