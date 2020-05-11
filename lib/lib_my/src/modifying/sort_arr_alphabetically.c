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

static bool arr_is_sorted(char **arr)
{
    for (size_t a = 1; arr[a]; a++) {
        if (!cmp_ascii_order(arr[a - 1], arr[a]))
            return false;
    }
    return true;
}

static void bubble_sort(char **arr)
{
    size_t index = 0;
    char *tmp = NULL;

    while (arr[++index]) {
        if (!cmp_ascii_order(arr[index - 1], arr[index])) {
            tmp = arr[index - 1];
            arr[index - 1] = arr[index];
            arr[index] = tmp;
        }
    }
}

void sort_arr_alphabetically(char **arr)
{
    if (!arr || !arr[0] || !arr[1])
        return;
    while (!arr_is_sorted(arr)) {
        bubble_sort(arr);
    }
}