/*
** EPITECH PROJECT, 2020
** my_lib
** File description:
** get_pos_word_in_str.c
*/

#include "my.h"

ssize_t get_pos_word_in_str(char const  *word, char const *str)
{
    size_t pos = 0;

    if (!word || !str)
        return -1;
    while (str[pos]) {
        if (my_str_n_cmp(word, str + pos, my_strlen(word))) {
            return pos;
        }
        pos++;
    }
    return -1;
}

ssize_t get_pos_word_end_in_str(char const *word, char const *str)
{
    size_t pos = 0;

    if (!word || !str)
        return -1;
    while (str[pos]) {
        if (my_str_n_cmp(word, str + pos, my_strlen(word))) {
            return pos + my_strlen(word);
        }
        pos++;
    }
    return -1;
}
