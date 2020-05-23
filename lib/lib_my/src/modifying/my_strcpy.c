/*
** EPITECH PROJECT, 2020
** my_lib
** File description:
** my_stcpy.c
*/

#include "my.h"
#include "file.h"

char *my_strcpy(char *str)
{
    size_t len = my_strlen(str);
    char *cpy = NULL;

    if (!len)
        return NULL;
    cpy = malloc(sizeof(char) * (len + 1));
    if (!cpy)
        return NULL;
    for (size_t a = 0; a < len; a++)
        cpy[a] = str[a];
    cpy[len] = '\0';
    return cpy;
}

char *my_str_n_cpy(char *str, size_t size)
{
    size_t len = my_strlen(str);
    char *cpy = NULL;

    if (!len || !size)
        return NULL;
    cpy = malloc(sizeof(char) * (size + 1));
    if (!cpy)
        return NULL;
    for (size_t a = 0; a < size; a++) {
        cpy[a] = str[a];
    }
    cpy[size] = '\0';
    return cpy;
}

char *my_str_cpy_until_char(char *str, char c)
{
    size_t len = 0;
    char *cpy = NULL;

    while (str[len] && str[len++] != c);
    cpy = malloc(sizeof(char) * (len + 1));
    if (!len)
        return NULL;
    if (!cpy)
        return NULL;
    for (size_t a = 0; a < len; a++) {
        cpy[a] = str[a];
    }
    cpy[len] = '\0';
    return cpy;
}

char *my_str_cpy_until_str(char *str, char *cmp)
{
    size_t len = 0;
    char *cpy = NULL;

    if (!str || !cmp)
        return NULL;
    len = get_pos_word_in_str(cmp, str);
    if (len == -1 || !len) {
        return my_strcpy(str);
    }
    cpy = malloc(sizeof(char) * (len + 1));
    if (!cpy)
        return NULL;
    for (size_t a = 0; a < len; a++) {
        cpy[a] = str[a];
    }
    cpy[len] = '\0';
    return cpy;
}