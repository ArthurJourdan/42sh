/*
** EPITECH PROJECT, 2020
** my_lib_file
** File description:
** check_comments.c
*/

#include "my.h"

bool check_comments(char *str)
{
    size_t a = 0;

    for (; str[a] && str[a] <= ' '; a++);
    if (str[a] == '#')
        return true;
    return false;
}