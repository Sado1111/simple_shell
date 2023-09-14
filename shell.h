#ifndef SHELL_H
#define SHELL_H

/* Global variable */
extern char **environ;

/* Headers */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

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

#endif
