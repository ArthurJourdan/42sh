/*
** EPITECH PROJECT, 2020
** my_lib
** File description:
** my_str_cpy_quotation.c
*/

#include "my.h"
#include "file.h"

static char first_quote(char *str, bool double_q, bool simple, bool magic)
{
    if (!str || my_strlen(str) <= 1)
        return '\0';
    for (size_t a = 0; str[a]; a++) {
        if (double_q && str[a] == '\"' && my_str_has_char(str + a + 1, '\"')) {
            return '\"';
        }
        if (simple && str[a] == '\'' && my_str_has_char(str + a + 1, '\'')) {
            return '\'';
        }
        if (magic && str[a] == '`' && my_str_has_char(str + a + 1, '`')) {
            return '`';
        }
    }
    return '\0';
}

static size_t get_len_quotation(char *str, char bound_quote)
{
    size_t len = 0;
    size_t beg_quotation = 0;

    if (!bound_quote)
        return 0;
    len = my_strlen(str);
    while (str[beg_quotation++] != bound_quote);
    for (size_t a = beg_quotation; a < len; a++) {
        if (str[a] == bound_quote && str[a - 1] != '\\') {
            len -= beg_quotation + (len - a);
            return len;
        }
    }
    return 0;
}

char *my_str_cpy_quotation(char *str, bool double_q, bool simple, bool magic)
{
    char bound_quote = first_quote(str, double_q, simple, magic);
    size_t len_quotation = get_len_quotation(str, bound_quote);
    size_t pos = 0;
    char *cpy = NULL;

    if (!bound_quote || !len_quotation)
        return NULL;
    cpy = malloc(sizeof(char) * (len_quotation + 1));
    if (!cpy)
        return NULL;
    while (str[pos++] != bound_quote);
    for (size_t a = 0; a < len_quotation; a++) {
        cpy[a] = str[pos + a];
    }
    cpy[len_quotation] = '\0';
    return cpy;
}
