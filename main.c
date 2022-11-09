#include "main.h"
#include <unistd.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void fork_n_execute(char **args, char *env[], char *argv[]);

/**
 * main - entry point
 * @argc: numbers of command line arguments
 * @argv: array of command line arguments
 * @env: environment variables
 *
 * Return: Always 0
*/
int main(__attribute__((unused)) int argc, char *argv[], char *env[])
{
	char *input = NULL, *cmd;
	char **args;
	int exitCode = 1;

	while (*(input = prompt()) != EOF)
	{

		args = split(input);
		free(input);

		/* Check if command is  an exit shell command*/
		if (_strcmp(args[0], "exit") == 0)
		{
			exitCode = _atoi(args[1]);
			if (exitCode == -1)
				exit(1);

			exit(exitCode);
		}

		/* Get full command path e.g ls -> /bin/ls */
		cmd = get_command(args[0]);

		if (!cmd)
		{
			/* If command doesn't exist skip the current execute */
			printf("%s: command not found\n", args[0]);
			free_split(args);
			continue;
		}

		/* Free previous command before overwriting it*/
		free(args[0]);
		args[0] = cmd;

		/* Create a child process and execute the command in the child process*/
		fork_n_execute(args, env, argv);

		/* Free all args */
		free_split(args);
	}

	return (0);
}

/**
 * fork_n_execute - creates a child process of the main process and executes a
 * command in it
 * @args: An array containing the command and the command arguments where
 * args[0] is the command itself
 * @env: An array of the environment variables
 * @argv: The array arguments passed into the executing program
 *
 * Return: void
*/
void fork_n_execute(char **args, char *env[], char *argv[])
{
	pid_t child;
	int status;

	child = fork();

	/* Execute command only if the current process is the child process*/
	if (child == 0)
	{
		if (execve(args[0], args, env) == -1)
		{
			perror(argv[0]);
			exit(1);
		}
	}
	else
	{
		/* Wait for child process to exit before continuing*/
		wait(&status);
	}

}
