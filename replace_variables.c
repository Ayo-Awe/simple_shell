#include <stdlib.h>
#include "main.h"
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

char *_getenv(char *var, char **env);

/**
 * replace_variables - replaces variables in a shell program denoted by $
 * @args: array strings containing the command and its arguments
 * @status: exit status of previously executed program
 * @env: Array of environment variables
 *
 * Return:
*/
void replace_variables(char **args, int status, char **env)
{
	int i = 1;
	char *str;

	if (!args)
		return;

	while (args[i])
	{
		if (args[i][0] == '$' && args[i][1])
		{
			switch (args[i][1])
			{
			case '$':
				str = _itoa((int) getpid());
				break;

			case '?':
				str = _itoa(WEXITSTATUS(status));
				break;

			default:
				str = _getenv(&args[i][1], env);
				break;
			}

			free(args[i]);

			if (str)
				args[i] = str;
			else
				args[i] = _strdup("");
		}
		i++;
	}

}

/**
 * _getenv - gets the value of an environment variable
 * @var: name of environment variable
 * @env: array of environment variables
 *
 * Return: malloc'd string containing value of the variable
 * or NULL on error
*/
char *_getenv(char *var, char **env)
{
	int i = 0, len;
	char *str;

	if (!env || !var)
		return (NULL);

	while (env[i])
	{
		len = _strlen(var);

		/* the environment varible exists */
		if (_strncmp(var, env[i], len) == 0)
		{
			/*
			* Copy variable value to new malloc'd memory,
			* copy only after the = sign e.g PATH=WIE -> WIE
			 */
			str = _strdup(&env[i][len + 1]);

			if (!str)
				return (NULL);

			return (str);
		}
		i++;
	}

	return (NULL);
}
