/*
** EPITECH PROJECT, 2019
** my_strncpy.c
** File description:
** copy n number of string
*/

#include "minishell.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    for (; src[i] != '\0'; i++) {
        if (i < n)
            dest[i] = src[i];}
    dest[i] = '\0';
    return (dest);
}
