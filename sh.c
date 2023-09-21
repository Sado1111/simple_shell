#include "shell.h"

/**
 * run_external_cmd - executes external commands passed as input
 * @args: array of arguments gotten from inputted command
 * Return: exit status value of last command inputted
 */
int run_external_cmd(char *args[])
{
	int status;
	pid_t cp = fork();


	if (cp < 0)
	{
		fprintf(stderr, "Fork failed\n");
		return (-1);
	}
	else if (cp == 0)
	{
		execvp(args[0], args);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
	}

	return (status);
}

/**
 * find_and_execute - searches PATH for external executable commands
 * @args: array of arguments from tokenized inputted command
 * @shell_name: simple_shell's name
 * @cmd_count: no. of commands inputted by user since shell was run
 * Return: last command's exit status value to be passed in exit function
 */

int find_and_execute(char *args[], const char *shell_name, int cmd_count)
{
	char *pathToken;
	char path[KB_LENGTH], cmd_path[KB_LENGTH];
	struct stat file_info;
	int status = 0, found = 0;

	strcpy(path, getenv("PATH"));
	pathToken = strtok(path, ":");
	if (stat(args[0], &file_info) != 0)
	{
		while (pathToken != NULL)
		{
			strcpy(cmd_path, pathToken);
			strcat(cmd_path, "/");
			strcat(cmd_path, args[0]);

			if (access(cmd_path, X_OK) == 0)
			{
				found = 1;
				status = run_external_cmd(args);
				break;
			}
			pathToken = strtok(NULL, ":");
		}
	}
	else
	{
		found = 1;
		status = run_external_cmd(args);
	}
	if (found != 1)
	{
		status = 127;
		fprintf(stderr, "%s: %d: %s: not found\n", shell_name,
				cmd_count, args[0]);
	}
	return (status);
}

/**
 * check_N_execute - checks if args[0] is a built-in / external cmd
 * @args: array of arguments from tokenized inputted command
 * @shell_name: name of simple shell being run
 * @cmd_count: no of commands inputted since shell has been run
 * @status: last command's exit status
 * @input: last command inputted by user to be tokenized and used
 *
 * Return: exit status stored in variable status
 */

int check_N_execute(char *args[], const char *shell_name,
		int cmd_count, int status, char *input)
{
	if (strcmp(args[0], "exit") == 0)
		status = shell_exit(args, shell_name, cmd_count, status, input);
	else if (strcmp(args[0], "env") == 0)
		status = print_env_variables(status);
	else
		status = find_and_execute(args, shell_name, cmd_count);

	return (status);
}

/**
 * derive_ourShellName - uses getenv() to derive the shell name
 *
 * Return: pointer to char (strings) which the shell name derived
 */

char *derive_ourShellName()
{
	char *shell_name;

	shell_name = getenv("_");
	return (shell_name);
}

/**
 * main -  entry point of the simple shell program
 * Return: Always 0.
 */
int main(void)
{
	char *input = NULL, *args[KB_LENGTH];
	size_t len = 0;
	const char *shell_name;
	int cmd_count = 0, status = 0;

	shell_name = derive_ourShellName();

	while (1)
	{
		cmd_count++;

		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);
		if (getline(&input, &len, stdin) == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			free(input);
			exit(0);
		}

		input[_strlen(input) - 1] = '\0';

		parse_input(input, args);
		if (args == NULL || args[0] == NULL)
			continue;
		status = check_N_execute(args, shell_name, cmd_count, status, input);
	}
	free(input);
	return (status);
}
