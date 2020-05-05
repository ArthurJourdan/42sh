/*
** EPITECH PROJECT, 2020
** lib_my
** File description:
** free_arr.c
*/

#include "my.h"

void free_double_char_arr(char **arr)
{
    size_t a = 0;

    if (!arr)
        return;
    for (; arr[a]; a++) {
        free(arr[a]);
    }
    free(arr);
}

void free_triple_char_arr(char ***arr)
{
    size_t a = 0;

    if (!arr)
        return;
    for (; arr[a]; a++) {
        free_double_char_arr(arr[a]);
    }
    free(arr);
}
