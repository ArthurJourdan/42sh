/*
** EPITECH PROJECT, 2020
** my_lib
** File description:
** my_sep_parser.c
*/

#include "my.h"
#include "file.h"

static char *fill_arr(char * const str, char * const sep, size_t *pos_in_str)
{
    char *act_word = NULL;

    act_word = my_str_cpy_until_str(str + *(pos_in_str), sep);
    *(pos_in_str) += my_strlen(act_word) + my_strlen(sep);
    return act_word;
}

char **my_sep_parser(char * const str, char * const sep)
{
    char **word_arr = NULL;
    char *act_word = NULL;
    size_t pos_in_str = 0;
    size_t wich_arr = 0;
    size_t nb_words = 0;

    if (!str || !sep)
        return NULL;
    nb_words = count_occurences_in_str(sep, str) + 1;
    while (wich_arr < nb_words) {
        act_word = fill_arr(str, sep, &pos_in_str);
        word_arr = add_str_to_arr(word_arr, act_word, true, true);
        wich_arr++;
    }
    return word_arr;
}
