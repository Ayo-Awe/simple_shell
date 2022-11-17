#include "main.h"
#include <unistd.h>
#include <stdlib.h>

path_t *add_path_node(path_t **head, char *path);
int count_chars_to_delimiter(char *str);

/**
 * generate_path_list - generates a linked list from the path environment var
 * @head: pointer to pointer to list head
 *
 * Return: pointer to list head on success or NULL on error
 */
path_t *generate_path_list(path_t **head)
{
	int offset = 0;
	char *path, *tmp, *path_env = _getenv("PATH");

	path = NULL;

	if (!path_env)
		return (NULL);

	tmp = path_env;

	while (*path_env)
	{
		if (*path_env == ':')
			path_env++;

		offset = count_chars_to_delimiter(path_env);

		if (offset == -1)
			return (NULL);

		path = malloc(sizeof(char) * (offset + 2));

		_strncpy(path, path_env, offset);
		_strcat(path, "/");

		if (add_path_node(head, path) == NULL)
		{
			free(path);
			free(tmp);
			free_path_list(head);
			return (NULL);
		}

		path_env += offset;
	}

	free(tmp);
	return (*head);
}

/**
 * count_chars_to_delimiter - counts the number of characters
 * before the delimeter :
 * @str: string pointer with values seperated by :
 *
 * Return: number of characters before the delimeter
 */
int count_chars_to_delimiter(char *str)
{
	int count = 0;

	if (!str)
		return (-1);

	while (*str && *str != ':')
	{
		count++;
		str++;
	}

	return (count);
}

/**
 * add_path_node - adds a new node to a path_t linked list
 * @head: pointer to pointer to head
 * @path: string pointer for path
 *
 * Return: pointer to new node or NULL on error
 */
path_t *add_path_node(path_t **head, char *path)
{
	path_t *node, *current;

	current = node = NULL;

	if (!head)
		return (NULL);

	if (*head == NULL)
	{
		node = malloc(sizeof(path_t));

		if (!node)
			return (NULL);

		node->path = path;
		node->next = NULL;

		*head = node;

		return (node);
	}

	current = *head;
	while (current->next)
		current = current->next;

	node = malloc(sizeof(path_t));

	if (!node)
		return (NULL);

	node->path = path;
	node->next = NULL;
	current->next = node;

	return (node);
}
