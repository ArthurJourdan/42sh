/*
** EPITECH PROJECT, 2019
** my_strdup.c
** File description:
** string duplication
*/

#include<stdlib.h>
#include "minishell.h"

char *my_strdup(char const *src)
{
    char *dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    my_strcpy1(dest, src);
    return dest;
}
