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
	/* checkear av null */
	/* checkear path */
	/* si path o exec exect */
	/* no path o exec concat con path*/
	/* crear proceso hijo */
	/* ejecutar proceso */
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
		printf("2-split args funciona\n");
		if (check_path(*args))
		{
			printf("ingreso aqui por que no tiene path\n");
			route = path(*args);
			if (route)
				args[0] = route;
		}
		printf("este es el argumento con el path [%s]\n", args[0]);
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
	int status;

	printf("Antes de crear al hijo\n");
	printf("este es path ahora->[%s]\n", args[0]);
	child = fork();
	if (!child)
	{
		if (execve(args[0], args, environ) == EOF)
		{
			perror(name);
			free(init()->buff);
			exit(127);
		}
	}
	else
	{
		wait(&status);
	}
	
}
