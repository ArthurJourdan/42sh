/*
** EPITECH PROJECT, 2019
** convert and display
** File description:
** convert an int in hexa and display it
*/

#include <unistd.h>

void rec_puthexa(int const output, unsigned int nb, unsigned int rest)
{
    if (nb) {
        if ((rest = nb % 16) <= 9)
            rest += 48;
        else
            rest += 87;
        rec_puthexa(output, nb / 16, 0);
        write(output, &rest, 1);
    }
}

void my_puthexa(int const output, unsigned int nb)
{
    rec_puthexa(output, nb, 0);
}
