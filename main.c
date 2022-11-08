#include "main.h"
#include <unistd.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

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
	pid_t child;
	char *input = NULL;
	int status;

	char **args;

	while (*(input = prompt()) != EOF)
	{

		args = split(input);

		if (_strcmp(args[0], "exit") == 0)
		{
			free(input);
			exit(1);
		}


		child = fork();


		if (child == 0)
		{
			if (execve(args[0], args, env) == -1)
			{
				perror(argv[0]);
				return (1);
			}
		}
		else
		{
			wait(&status);
		}

		free(input);
	}

	return (0);
}

