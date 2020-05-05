/*
** EPITECH PROJECT, 2019
** my putchar
** File description:
** to print char
*/

#include <unistd.h>

void my_putchar(int const output, int c)
{
    char nb = c;

    write(output, &nb, 1);
}
