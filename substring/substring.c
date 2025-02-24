#ifndef SUBSTRING_H
#define SUBSTRING_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int *find_substring(char const *s, char const **words, int nb_words, int *n);

#endif /* SUBSTRING_H */

#include "substring.h"

int *find_substring(char const *s, char const **words, int nb_words, int *n) {
    int word_len = strlen(words[0]);
    int str_len = strlen(s);
    int substr_len = word_len * nb_words;
    int *indices = malloc(str_len * sizeof(int));
    int count = 0;

    if (!indices) return NULL;

    for (int i = 0; i <= str_len - substr_len; i++) {
        char temp[substr_len + 1];
        strncpy(temp, s + i, substr_len);
        temp[substr_len] = '\0';

        int found = 1;
        for (int j = 0; j < nb_words; j++) {
            if (!strstr(temp, words[j])) {
                found = 0;
                break;
            }
        }
        
        if (found) {
            indices[count++] = i;
        }
    }

    *n = count;
    return realloc(indices, count * sizeof(int));
}
