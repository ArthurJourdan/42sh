/*
** EPITECH PROJECT, 2020
** lib
** File description:
** my_putdouble_array.c
*/

#include "my.h"
#include "print.h"

void my_putdouble_arr(int const output, char **arr)
{
    for (int a = 0; arr[a] != NULL; a++) {
        my_putstr(output, arr[a]);
    }
}

void my_putdouble_arr_newline(int const output, char **arr)
{
    for (int a = 0; arr[a] != NULL; a++) {
        my_putstr(output, arr[a]);
        if (arr[a + 1])
            my_putchar(output, '\n');
    }
}

void my_putdouble_arr_one_newline(int const output, char **arr)
{
    size_t last_frame = 0;

    for (int a = 0; arr[a] != NULL; a++) {
        my_putstr(output, arr[a]);
        last_frame = my_strlen(arr[a]) - 1;
        if (arr[a][last_frame] != '\n') {
            my_putchar(output, '\n');
        }
    }
}