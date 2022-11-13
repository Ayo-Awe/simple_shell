#include "main.h"

/**
 * print_array - prints an array of strings to stdout
 * @array: array of strings
 *
 * Return: void
*/
void print_array(char **array)
{
	if (!array)
		return;

	while (*array)
	{
		_puts(*array);
		_putchar('\n');
		array++;
	}
}
