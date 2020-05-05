/*
** EPITECH PROJECT, 2019
** my_putoctal
** File description:
** display unsigned ints in octal base
*/

#include "unistd.h"

void rec_putoctal(int const output, unsigned int nb, unsigned int rest)
{
    if (nb) {
        if ((rest = nb % 8) <= 9)
            rest += 48;
        rec_putoctal(output, nb / 8, 0);
        write(output, &rest, 1);
    }
}

void my_putoctal(int const output, unsigned int nb)
{
    rec_putoctal(output, nb, 1);
}
