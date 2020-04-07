# include "holberton.h"
/**
 * main - main of program (shell)
 * @av: argument values.
 * @ac: argument counts.
 * @env: environment
 * Return: Always 0
 */
int main(int ac, char **av)
{
	(void)ac;

	lenv();
	list_path();
	/*if (ac > 1) */
	/*	process(av, av[0]);*/
	/*else*/
	prompt(av[0]);

	return (EXIT_SUCCESS);
}
