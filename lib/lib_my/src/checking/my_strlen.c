/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** strlenhuponireticagu
*/

#include "my.h"

size_t my_strlen(char const *str)
{
    size_t i = 0;

    if (str)
        while (*(str + i)) {
            i++;
        }
    return (i);
}

size_t my_arrlen(char **arr)
{
    size_t i = 0;

    if (arr)
        while (*(arr + i)) {
            i++;
        }
    return (i);
}

size_t my_triplearrlen(char **arr[])
{
    size_t i = 0;

    if (arr)
        while (*(arr + i)) {
            i++;
        }
    return (i);
}

size_t my_len_tot(char const *str)
{
    static size_t len = 0;

    if (str)
        len += my_strlen(str);
    return len;
}

size_t my_strlen_until_word(char * const str, char * const word)
{
    size_t len = 0;
    size_t len_word = my_strlen(word);

    if (!str || !word || !len_word)
        return 0;
    while (str[len] && !my_str_n_cmp(str + len, word, len_word)) {
        len++;
    }
    return len;

}