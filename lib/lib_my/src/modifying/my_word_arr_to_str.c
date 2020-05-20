/*
** EPITECH PROJECT, 2020
** my_lib
** File description:
** my_word_arr_to_str.c
*/

#include "my.h"

char *my_word_arr_to_str(char **arr)
{
    size_t len_arr = my_arrlen(arr);
    char *str = NULL;

    for (size_t a = 0; a < len_arr; a++) {
        str = my_strcat(str, arr[a], true, false);
    }
    return str;
}