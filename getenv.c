#include "shell.h"
/**
 * _getenv - look for name in the environement.
 * @name: the env var to search for.
 *
 * Return: a pointer to that var, otherwise NULL.
 */
char *_getenv(char *name)
{
	char *tmp = NULL;
	int i = 0;

	if (name == NULL)
		return (NULL);
	while (environ[i])
	{
		tmp = _strdup(environ[i]);
		if (_strcmp(strtok(tmp, "="), name) == 0)
		{
			free(tmp);
			return (_strdup(environ[i]));
		}
		i++;
	}
	return (NULL);
}
