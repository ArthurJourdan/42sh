/*
** EPITECH PROJECT, 2020
** my_lib
** File description:
** arr_from_hard_quote.c
*/

#include "my.h"

char **arr_from_hard_quote(size_t ac, ...)
{
    char **arr = NULL;
    va_list ap;

    va_start(ap, ac);
    for (size_t a = 0; a < ac; a++)
        arr = add_str_to_arr(arr, va_arg(ap, char *), true, false);
    va_end(ap);
    return arr;
}