#include "holberton.h"

/**
 * 
 * 
 * 
 */
char *path(char *args)
{
	char *path = NULL;
	list_t *cpy = init()->hpath;
	int size = _strlen(args) + 2;
	struct stat st;

	while (cpy)
	{
		path = malloc(cpy->len * size);
		_strcpy(path, cpy->var);
		_strcat(path, "/");
		_strcat(path, args);
		if (!stat(path, &st))
			return (path);
		cpy = cpy->next;
	}
	free(path);
	return (NULL);
}

/**
 * 
 * 
 * 
 */
int check_path(char *args)
{
	struct stat st;
	list_t *path = init()->hpath;

	while (path && _strncmp(args, path->var, _strlen(path->var)))
		path = path->next;
	if (!stat(args, &st) || !_strncmp(args, "./", 2) || path)
		return (0);
	return (1);
}

/**
 * 
 * 
 * 
 */
void list_path(void)
{
	char *path = NULL, *tok = NULL;

	path = _getenv("PATH");
	tok = strtok(path, ":");
	while (tok)
	{
		addnode_end(&init()->hpath, tok);
		tok = strtok(NULL, ":");
	}
}
