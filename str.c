#include "holberton.h"
/**
 * _strlen - returns len of str
 * @str: string to count chars
 * Return: len of str
 */
int _strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}
/**
 * _strcmp - compare two strings.
 * @s1: first string
 * @s2: second string
 * Return: 1 if not equal, 0 if igual
 */
int _strncmp(char *s1, char *s2, int bytes)
{
	int i = 0;

	while (s1[i] && s2[i] && i < bytes)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
/**
 * _strcpy - copy a string
 * @dest: destination
 * @src: source
 * Return: a pointer to the destination string *dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{	dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
/**
  * *_strcat - concatenates two strings.
  * @dest: destination.
  * @src: source.
  * Return: destination.
  */
char *_strcat(char *dest, char *src)
{
	int size, index;

	size = 0;
	while (dest[size] != 0)
		size++;
	for (index = 0; src[index] != 0; index++)
		dest[size + index] = src[index];
	dest[size + index] = 0;
	return (dest);
}

/**
 * _strdup - duplicate a string.
 * @s: string to duplicate
 * Return: duplicate string
 */
char *_strdup(char *s)
{
	char *dup;

	dup = malloc((1 + _strlen(s)) * sizeof(char));
	if (!dup)
		return (NULL);
	dup = _strcpy(dup, s);
	return (dup);
}
