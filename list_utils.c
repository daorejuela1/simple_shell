#include "holberton.h"
/**
 *print_list - prints the information inside a list
 *@h: list to print
 *Return: Number of nodes
 */
size_t print_list(const path_dir_node *h)
{
	int i = 0;

	for (i = 0; h != NULL; i++)
	{
		if (h->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%d] %s\n", h->len, h->str);
		h = h->next;
	}
	return (i);
}

/**
 *free_list - eliminate memory leaks while using lists
 *@head: pointer to the the list
  *Return: Nothing
 */
void free_list(path_dir_node *head)
{
	int i = 0;
	void *tmp;

	for (i = 0; head != NULL; i++)
	{
		tmp = head;
		free(head->str);
		head = head->next;
		free(tmp);
	}
}
