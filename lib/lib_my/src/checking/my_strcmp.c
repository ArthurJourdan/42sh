/*
** EPITECH PROJECT, 2020
** my_lib
** File description:
** my_strcmp.c
*/

#include "my.h"

bool my_strcmp(char const *str_1, char const *str_2)
{
    int len_1 = my_strlen(str_1);
    int len_2 = my_strlen(str_2);

    if (len_1 != len_2)
        return false;
    if (!str_1 || !str_2)
        return false;
    for (int a = 0; a < len_1; a++)
        if (*(str_1 + a) != *(str_2 + a))
            return false;
    return true;
}

bool my_str_n_cmp(char const *str_1, char const *str_2, int len)
{
    if (!str_1 || !str_2)
        return false;
    for (int a = 0; a < len; a++) {
        if (!str_1[a] || !str_2[a])
            return false;
        if (*(str_1 + a) != *(str_2 + a))
            return false;
    }
    return true;
}
