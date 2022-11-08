#include "main.h"
#include <stdlib.h>

int countWords(char *string);
int lengthOfNextWord(char *string);
int countWords(char *string);


/**
 * split - splits a string delimited by ' '
 * @string: string pointer
 *
 * Return: an array of malloc'd strings
*/
char **split(char *string)
{
	int number_of_words = countWords(string);
	char *word;
	char **words, **s;
	int jump = 0;

	if (number_of_words == 0)
		return (NULL);

	words = malloc(sizeof(char *) * (number_of_words + 1));
	s = words;

	if (words == NULL)
		return (NULL);


	while (*string)
	{
		if (*string != ' ')
		{
			jump = lengthOfNextWord(string);
			word = malloc(sizeof(char) * (jump + 1));

			if (!word)
				return (NULL);

			_strncpy(word, string, jump);
			string += jump;
			*s = word;
			s++;
		}

		string++;
	}
	words[number_of_words] = NULL;
	return (words);
}

/**
 * lengthOfNextWord - gets the length of the next word in a string
 * @string: string pointer
 *
 * Return: length of the next word in the string pointer
*/
int lengthOfNextWord(char *string)
{
	int i = 0;

	while (*(string + i) && *(string + i) != ' ')
		i++;

	return (i);
}

/**
 * countWords - returns the total number of words in the string
 * @string: string pointer
 *
 * Return: the number of words in the string pointer
*/
int countWords(char *string)
{
	int words = 0;
	int inWord = 0;

	while (*string)
	{
		if (*string != ' ' && inWord == 0)
		{
			words++;
			inWord = 1;
		}
		else if (*string == ' ')
		{
			inWord = 0;
		}

		string++;
	}

	return (words);
}
