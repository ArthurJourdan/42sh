/*
** EPITECH PROJECT, 2020
** lib
** File description:
** my_str_is_alpha_num.c
*/

#include "my.h"

bool my_char_is_alpha_num(char const c, bool alpha, bool num, bool up)
{
    int is_alpha = 0;

    if (alpha && c >= 'a' && c <= 'z')
        is_alpha++;
    if (num && c >= '0' && c <= '9')
        is_alpha++;
    if (up && c >= 'A' && c <= 'Z')
        is_alpha++;
    if (is_alpha)
        return true;
    return false;
}

bool my_str_is_alphanum(char const *str)
{
    if (!str)
        return false;
    for (int a = 0; *(str + a); a++) {
        if (!my_char_is_alpha_num(*(str + a), true, true, true))
            return false;
    }
    return true;
}

bool my_str_is_alpha(char const *str)
{
    if (!str)
        return false;
    for (int a = 0; *(str + a); a++) {
        if (!my_char_is_alpha_num(*(str + a), true, false, false))
            return false;
    }
    return true;
}

bool my_str_upper(char const *str)
{
    if (!str)
        return false;
    for (int a = 0; *(str + a); a++) {
        if (!my_char_is_alpha_num(*(str + a), false, false, true))
            return false;
    }
    return true;
}