/*
** EPITECH PROJECT, 2020
** my_lib
** File description:
** compare_str.c
*/

#include "my.h"

ssize_t biggest_in_double_arr(char **src)
{
    size_t len = 0;
    size_t biggest_len = 0;
    ssize_t index = 0;
    ssize_t index_biggest = -1;

    if (!src)
        return -1;
    for (; src[index]; index++) {
        len = my_strlen(src[index]);
        if (len > biggest_len) {
            biggest_len = len;
            index_biggest = index;
        }
    }
    return index_biggest;
}