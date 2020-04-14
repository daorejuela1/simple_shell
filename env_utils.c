#include "holberton.h"
#include "holberton.h"
/**
 *_getenv - gets actual enviroment
 *@name: key of enviroment
 *Return: string with paths of environment
 */
char *_getenv(const char *name)
{
	extern char **environ;
	char *key = NULL;
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		key = strtok(environ[i], "=");
		if (strcmp(key, name) == 0)
		{
			key = strtok(NULL, "=");
			return (key);
		}
	}
	return (NULL);
}
/**
 *path_searcher - search through path for a valid file
 *@command: argument to check if exist or not
 *Return: modified path or null if failed
 */
char **path_searcher(char **command, int *data_length, char *env)
{
	char *token = NULL, *copy;
	char **full_path = NULL, *final_path = NULL;
	struct stat st;

	copy = _calloc(_strlen(env) + 1, 1);
	_strncpy(copy, env, _strlen(env));
	token = strtok(copy, ":");
	while(token != NULL)
	{
		final_path = _calloc(_strlen(token) + 1, 1);
		_strncpy(final_path, token, _strlen(token));
		strcat(final_path, "/" );
		strcat(final_path, command[0]);
		if (stat(final_path, &st) == 0)
		{
			printf("%s\n %d", final_path, *data_length);
			return (full_path);   
		}
		token = strtok(NULL, ":");
	}
	return (full_path);  
}


/**
 *get_match - ask if current path exist
 *@h: list to iterate over
 *Return: Matching path or null
 */
char *get_match(const path_dir_node *h)
{
	int i = 0;
	struct stat st;

	for (i = 0; h != NULL; i++)
	{
		if (stat(h->str, &st) == 0)
			return (h->str);
		h = h->next;
	}
	return (NULL);
}
