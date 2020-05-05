/*
** EPITECH PROJECT, 2020
** my_lib
** File description:
** my_str_is_num.c
*/

#include "my.h"

bool my_str_is_num(char const *str)
{
    if (!str)
        return false;
    for (int a = 0; *(str + a); a++) {
        if (!my_char_is_alpha_num(*(str + a), false, true, false))
            return false;
    }
    return true;
}

bool my_str_is_float(char const *str)
{
    unsigned short coma = 0;
    if (!str)
        return false;
    for (int a = 0; *(str + a); a++) {
        if (my_char_is_alpha_num(*(str + a), false, true, false))
            continue;
        else if (*(str + a) == ',' || *(str + a) == '.') {
            coma++;
        } else
            return false;
        if (coma > 1)
            return false;
    }
    return true;
}