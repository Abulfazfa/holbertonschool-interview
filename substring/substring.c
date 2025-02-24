#ifndef SUBSTRING_H
#define SUBSTRING_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int *find_substring(char const *s, char const **words, int nb_words, int *n);

#endif /* SUBSTRING_H */

#include "substring.h"

/**
 * find_substring - Finds all the possible substrings containing a list of words
 * @s: The string to scan
 * @words: The array of words all substrings must be a concatenation of
 * @nb_words: The number of elements in the array words
 * @n: Pointer to store the number of elements in the returned array
 *
 * Return: An allocated array storing each index in s, at which a substring was found.
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
    int word_len, str_len, substr_len, *indices, count = 0, i, j;
    char *temp;
    int *word_count;

    if (!s || !words || nb_words == 0 || !n)
        return (NULL);

    word_len = strlen(words[0]);
    str_len = strlen(s);
    substr_len = word_len * nb_words;
    indices = malloc(str_len * sizeof(int));
    if (!indices)
        return (NULL);

    word_count = malloc(nb_words * sizeof(int));
    if (!word_count)
    {
        free(indices);
        return (NULL);
    }

    for (i = 0; i <= str_len - substr_len; i++)
    {
        memset(word_count, 0, nb_words * sizeof(int));
        for (j = 0; j < nb_words; j++)
        {
            temp = strndup(s + i + j * word_len, word_len);
            if (!temp)
                continue;
            for (int k = 0; k < nb_words; k++)
            {
                if (!strcmp(temp, words[k]) && word_count[k] == 0)
                {
                    word_count[k] = 1;
                    break;
                }
            }
            free(temp);
        }
        if (memchr(word_count, 0, nb_words * sizeof(int)) == NULL)
            indices[count++] = i;
    }
    
    free(word_count);
    *n = count;
    return (realloc(indices, count * sizeof(int)));
}
