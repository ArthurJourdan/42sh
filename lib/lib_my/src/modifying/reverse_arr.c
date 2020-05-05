/*
** EPITECH PROJECT, 2020
** my_lib
** File description:
** reverse_arr.c
*/

#include "my.h"
#include "file.h"

static char **cpy_reversed(char **src, char **new, size_t len, size_t new_len)
{
    for (size_t a = 0; a < new_len; a++) {
        new[a] = malloc(sizeof(char) * (len + 1));
        if (!new[a])
            return NULL;
        new[a][len] = '\0';
    }
    for (size_t a = 0; a < len; a++) {
        for (size_t b = 0; b < new_len; b++) {
            new[new_len - 1 - b][a] = ' ';
            if (b < my_strlen(src[a]))
                new[new_len -1 - b][a] = src[a][b];
        }
    }
    return new;
}

char **reverse_double_arr(char **src, bool to_free)
{
    size_t len = my_arrlen(src);
    ssize_t biggest_src = 0;
    size_t new_len = 0;
    char **new = NULL;

    src = rm_char_in_double_arr(src, '\n');
    if (!src || !len)
        return NULL;
    if ((biggest_src = biggest_in_double_arr(src)) == -1)
        return NULL;
    new_len = my_strlen(src[biggest_src]);
    new = malloc(sizeof(char *) * (new_len + 1));
    if (!new)
        return NULL;
    new[new_len] = NULL;
    new = cpy_reversed(src, new, len, new_len);
    if (to_free)
        free_double_char_arr(src);
    return new;
}