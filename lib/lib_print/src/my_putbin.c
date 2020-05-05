/*
** EPITECH PROJECT, 2019
** convert and display
** File description:
** convert an int in hexa and display it
*/

#include <unistd.h>
#include "my.h"
#include "print.h"

static void rec_putbin(int const  output, unsigned int nb, unsigned int rest)
{
    if (nb) {
        if ((rest = nb % 2) <= 9)
            rest += 48;
        rec_putbin(output, nb / 2, 0);
        my_putchar(output, rest);
    }
}

void my_putbin(int const output, unsigned int nb)
{
    rec_putbin(output, nb, 0);
}
