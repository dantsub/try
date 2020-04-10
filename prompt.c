#include "holberton.h"

/**
 * prompt - Display a prompt and wait for the user to type a command.
 * Return: nothing
 */
void prompt(char *av)
{
	char *prompt = "$ ";

	do
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, prompt, _strlen(prompt));
		if (getline(&init()->buff, &init()->len, stdin) != EOF)
		{
			if (_strncmp(init()->buff, "\n", 1))
			{
				process(NULL, av);
			}
		}
		else
		{
			allfree();
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(EXIT_SUCCESS);
		}
		
	} while (1);
}
