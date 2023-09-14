#include "shell.h"
/**
 * main - simple shell.
 * @ac: argumrnt count.
 * @av: argument vector.
 *
 * Return: Always 0.
 */
int main(__attribute__((unused)) int ac, char *av[])
{
	pid_t cpid;
	int sts, n = 0;
	size_t len = 0;
	char *tmp = NULL, **cm;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			printf("($) ");
		n = getline(&tmp, &len, stdin);
		if (n == -1)
			exit(0);
		tmp[len - 1] = '\0';
		cm = parse(tmp);
		cpid = fork();
		if (cpid == -1)
		{
			_perror("%s: ", av[0]);
			return (1);
		}
		else if (cpid == 0)
		{
			if (execve(cm[0], cm, environ) == -1)
			{
				_perror("%s: ", av[0]);
				return (1);
			}
		}
		else
			wait(&sts);
		free(tmp);
		free_cm(cm);
	}
	return (0);
}
