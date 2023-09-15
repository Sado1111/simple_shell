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
/**
 * _strcmp - compares two strings.
 * @s1: the first.
 * @s2: The second.
 *
 * Return: 0 if they're the same, a negative value if
 * s2 > s1, a positive value if s1 > s2. (i.e: *s1 - *s2).
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}
