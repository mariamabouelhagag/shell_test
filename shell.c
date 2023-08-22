#include "shell.h"

int main(int argc, char **argv)
{
	char *cmd = NULL, *cmd_copy = NULL, *token = NULL;
	char *delim = " \n";
	size_t n = 0;
	int i = 0;
	argc = 0;

	while (1 < 2)
	{
		printf(":) ");
		int value = getline(&cmd, &n, stdin);
		if (value == -1)
		{
			free(cmd);
			exit(EXIT_FAILURE);
		}
		else
		{
			while (cmd[i])
			{
				if (cmd[i] == '\n')
				{ cmd[i] = 0;}
				i ++;
			}
			
			cmd_copy = strdup(cmd);
			token = strtok(cmd_copy, delim);
			argv[0] = token;
			pid_t pid;
			int execute;
			
			pid = fork();
			if (pid == -1)
			{
				perror(getenv("_"));
			}
			if (pid == 0)
			{
				execve(argv[0], argv, __environ);
				perror(argv[0]);
				exit(EXIT_FAILURE);
			}
			else if (pid > 0)
			{
				wait(&execute);
			}
		}
	}
}
