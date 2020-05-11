/*
** EPITECH PROJECT, 2020
** my_lib
** File description:
** my_sep_parser.c
*/

#include "my.h"
#include "file.h"

static int count_words_sep(char *str, char * const sep)
{
    int a = 0;
    int nb_words = 0;

    if (str == NULL)
        return 0;
    nb_words += count_occurences_in_str(sep, str);
    if (nb_words)
        nb_words++;
    return nb_words;
}

static char *fill_word_arr(char * const str, char * const sep, int *pos_in_str)
{
    char *act_word = NULL;

    act_word = my_str_cpy_until_str(str + *(pos_in_str), sep);
    *(pos_in_str) += my_strlen(act_word) + 1;
    return act_word;
}

char **my_sep_parser(char * const str, char * const sep)
{
    int pos_in_str = 0;
    int wich_arr = 0;
    char **word_arr = NULL;
    char *act_word = NULL;
    int nb_words = count_words_sep(str, sep);

    if (!nb_words)
        return NULL;
    while (wich_arr < nb_words) {
        act_word = fill_word_arr(str, sep, &pos_in_str);
        word_arr = add_str_to_arr(word_arr, act_word, true, true);
        wich_arr++;
    }
    return word_arr;
}
