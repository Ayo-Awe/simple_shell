#include "main.h"
#include <stdlib.h>

/**
 * free_path_list - frees a malloc'd path_t linked list
 * @head: pointer to the pointer to head
 *
 * Return: void
 */
void free_path_list(path_t **head)
{
	path_t *next, *current = NULL;

	if (!head)
		return;

	current = *head;
	while (current)
	{
		next = current->next;

		if (current->path)
			free(current->path);

		free(current);

		current = next;
	}

	*head = NULL;
}
