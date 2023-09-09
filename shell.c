#include "main.h"
/**
 * main - simple shell.
 * @ac: argumrnt count.
 * @av: argument vector.
 *
 * Return: Always 0.
 */
int main(__attribute__((unused)) int ac, char **av)
{
	pid_t cpid;
	int sts, n = 0;
	size_t len = 0;
	char *tmp = NULL, *nil = NULL;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "$ ", 2);
		n = getline(&tmp, &len, stdin);
		if (n == EOF)
			exit(0);
		tmp[_strlen(tmp) - 1] = '\0';
		cpid = fork();
		if (cpid == -1)
		{
			write(STDERR_FILENO, av[0], _strlen(av[0]));
			write(STDERR_FILENO, ": ", 2);
			perror(NULL);
			return (1);
		}
		if (cpid == 0)
		{
			if (execve(tmp, &nil, environ) == -1)
			{
				write(STDERR_FILENO, av[0], _strlen(av[0]));
				write(STDERR_FILENO, ": ", 2);
				perror(NULL);
				return (1);
			}
		}
		else
			wait(&sts);
	}
	return (0);
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

