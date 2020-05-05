/*
** EPITECH PROJECT, 2020
** my_lib
** File description:
** my_getdigit.c
*/

int my_getdigit(char nb)
{
    float result = 0;

    if (nb < 48)
        return -1;
    result = nb - 48;
    return result;
}
