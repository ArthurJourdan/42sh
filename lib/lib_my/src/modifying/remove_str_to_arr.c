/*
** EPITECH PROJECT, 2020
** my_lib
** File description:
** remove_str_to_arr.c
*/

#include "my.h"
#include "file.h"
#include "print.h"

static char **fill_new_arr(char **arr, size_t index_str, size_t len)
{
    char **new_arr = malloc(sizeof(char *) * (len + 1));
    size_t a = 0;

    if (!new_arr)
        return NULL;
    for (size_t b = 0; a < len; b++) {
        if (b != index_str) {
            new_arr[a++] = my_strcpy(arr[b]);
        }
    }
    new_arr[len] = NULL;
    return new_arr;
}

char **remove_str_to_arr(char **arr, size_t index_str, bool to_free)
{
    size_t len = my_arrlen(arr) - 1;
    char **new_arr = NULL;

    if (!arr || len < 1 || index_str > len)
        return NULL;
    new_arr = fill_new_arr(arr, index_str, len);
    if (to_free)
        free_double_char_arr(arr);
    return new_arr;
}