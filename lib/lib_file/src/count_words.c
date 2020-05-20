/*
** EPITECH PROJECT, 2020
** my_lib
** File description:
** count_words_in_str.c
*/

#include "my.h"

static bool is_word(char *str, size_t pos)
{
    if (*(str + pos) <= ' ') {
        if (*(str + pos + 1) >= '!' && *(str + pos + 1) <= '~') {
            return true;
        }
    }
    return false;
}

size_t count_words_in_str(char * const str)
{
    size_t pos = 0;
    size_t nb_words = 1;

    if (!str)
        return 0;
    if (my_str_is_nothing(str))
        return 0;
    while (*(str + pos) <= ' ')
        pos++;
    while (*(str + pos)) {
        if (is_word(str, pos)) {
            nb_words++;
            pos++;
        }
        pos++;
    }
    return nb_words;
}

size_t count_words(char **arr)
{
    size_t words = 0;

    if (!arr)
        return 0;
    for (size_t a = 0; arr[a]; a++) {
        words += count_words_in_str(arr[a]);
    }
    return words;
}
