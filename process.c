#include "holberton.h"
/**
 * 
 * 
 * 
 */
void process(char **argv, char *av)
{
	char **args = NULL;
	char *route = NULL;
	if (argv)
	{
		if (!check_path(argv[1]))
			child(argv, argv[0]);
		else
		{
			route = path(argv[1]);
			if (route)
				argv[1] = route;
			child(argv, argv[0]);
		}
	}
	else
	{
		args = split_args(init()->buff, " \n\t\r");
		if (check_path(*args))
		{
			route = path(*args);
			if (route)
			{	free(args[0]);
				args[0] = route;
			}
		}
		child(args, av);
	}
}
/**
 * 
 * 
 * 
 * 
 */
void child(char **args, char *name)
{
	pid_t child;
	int status, i = 0;

	while (args[i])
	{
		printf("arg: %s, pos: %d\n", args[i], i);
		i++;
	}
	
	child = fork();
	if (!child)
	{
		if (execve(args[0], args, environ) == EOF)
		{
			perror(name);
			exit(127);
		}
	}
	else
	{
		dfree(args);
		wait(&status);
	}
}
