#include "holberton.h"
/**
 * addnode_end - add node at the end of list_t
 * @head: head of list_t
 * @var: is a string will be duplicate.
 */
list_t *addnode_end(list_t **head, char *var)
{
	list_t *node = NULL;
	list_t *cpy = *head;

	node = malloc(sizeof(list_t));
	if (!node)
		return (NULL);
	node->var = var;
	node->len = _strlen(var);
	node->next = NULL;
	
	if (!(*head))
	{	*head = node;
		return (node);
	}
	while (cpy->next)
		cpy = cpy->next;
	cpy->next = node;
	return (node);
}
