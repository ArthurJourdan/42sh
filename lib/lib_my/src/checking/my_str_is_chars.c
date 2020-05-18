/*
** EPITECH PROJECT, 2020
** my_lib
** File description:
** my_str_is_chars.c
*/

#include "my.h"

static size_t my_char_is_the_one(const char c, const char cmp)
{
    if (c == cmp) {
        return 1;
    }
    return 0;
}

bool my_str_is_chars(char * const str, size_t ac, ...)
{
    va_list ap;
    size_t corresp = 0;

    if (!str || !ac)
        return false;
    for (int a = 0; str[a]; a++) {
        corresp = 0;
        va_start(ap, ac);
        for (size_t nb_char = 0; nb_char < ac; nb_char++) {
            corresp += my_char_is_the_one(str[a], va_arg(ap, int));
        }
        va_end(ap);
        if (!corresp)
            return false;
    }
    return true;
}

bool my_str_has_char(char * const str, char c)
{
    for (size_t a = 0; str[a]; a++) {
        if (str[a] == c) {
            return true;
        }
    }
    return false;
}

bool my_str_has_chars(char * const str, size_t ac, ...)
{
    va_list ap;
    size_t corresp = 0;

    if (!str || !ac)
        return false;
    va_start(ap, ac);
    for (size_t nb_char = 0; nb_char < ac; nb_char++) {
        if (!my_str_has_char(str, va_arg(ap, int)))
            return false;
    }
    va_end(ap);
    return true;
}