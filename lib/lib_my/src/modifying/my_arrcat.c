/*
** EPITECH PROJECT, 2020
** my_lib
** File description:
** my_arrcat.c
*/

#include "my.h"

char **my_two_str_to_arr(char *str1, char *str2, bool do_free)
{
    char **arr = malloc(sizeof(char *) * 3);

    if (!arr)
        return NULL;
    arr[0] = my_strcpy(str1);
    arr[1] = my_strcpy(str2);
    arr[2] = NULL;
    if (free) {
        free(str1);
        free(str2);
    }
    return arr;
}

char **my_arrcat(char **arr1, char **arr2, bool free)
{
    size_t len1 = my_arrlen(arr1);
    size_t len2 = my_arrlen(arr2);
    size_t len3 = len1 + len2;
    char **arr3 = malloc(sizeof(char *) * (len3 + 1));

    if (!arr3)
        return NULL;
        for (size_t a = 0; a < len3; a++) {
        if (a < len1) {
            arr3[a] = my_strcpy(arr1[a]);
        } else {
            arr3[a] = my_strcpy(arr2[a - len1]);
        }
    }
    arr3[len3] = NULL;
    if (free) {
        free_double_char_arr(arr1);
        free_double_char_arr(arr2);
    }
    return arr3;
}

char ***my_triple_arrcat(char ***arr1, char ***arr2)
{
    size_t len1 = my_triplearrlen(arr1);
    size_t len2 = my_triplearrlen(arr2);
    size_t len3 = len1 + len2;
    char ***arr3 = malloc(sizeof(char **) * (len3 + 1));

    if (!arr3)
        return NULL;
    for (size_t a = 0; a < len3; a++) {
        if (a < len1) {
            arr3[a] = double_char_arr_cpy(arr1[a], false);
        } else {
            arr3[a] = double_char_arr_cpy(arr2[a - len1], false);
        }
    }
    arr3[len3] = NULL;
    return arr3;
}
