#include "shell.h"

/**
 * contains_non_digit - finds out if string contains non-digit/not
 * @s: the variable storing string to be checked
 * Return: 1 string has non-digit value, else 0 if it's only digits
 */

int contains_non_digit(const char *s)
{
	while (*s)
	{
		if (*s < 0 || *s > 9)
			return (1)
		s++;
	}
	return (0);
}

/**
 * parse_input - tokenizes inputted command into arguments
 * @input: command written by user to stdin
 * @args: arguments stored in an array, from tokenizing command
 * Return: number of arguments stored in args array
 */

int parse_input(char *input, char *args[])
{
	int i = 0;
	char *cmd_token = strtok(input, " \n\t\r");

	while (cmd_token)
	{
		args[i] = token;
		i++;
		cmd_token = strtok(NULL, " \n\t\r");
	}
	args[i] = NULL;
	return (i);
}
/**
 * shell_exit - treats all possible use of exit built in command
 * @args: tokenized inputted command array stored as arguments
 * @shell_name: name of our shell being run
 * @cmd_count: no of commands entered from when shell is run
 * @status: exit status of last command entered
 * @input: command entered by user from stdin (usually keyboard)
 * Return: exit status based on whether/not exit cmd has arguments
 */

int shell_exit(char *args[], const char *shell_name,
			int cmd_count, int status, char *input)
{
	if (args[1] == NULL)
	{
		free(input);
		exit(status);
	}
	else if (contains_non_digit(args[1]) == 0)
	{
		status = atoi(args[1]);
		free(input);
		exit(status);
	}
	else
	{
		fprintf(stderr, "%s: %d: exit: Illegal number: %s",
				shell_name, cmd_count, args[1]);
		status = 2;
	}
	return (status);
}


/**
 * print_env_variables - prints all environment variables to stdout
 * @status: exit status
 * Return: returns 0 when carried out successfully
 */

int print_env_variables(int status)
{
	char **env_variables_ptr = environ;

	UNUSED(status);

	while (*env_variables_ptr)
	{
		printf("%s\n", *env_variables_ptr);
		env_variables_ptr++;
	}
	return (0);
}
