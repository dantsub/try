#include "holberton.h"

/**
 * dfree - free to double pointer
 * @array: double pointer to be free.
 * Return: Nothing.
 */
void dfree(char **array)
{
	int i = 0;

	while (array[i])
		free(array[i++]);
	free(array);
}

/**
 * free_list - free a linked list
 * @head: head of linked list.
 * Return: nothing.
 */
void free_list(list_t **head)
{
	list_t *curr;

	if (head)
	{
		if (*head)
		{	curr = *head;
			free_list(&(*(*head)).next);
			free(curr->var);
			free(curr);
		}
		*head = NULL;
	}
}

/**
 * allfree - free all pointers used
 * Return: nothing.
 */
void allfree(void)
{
	if (init()->buff)
		free(init()->buff);
	if (init()->henv)
		free_list(&init()->henv);
	if (init()->hpath)
		free_list(&init()->hpath);
}
