#include "shell.h"
/**
 * _strdup - duplicate a string.
 * @s: a given string to duplicate.
 *
 * Return: a newly allocated space in mem.
 */
char *_strdup(char *s)
{
	int i;
	char *d;

	d = malloc(sizeof(char) * _strlen(s) + 1);
	if (d == NULL || s == NULL)
		return (NULL);
	for (i = 0; s[i]; i++)
		d[i] = s[i];
	d[i] = '\0';
	return (d);
}
/**
 * _strlen - computes the length  of s.
 * @s:  a given string.
 *
 * Return: the length.
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;
	return (len);
}
