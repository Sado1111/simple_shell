#ifndef SHELL_H
#define SHELL_H

extern char **environ;
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

int _strlen(char *s);

#endif
