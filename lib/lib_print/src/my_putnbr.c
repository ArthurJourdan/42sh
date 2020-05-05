/*
** EPITECH PROJECT, 2019
** putnbr
** File description:
** display
*/

#include "my.h"
#include "print.h"

void disp_nbr(int const output, int nb, int rest)
{
    if (nb) {
        if ((rest = nb % 10) <= 9)
            rest += 48;
        disp_nbr(output, nb / 10, 0);
        write(output, &rest, 1);
    }
}

void my_putnbr(int const output, int nb)
{
    if (nb < 0) {
        my_putchar(output, '-');
        nb *= -1;
    } else if (nb == 0) {
        my_putchar(output, '0');
    }
    disp_nbr(output, nb, 1);
}
