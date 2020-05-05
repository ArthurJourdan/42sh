/*
** EPITECH PROJECT, 2020
** my_lib
** File description:
** my_memset.c
*/

#include "my.h"

void my_memset_char_arr(char **arr, char *ptr, size_t len)
{
    if (!arr)
        return;
    for (size_t a = 0; a < len; a++) {
        arr[a] = ptr;
    }
    arr[len - 1] = NULL;
}

void my_memset_str(char *array, int c, size_t len)
{
    if (!array)
        return;
    for (size_t a = 0; a < len; a++) {
        array[a] = c;
    }
    array[len - 1] = '\0';
}
