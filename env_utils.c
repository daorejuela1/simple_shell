#include "holberton.h"
/**
 *_getenv - gets actual enviroment
 *@name: key of enviroment
 *Return: string with paths of environment
 */
char *_getenv(const char *name)
{
	char *key = NULL, *copy = NULL;
	char *result = NULL;
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		copy = _calloc(_strlen(environ[i]) + 1, 1);
		if (copy == NULL)
			return (NULL);
		_strncpy(copy, environ[i], _strlen(environ[i]));
		key = strtok(copy, "=");
		if (_strcmp(key, (char *)name) == 0)
		{
			key = strtok(NULL, "=");
			if (key == NULL)
				key = "";
			result = _calloc(_strlen(key) + 1, 1);
			if (result == NULL)
				return (NULL);
			_strncpy(result, key, _strlen(key));
			free(copy);
			return (result);
		}
		free(copy);
	}
	free(copy);
	return (NULL);
}
/**
 *path_searcher - search through path for a valid file
 *@command: argument to check if exist or not
 *@env: actual environment
 *Return: modified path or null if failed
 */
char *path_searcher(char **command, char *env)
{
	char *token = NULL, *copy;
	char *final_path = NULL;
	struct stat st;

	copy = _calloc(_strlen(env) + 1, 1);
	_strncpy(copy, env, _strlen(env));
	token = strtok(copy, ":");
	while (token != NULL)
	{
		final_path = _calloc(_strlen(token) + _strlen(command[0]) + 2, 1);
		_strncpy(final_path, token, _strlen(token));
		_strcat(final_path, "/");
		_strcat(final_path, command[0]);
		if (stat(final_path, &st) == 0)
		{
			free(copy);
			return (final_path);
		}
		token = strtok(NULL, ":");
		free(final_path);
	}
	free(copy);
	return (NULL);
}
