/*
** EPITECH PROJECT, 2020
** lib/my
** File description:
** my_strcat.c
*/

#include "my.h"
#include "print.h"

char *my_strcat(char const *str1, char const *str2)
{
    size_t len1 = my_strlen(str1);
    size_t len2 = my_strlen(str2);
    size_t len3 = len1 + len2;
    char *str3 = NULL;

    if (!len3)
        return NULL;
    str3 = malloc(sizeof(char) * (len3 + 2));
    if (!str3)
        return NULL;
    for (size_t a = 0; a < len1; a++)
        *(str3 + a) = *(str1 + a);
    for (size_t b = 0; b < len2; b++)
        *(str3 + b + len1) = *(str2 + b);
    *(str3 + (len1 + len2)) = '\0';
    return str3;
}

char *my_strcat_free(char *str1, char *str2)
{
    size_t len1 = my_strlen(str1);
    size_t len2 = my_strlen(str2);
    size_t len3 = len1 + len2;
    char *str3 = NULL;

    if (!len3)
        return NULL;
    str3 = malloc(sizeof(char) * (len3 + 2));
    if (!str3)
        return NULL;
    for (size_t a = 0; a < len1; a++)
        *(str3 + a) = *(str1 + a);
    for (size_t b = 0; b < len2; b++)
        *(str3 + b + len1) = *(str2 + b);
    *(str3 + (len1 + len2)) = '\0';
    free(str1);
    free(str2);
    return str3;
}
