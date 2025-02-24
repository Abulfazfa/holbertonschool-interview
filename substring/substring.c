#ifndef SUBSTRING_H
#define SUBSTRING_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int *find_substring(char const *s, char const **words, int nb_words, int *n);

#endif /* SUBSTRING_H */

#include "substring.h"

/**
 * check_substring - Checks if a substring starting at index matches words
 * @s: The input string
 * @words: The words array
 * @nb_words: Number of words
 * @word_len: Length of each word
 *
 * Return: 1 if valid, 0 otherwise
 */
int check_substring(const char *s, 
    const char **words, int nb_words, int word_len)
{
	int found[nb_words];
	int i, j;

	memset(found, 0, sizeof(found));
	for (i = 0; i < nb_words; i++)
	{
		for (j = 0; j < nb_words; j++)
		{
			if (!found[j] && strncmp(s + i * word_len, words[j], word_len) == 0)
			{
				found[j] = 1;
				break;
			}
		}
		if (j == nb_words)
			return (0);
	}
	return (1);
}

/**
 * find_substring - Finds all valid substrings made from words
 * @s: The input string
 * @words: Array of words
 * @nb_words: Number of words
 * @n: Output parameter to store the number of found substrings
 *
 * Return: Array of starting indices, or NULL if none found
 */
int *find_substring(const char *s, const char **words, int nb_words, int *n)
{
	int str_len, word_len, substr_len, *indices, count = 0, i;

	if (!s || !words || nb_words == 0 || !n)
		return (NULL);

	word_len = strlen(words[0]);
	str_len = strlen(s);
	substr_len = word_len * nb_words;
	indices = malloc(str_len * sizeof(int));
	if (!indices)
		return (NULL);

	for (i = 0; i <= str_len - substr_len; i++)
	{
		if (check_substring(s + i, words, nb_words, word_len))
			indices[count++] = i;
	}

	*n = count;
	return (realloc(indices, count * sizeof(int)));
}
