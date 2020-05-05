/*
** EPITECH PROJECT, 2020
** my_lib_fifle
** File description:
** rm_char_in_str.c
*/

#include "my.h"
#include "print.h"

char *rm_trailling_char_in_str(char *str, const char ch)
{
    size_t new_len = my_strlen(str);
    char *new_str = NULL;
    size_t index = new_len - 1;

    if (!new_len)
        return NULL;
    for (size_t a = new_len - 1; str[a] && str[a] != '*' &&
    !my_char_is_alpha_num(str[a], true, true, true); a--) {
        if (str[a] == ch)
            new_len--;
    }
    new_str = malloc(sizeof(char) * (new_len + 1));
    for (size_t b = new_len - 1; b < new_len; b--) {
        while (index > b && str[index] == ch)
            index--;
        new_str[b] = str[index--];
    }
    new_str[new_len] = '\0';
    free(str);
    return new_str;
}

char **rm_trailling_char_in_double_arr(char **arr, const char ch)
{
    for (size_t a = 0; arr[a]; a++) {
        arr[a] = rm_trailling_char_in_str(arr[a], ch);
    }
    return arr;
}

char *rm_char_in_str(char *str, const char ch)
{
    size_t new_len = my_strlen(str);
    char *new_str = NULL;
    size_t index = 0;

    if (!new_len)
        return NULL;
    for (size_t a = 0; str[a]; a++) {
        if (str[a] == ch)

            new_len--;
    }
    new_str = malloc(sizeof(char) * (new_len + 1));
    for (size_t b = 0; str[b]; b++) {
        if (str[b] != ch)

            new_str[index++] = str[b];
    }
    new_str[new_len] = '\0';
    free(str);
    return new_str;
}

char **rm_char_in_double_arr(char **arr, const char ch)
{
    for (size_t a = 0; arr[a]; a++) {
        arr[a] = rm_char_in_str(arr[a], ch);
    }
    return arr;
}