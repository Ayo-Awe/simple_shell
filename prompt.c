#include "main.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * prompt - shows shell prompt and waits for user to
 * enter a command
 *
 * Return: void
*/
char *prompt(void)
{
	char *input = NULL;
	ssize_t chars_read;
	size_t size = 0;

	_puts("#aweshell$ ");
	chars_read = getline(&input, &size, stdin);

	if (chars_read == -1)
		perror("Couldn't read input");

	/* Get rid of the new line character*/
	input[chars_read - 1] = ' ';

	return (input);
}
