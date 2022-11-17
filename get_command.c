#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
 * get_command - checks if a command exists
 * @command: a malloc'd string pointer representing command
 *
 * Return: pointer to original command string if command
 * exists without /bin/ prefix,
 * a malloc'd string if prefix was needed otherwise NULL
 */
char *get_command(char *command)
{
	struct stat st;
	char *full_command = NULL;
	path_t *current, *head = NULL;
	char *command_copy = _strdup(command);

	if (!command || !command_copy)
		return (NULL);

	/* Path exists */
	if (lstat(command_copy, &st) == 0)
	{
		return (command_copy);
	}

	free(command_copy);

	if (generate_path_list(&head) == NULL)
		return (NULL);

	current = head;
	while (current)
	{
		full_command = prefix(current->path, command);

		if (!full_command)
			return (NULL);

		/* Path exists */
		if (lstat(full_command, &st) == 0)
		{
			free_path_list(&head);
			return (full_command);
		}

		free(full_command);
		current = current->next;
	}

	free_path_list(&head);
	return (NULL);
}
