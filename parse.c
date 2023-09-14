#include "shell.h"
/**
 * parse - parses a command into portions.
 * @av: array of strings.
 * @line: a given command.
 *
 * Return: array of the command's portions.
 */
char **parse(char *line)
{
	char **ae, *tk, *tmp;
	char d[] = " ";
	int i = 0;

	tk = _strdup(line);
	ae = malloc(sizeof(char *) * (nportion(line, d) + 1));
	tmp =  strtok(tk, d);
	while (tmp)
	{
		ae[i] = _strdup(tmp);
		tmp = strtok(NULL, d);
		i++;
	}
	ae[i] = NULL;
	free(tk);
	free(tmp);
	return (ae);
}
/**
 * nportion - counts the portion of a str.
 * @s: string.
 * @d: a delimiter.
 *
 * Return: the number of portions.
 */
int nportion(char *s, char *d)
{
	int c = 0, i = 0;

	for (i = 0; s[i]; i++)
	{
		if (s[i] == *d && s[i + 1] != *d)
			c++;
	}
	return (c + 1);
}
/**
 * free_cm - frees a 2D array.
 * @cm: 2D array.
 *
 * Return: Nothing.
 */
void free_cm(char **cm)
{
	int i = 0;

	while (cm[i])
	{
		free(cm[i]);
		i++;
	}
	free(cm);
}
