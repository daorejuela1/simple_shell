#include "holberton.h"
/**
 * str_srch - search a character inside a string
 * @array: string to search
 * @charac: character to search for
 * Return: Always 0 on success
 */
int str_srch(char *array, char charac)
{
	int index = -1, i = 0;

	for (; array[i]; i++)
	{
		if (charac == array[i])
		{
			index = i;
			return (index);
		}
	}
	return (index);
}
