/*
** EPITECH PROJECT, 2020
** my_lib
** File description:
** my_int_arr_len.c
*/

#include "my.h"

size_t my_int_arr_len(int *arr)
{
    size_t len = 0;

    if (!arr)
        return 0;
    while (arr[len++]);
    return len;
}
