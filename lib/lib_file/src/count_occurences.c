/*
** EPITECH PROJECT, 2020
** my_lib
** File description:
** count_occurences.c
*/

#include "my.h"

size_t count_occurences_in_str(char * const word, char * const str)
{
    size_t occurences = 0;
    size_t len_word = my_strlen(word);

    if (!str || !word || !len_word)
        return 0;
    for (size_t pos = 0; str[pos]; pos++) {
        if (my_str_n_cmp(word, str + pos, len_word)) {
            occurences++;
        }
    }
    return occurences;
}

size_t count_occurences(char * const word, char * const * const arr)
{
    size_t occurences = 0;

    if (!arr || !word)
        return 0;
    for (size_t a = 0; arr[a]; a++) {
        occurences += count_occurences_in_str(word, arr[a]);
    }
    return occurences;
}
