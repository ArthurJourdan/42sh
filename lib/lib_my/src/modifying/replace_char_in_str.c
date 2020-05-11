/*
** EPITECH PROJECT, 2020
** my_lib
** File description:
** replace_char_in_str.c
*/

#include "my.h"

void replace_char_in_str(char *str, char const old, char new)
{
    if (!str)
        return;
    for (size_t a = 0; str[a]; a++) {
        if (str[a] == old)
            str[a] = new;
    }
}

void replace_char_in_arr(char **arr, char const old, char new)
{
    if (!arr)
        return;
    for (size_t a = 0; arr[a]; a++) {
        replace_char_in_str(arr[a], old, new);
    }
}
