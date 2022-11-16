#include <unistd.h>
#include <stdlib.h>

/**
 * _putchar - prints on character to standard output
 * @c: character
 *
 * Return: void
 */
void _putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);
}
