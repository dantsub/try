#include "holberton.h"

/**
 * 
 * 
 * 
 */
char *_getenv(char *name)
{
	char *var = NULL;
	list_t *env = init()->henv;
	int pos = 0;

	while (env && _strncmp(env->var, name, _strlen(name)))
		env = env->next;
	if (!env)
		return (NULL);
	pos = _strlen(name) + 1;
	var = malloc(((env->len + 2) - pos) * sizeof(char));
	if (!var)
		return (NULL);
	var = _strcpy(var, (pos + env->var));
	return (var);
}
/**
 * 
 * 
 */
void lenv(void)
{
	char **array = NULL;
	int i = 0;

	while (environ[i])
		i++;
	array = _calloc((i + 1), sizeof(char *));
	i = 0;
	while (environ[i])
	{	array[i] = malloc(sizeof(char) * (_strlen(environ[i]) + 1));
		if (!array[i])
		{	dfree(array);
			return;
		}
		_strcpy(array[i], environ[i]);
		i++;
	}
	array[i] = 0;
	for (i = 0; array[i]; i++)
		addnode_end(&init()->henv, array[i]);
	free(array);
}
