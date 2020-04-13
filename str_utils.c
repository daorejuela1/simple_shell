#include "holberton.h"
/**
  *_strcmp - merge  two strings
  *
  *@s1: second string
  *@s2: first string
  *
  *Return: number with difference
  */
int _strcmp(char *s1, char *s2)
{
	int i;
	int differ;

	for (i = 0; s1[i] != 0; i++)
	{
		differ = *(s1 + i) - *(s2 + i);
		if (*(s1 + i) == *(s2 + i))
		{
			continue;
		}
		else
		{
			break;
		}
	}
	return (differ);
}

/**
  *_strncpy - merge  two strings
  *
  *@dest: second string
  *@src: first string
  *@n: limit number
  *Return: a pointer, to dest
  */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != 0; i++)
		*(dest + i) = *(src + i);
	for (; i < n; i++)
		*(dest + i) = 0;
	return (dest);
}

/**
 *_strlen - returns data len
 *@s: input string
 *
 *Return:an int number
 *
 */
int _strlen(char *s)
{
	int counter = 0;

	while (*(s + counter) != 0)
	{
	counter++;
	}
	return (counter);
}

/**
  *_strcat - concatenates two strings
  *
  *@dest: second string
  *@src: first string
  *Return: a pointer, to dest
  */
char *_strcat(char *dest, char *src)
{
	int i, counter = 0;

	while (*(dest + counter) != 0)
	{
		counter++;
	}
	for (i = counter;  src[i - counter] != 0; i++)
	{
		*(dest + i) = *(src + i - counter);
	}
	return (dest);
}

/**
 *c_number_to_arr - Prints an int number by using putchar
 *@n: Input number
 *@array_data: Array to store final string
 *Return: converted array
 */
char *c_number_to_arr(char *array_data, int n)
{
	int i, position = 0;
	unsigned int handler;
	int num_digits;

	handler = n;
	if (n < 0)
	{
		handler = handler * -1;
		array_data[position] = '-';
		position++;
	}
	num_digits = cal_digits(handler);
	for (i = num_digits; i >= 1; i /= 10)
	{
		array_data[position] = (handler / i) % 10 + '0';
		position++;
		if (i == 1)
			break;
	}
	return (array_data);
}
