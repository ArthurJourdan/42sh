/*
** EPITECH PROJECT, 2020
** my_lib
** File description:
** reverse_str.c
*/

#include "my.h"

void reverse_str(char *str)
{
    size_t len = my_strlen(str) - 1;
    char *cpy = my_strcpy(str);

    if (!cpy)
        return;
    for (size_t a = 0; a <= len; a++) {
        str[a] = cpy[len - a];
    }
    free(cpy);
}