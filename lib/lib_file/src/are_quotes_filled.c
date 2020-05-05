/*
** EPITECH PROJECT, 2020
** my_lib_file
** File description:
** are_quotes_filled.c
*/

#include "my.h"
#include "print.h"

static short check_quotes(char const * const line)
{
    size_t check_double = 0;
    size_t check_simple = 0;
    size_t check_magic = 0;

    for (int c = 0; line[c]; c++) {
        if (line[c] == '\"')
            check_double++;
        if (line[c] == '\'')
            check_simple++;
        if (line[c] == '`')
            check_magic++;
    }
    if (check_double % 2 == 1)
        return 1;
    if (check_simple % 2 == 1)
        return 2;
    if (check_magic % 2 == 1)
        return 3;
    return 0;
}

bool are_quotes_filled(char const * const line)
{
    short return_check = 0;

    if (!line)
        return false;
    return_check = check_quotes(line);
    if (return_check == 1) {
        my_dprintf(1, "%sdouble quote%s> ", LIGHT_RED, DEFAULT);
        return false;
    }
    if (return_check == 2) {
        my_dprintf(1, "%ssimple quote%s> ", LIGHT_RED, DEFAULT);
        return false;
    }
    if (return_check == 3) {
        my_dprintf(1, "%smagic quote%s> ", LIGHT_RED, DEFAULT);
        return false;
    }
    return true;
}