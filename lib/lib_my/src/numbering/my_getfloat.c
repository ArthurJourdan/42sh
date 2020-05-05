/*
** EPITECH PROJECT, 2020
** my_lib
** File description:
** my_getfloat.c
*/

#include "my.h"

static float recurs_nbr(char *str)
{
    float nb = 0;

    for (size_t a = 0; *(str + a); a++) {
        if (*(str + a) != '.') {
            nb *= 10;
            nb += str[a] - 48;
        }
    }
    return nb;
}

static float put_coma(float nb, char *str)
{
    float divide = 1;

    for (size_t a = 0; *(str + a); a++) {
        divide *= 10;
        if (*(str + a) == '.' || *(str + a) == ',') {
            nb /= divide;
            return nb;
        }
    }
    return nb;
}

float my_getfloat(char *str)
{
    float nb = 0;

    if (!str)
        return 0;
    if (str[0] == '-') {
        nb = recurs_nbr(str + 1);
        nb *= -1;
    } else
        nb = recurs_nbr(str);
    nb = put_coma(nb, str);
    return nb;
}
