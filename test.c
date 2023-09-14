#include "shell.h"
/**
 * main - test parse.
 *
 * Return: Always 0.
 */
int main(__attribute__((unused)) int ac, char **av)
{
	pid_t cp;
	char *tmp = NULL, **cm;
	size_t len = 0;
	int i = 0; 

	while(1)
	{
		if (isatty(STDIN_FILENO) != -1)
			printf("($) ");
		if (getline(&tmp, &len, stdin) == -1)
			exit(0);
		tmp[_strlen(tmp) - 1] = '\0';
		cm = parse(tmp);
		cp = fork();
		if (cp == -1)
			_perror("%s: ", av[0]);
		if (cp == 0)
		{
			if (execve(cm[0], cm, environ) == -1)
				_perror("%s: ", av[0]);
		}
		else
			wait(&i);
		free_cm(cm);
		free(tmp);
	}
	return (0);
}
