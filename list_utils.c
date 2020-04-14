#include "holberton.h"

/**
 *free_list - eliminate memory leaks while using lists
 *@head: pointer to the the list
  *Return: Nothing
 */
void free_list(p_node *head)
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

/**
 *put_node - adds node at end of list and return
 *pointer to origin
 *@head: pointer to the pointer of the list
 *@new_node: str data to add
 *@old_clone: old data copy with original address
 *Return: none
 */
void put_node(p_node **head, p_node *new_node, p_node *old_clone)
{
	if (*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		while (*head != NULL)
		{
			if ((*head)->next == NULL)
			{
				(*head)->next = new_node;
				(*head) = old_clone;
				break;
			}
			*head = (*head)->next;
		}
	}
}
/**
 *add_node_end - adds new node at end of list
 *@head: pointer to the pointer of the list
 *@str: str data to add
 *Return: pointer to the new element of list
 */
p_node *add_node_end(p_node **head, const char *str)
{
	int len_str = 0;
	p_node *new_node, *old_clone;
	char *final = NULL;

	if (head == NULL)
		return (NULL);
	if (str != NULL)
	{
		final = strdup(str);
		if (final == NULL)
			return (NULL);
		while (final[len_str])
			len_str++;
	}
	new_node = malloc(sizeof(p_node));
	if (new_node == NULL)
		return (NULL);
	old_clone = malloc(sizeof(p_node));
	if (old_clone == NULL)
		return (NULL);
	old_clone = *head;
	new_node->str = final;
	new_node->len = len_str;
	new_node->next = NULL;
	put_node(head, new_node, old_clone);
	return (new_node);
}
