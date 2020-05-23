/*
** EPITECH PROJECT, 2020
** my_lib_file
** File description:
** get_pos_word_in_double_arr.c
*/

#include "file.h"
#include "my.h"

ssize_t get_pos_word_in_double_arr(char const *word, char const **arr)
{
    if (!word || !arr)
        return -1;
    for (size_t line = 0; arr[line]; line++) {
        if (get_pos_word_in_str(word, arr[line]) != -1)
            return line;
    }
    return -1;
}

ssize_t get_index_word_begin_in_arr(char const *word, char **arr)
{
    size_t len = 0;

    if(!word || !arr)
        return (-1);
    len = my_strlen(word);
    for (size_t pos = 0; arr[pos]; pos++) {
        if (my_str_n_cmp(word, arr[pos], len))
            return pos;
    }
    return (-1);
}