/*
** EPITECH PROJECT, 2019
** zef,
** File description:
** zef
*/

#include "my.h"
#include "limits.h"

int recurs_nbr(char *str)
{
    int nb = 0;

    for (int a = 0; *(str + a) && (*(str + a) >= '0' &&
*(str + a) <= '9'); a++) {
        nb *= 10;
        nb += str[a] - 48;
    }
    return nb;
}

int my_getnbr(char *str)
{
    int nb = 0;

    if (!str)
        return 0;
    if (str[0] == '-') {
        nb = recurs_nbr(str + 1);
        nb *= -1;
    } else
        nb = recurs_nbr(str);
    return nb;
}
