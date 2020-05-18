/*
** EPITECH PROJECT, 2019
** my_strcpy.c
** File description:
** to copy a string into another
*/

#include "minishell.h"

char *my_strcpy1(char *dest , char const *src)
{
    int i = 0;
    for (; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return (dest);
}
