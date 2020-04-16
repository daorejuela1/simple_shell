#include "holberton.h"

/**
 * main - reads the user input and avaloidates it
 *@argc: quantity of arguments
 *@argv: value of the arguments
 *@env: enviroment variable
 * Return: status
 */
int main(int argc, char *argv[], char **env)
{
	int counter = 0, read = 0, status = 0;
	char start = 1, *line = NULL;
	size_t len = 0;
	creator_args c_args;

	signal(SIGINT, handler_ctrlc);
	c_args.line = &line, c_args.argv = argv;
	c_args.counter = &counter, c_args.start = &start, c_args.status = &status;
	if (argc > 1)
		errno_lin_st(argv[0], argv[1]);
	if (isatty(STDIN_FILENO))
	{
		while (start) /*interactive mode*/
		{
			_puts("$ ");
			read =  getline(&line, &len, stdin);
			counter++;
			if (read == EOF)
			{
				_puts("\n");
				break;
			}
			status = (_strcmp(line, "env\n") == 0) ? print_env(env) : new_pro(c_args);
		}
	}
	else
	{
		while ((read = getline(&line, &len, stdin)) != EOF)
		{
			counter++; /*non interactive mode*/
			status = (_strcmp(line, "env\n") == 0) ? print_env(env) : new_pro(c_args);
		}
	}
	free(line);
	return (status);
}
