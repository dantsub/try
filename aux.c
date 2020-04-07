#include "holberton.h"
/**
 * array_path - return array of string.
 * @s: string for split.
 * @delim: delimitator.
 * Return: array of strings.
 */
char **split_args(char *s, char *delim)
{
	char **array, *cpy, *tok;
	int size = 0;

	cpy = tok = NULL;
	array = NULL;
	cpy = malloc(sizeof(char) * (_strlen(s) + 1));
	if (!cpy)
		return (NULL);
	_strcpy(cpy, s);
	tok = strtok(cpy, delim);
	while (tok)
	{	size++;
		tok = strtok(NULL, delim);
	}
	array = _calloc(size + 1, sizeof(char *));
	if(!array)
		return (NULL);
	_strcpy(cpy, s);
	tok = strtok(cpy, delim);
	size = 0;
	while (tok)
	{	array[size] = malloc(sizeof(char) * _strlen(tok) + 1);
		if (!array[size])
		{	free(cpy);
			dfree(array);
			return (NULL);
		}
		_strcpy(array[size++], tok);
		tok = strtok(NULL, delim);
	}
	free(cpy);
	return (array);
}

/**
 * init - function for access global values
 * Return: pointer
 */
global_t *init(void)
{
	static global_t global = {
		NULL,
		0,
		NULL,
		NULL
	};

	return (&global);
}
/**
 * 
 * 
 * 
 */
void _puts(char *s)
{
	write(STDOUT_FILENO, s, _strlen(s));
}
