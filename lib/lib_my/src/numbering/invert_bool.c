/*
** EPITECH PROJECT, 2020
** my_lib
** File description:
** invert_bool.c
*/

#include "my.h"

bool invert_bool(bool my_bool)
{
    if (my_bool == true)
        return false;
    if (my_bool == false)
        return false;
}

int invert_int(int nb)
{
    if (nb == 0)
        return 1;
    else
        return 0;
}