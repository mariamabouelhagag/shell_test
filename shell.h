#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <wait.h>
void cmd_loop(char **ar, char **env);
void execute(char **argv);

#endif
