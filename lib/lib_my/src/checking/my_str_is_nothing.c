/*
** EPITECH PROJECT, 2020
** lib
** File description:
** my_str_is_nothing.c
*/

#include "my.h"

bool my_char_is_nothing(char const c, bool alpha, bool num, bool up)
{
    if (alpha && c >= 'a' && c <= 'z')
        return true;
    if (num && c >= '0' && c <= '9')
        return true;
    if (up && c >= 'A' && c <= 'Z')
        return true;
    return false;
}

bool my_str_is_nothing(char const *str)
{
    if (!str)
        return true;
    for (int a = 0; *(str + a); a++) {
        if (my_char_is_nothing(*(str + a), true, true, true))
            return false;
    }
    return true;
}

bool my_quotation_is_nothing(char const *str)
{
    if (!str)
        return true;
    for (int a = 0; *(str + a) != '"'; a++) {
        if (my_char_is_nothing(*(str + a), true, true, true))
            return false;
    }
    return true;
}
