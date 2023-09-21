#ifndef SHELL_H
#define SHELL_H

/* Global variable */
extern char **environ;

/* Headers */
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* Macros */
#define KB_LENGTH 1024
#define UNUSED(x) (void)(x)

/* Functions */
int _strlen(char *);
void free_cm(char **);
char **parse(char *);
int nportion(char *, char *);
char *_strcpy(char *, char *);
void _perror(const char *, ...);
int _putchar(char);
void print_str(va_list);
char *_strdup(char *);
int contains_non_digit(const char *s);
int shell_exit(char *args[],
		const char *shell_name, int cmd_count,
		int status, char *input);
int print_env_variables(int status);
int run_external_cmd(char *args[]);
int find_and_execute(char *args[],
		const char *shell_name, int cmd_count);
int check_N_execute(char *args[],
		const char *shell_name, int cmd_count,
		int status, char *input);
char *derive_ourShellName();
int parse_input(char *input, char *args[]);
void handle_cd(char *args[], const char *shell_name, int cmd_count);
void print_cd_error(const char *error_type,
const char *shell_name, int cmd_count);
void change_directory_to_home(const char *shell_name, int cmd_count);
void change_directory_to_specified(const char *directory,
const char *shell_name, int cmd_count);
void change_directory_to_previous(const char *shell_name, int cmd_count);
void change_directory(char *args[], const char *shell_name, int cmd_count);

#endif
