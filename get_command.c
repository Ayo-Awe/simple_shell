#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"


/**
 * handle_command - checks if a command exists
 * @command: a malloc'd string pointer representing command
 *
 * Return: pointer to original command string if command
 * exists without /bin/ prefix,
 * a malloc'd string if prefix was needed otherwise NULL
*/
char *get_command(char *command)
{
	struct stat st;
	char *prefixed_command = prefix("/bin/", command);

	if (!prefixed_command)
		return (NULL);

	/* Path doesn't exists */
	if (stat(command, &st) == 0)
	{
		free(prefixed_command);
		return (command);
	}
	else if (stat(prefixed_command, &st) == 0)
	{
		return (prefixed_command);
	}

	return (NULL);
}
