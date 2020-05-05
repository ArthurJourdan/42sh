/*
** EPITECH PROJECT, 2020
** my_lib
** File description:
** add_str_to_arr.c
*/

#include "my.h"

char **add_str_to_arr(char **arr, char *str, bool free_arr, bool free_str)
{
    size_t len = my_arrlen(arr);
    char **new_arr = malloc(sizeof(char *) * (len + 2));

    if (!new_arr)
        return NULL;
    my_memset_char_arr(new_arr, NULL, len + 2);
    double_char_arr_dup(arr, new_arr);
    new_arr[len] = my_strcpy(str);
    new_arr[len + 1] = NULL;
    if (free_arr)
        free_double_char_arr((char **)arr);
    if (free_str)
        free(str);
    return new_arr;
}