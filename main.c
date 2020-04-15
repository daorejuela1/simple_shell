#include "holberton.h"

/**
 * main - reads the user input and checks if is valid
 *@argc: quantity of arguments
 *@argv: value of the arguments
 *@env: actual environment
 *Return: Always 0
 */
int main(int argc, char *argv[], char **env)
{
	int counter = 0, read = 0, status = 0;
	char *en_variable = NULL, start = 1, *line = NULL;
	size_t len = 0;
	creator_args creator_params;

	signal(SIGINT, handler_ctrlc);
	en_variable = _getenv("PATH");
	creator_params.line = &line, creator_params.en_variable = en_variable;
	creator_params.argv = argv, creator_params.counter = &counter;
	creator_params.start = &start, creator_params.status = &status;
	creator_params.actual_env = env;
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
			status = create_process(creator_params);
		}
	}
	else
	{
		while ((read = getline(&line, &len, stdin)) != EOF)
		{
			counter++; /*non interactive mode*/
			status = create_process(creator_params);
		}
	}
	free(en_variable);
	free(line);
	return (status);
}
