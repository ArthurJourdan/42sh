/*
** EPITECH PROJECT, 2020
** lib
** File description:
** my_str_to_word_arr.c
*/

#include "my.h"
#include "file.h"

static size_t len_word(char *word)
{
    size_t len = 0;

    while (*(word + len) && *(word + ++len) > ' ');
    return len;
}

static char *fill_word(char *str, size_t pos_in_str)
{
    size_t len_act_word = len_word(str + pos_in_str);
    char *word = malloc(sizeof(char) * len_act_word + 1);

    for (size_t pos_in_word = 0; pos_in_word < len_act_word; pos_in_word++) {
        word[pos_in_word] = *(str + pos_in_str++);
    }
    word[len_act_word] = '\0';
    return word;
}

char **my_str_to_word_arr(char *str)
{
    size_t pos_in_str = 0;
    size_t wich_arr = 0;
    char **word_arr;
    size_t nb_words = count_words_in_str(str);

    if (!nb_words)
        return NULL;
    word_arr = malloc(sizeof(char *) * (nb_words + 1));
    while (wich_arr < nb_words) {
        while (*(str + pos_in_str) <= ' ')
            pos_in_str++;
        word_arr[wich_arr] = fill_word(str, pos_in_str);
        wich_arr++;
        while (*(str + pos_in_str) && *(str + pos_in_str) > ' ')
            pos_in_str++;
    }
    word_arr[nb_words] = NULL;
    return word_arr;
}
