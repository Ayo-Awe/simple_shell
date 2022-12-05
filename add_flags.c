#include "main.h"
#include <stdlib.h>

int chars_before_space(char *str);
/**
 * add_option - adds a flag option to a command
 * @command: original string input before split
 * @flag: option to be added
 * @value: option to be added
 *
 * Return: pointer to an array of strings
 */

char *add_option(char *command, char *flag, char *value)
{
	char *option = NULL;
	char *new_command = NULL;
	int len = 0;

	if (!command || !flag || !value)
		return (NULL);

	/* Length of flag, value plus = sign and null byte*/
	len = _strlen(flag) + _strlen(value) + 2;

	option = malloc(sizeof(char *) * len);

	if (!option)
		return (NULL);

	/* Copy flag, value and = into option variable */
	_strcpy(option, flag);
	_strcat(option, "=");
	_strcat(option, value);

	/* Create new command string with flag included */
	len = _strlen(option) + _strlen(command) + 2;

	new_command = malloc(sizeof(char) * len);

	_strncpy(new_command, command, chars_before_space(command));
	_strcat(new_command, " ");
	_strcat(new_command, option);
	_strcat(new_command, (command + chars_before_space(command)));

	free(option);

	return (new_command);
}

/**
 * chars_before_space - counts the number of characters before a
 * space in string
 * @str: string pointer
 *
 * Return: number of characters or -1 on error
 */
int chars_before_space(char *str)
{
	int num = 0;

	if (!str)
		return (-1);

	while (*str && *str != ' ')
	{
		num++;
		str++;
	}

	return (num);
}
