/*
** EPITECH PROJECT, 2020
** my_lib
** File description:
** free_to_null.c
*/

#include "my.h"

char *free_char_to_null(char *str)
{
    if (str)
        free(str);
    str = NULL;
    return str;
}
