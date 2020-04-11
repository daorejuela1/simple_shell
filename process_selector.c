#include "holberton.h"
/**
 * process_selector - function that selects the children processes
 * @command: buffer variable where data is stored temporarily
 * @status: returns children running status
 * Return: Always 0 on success
*/

int process_selector(char **command, int *status)
{
	pid_t children;

	children = fork();
	if (children < 0) /*Error*/
	{
		perror("Error: Children process can't be created");
		exit(1);
	}
	if (children == 0) /*Children process*/
	{
		if (execve(command[0], command, environ) == -1)
			perror("No such file or directory");
	}
	if (children > 0) /*current process*/
	{
		wait(status);
	}
return (0);
}
