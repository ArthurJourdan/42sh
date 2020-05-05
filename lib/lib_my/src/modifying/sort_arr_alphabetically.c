/*
** EPITECH PROJECT, 2020
** my_lib
** File description:
** sort_alphabetically.c
*/

#include "my.h"

static bool cmp_ascii_order(char *name1, char *name2)
{
    size_t len1 = 0;
    size_t len2 = 0;

    for (size_t a = 0; name1[a] && name2[a]; a++) {
        if (name1[a] < name2[a])
            return true;
        else if (name1[a] > name2[a])
            return false;
    }
    len1 = my_strlen(name1);
    len2 = my_strlen(name2);
    if (len1 < len2)
        return true;
    return false;
}

static bool arr_is_sorted(char **tetriminos)
{
    for (size_t a = 1; tetriminos[a]; a++) {
        if (!cmp_ascii_order(tetriminos[a - 1], tetriminos[a]))
            return false;
    }
    return true;
}

static void bubble_sort(char **tetriminos)
{
    size_t index = 0;
    char *tmp = NULL;

    while (tetriminos[++index]) {
        if (!cmp_ascii_order(tetriminos[index - 1], tetriminos[index])) {
            tmp = tetriminos[index - 1];
            tetriminos[index - 1] = tetriminos[index];
            tetriminos[index] = tmp;
        }
    }
}

void sort_arr_alphabetically(char **tetriminos)
{
    if (!tetriminos || !tetriminos[0] || !tetriminos[1])
        return;
    while (!arr_is_sorted(tetriminos)) {
        bubble_sort(tetriminos);
    }
}