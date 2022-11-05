#include "main.h"
#include <unistd.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - entry point
 * @argc: numbers of command line arguments
 * @argv: array of command line arguments
*/
int main(__attribute__((unused)) int argc,__attribute__((unused))  char* argv[],__attribute__((unused))  char *env[])
{
	pid_t child;
	char *input = NULL;
	int status;

	char *args[] = {"", NULL};

	while (*(input = prompt()) != EOF)
	{
		child = fork();

		if (child == 0)
		{
			if (execv(input, args) == -1)
			{
				perror(argv[0]);
				return (1);
			}
		}
		else
		{
			wait(&status);
		}

	}

	return (0);
}

