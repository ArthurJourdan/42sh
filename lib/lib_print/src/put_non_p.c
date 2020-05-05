/*
** EPITECH PROJECT, 2019
** for my_printf
** File description:
** S like put str
*/

#include "my.h"
#include "print.h"

void put_non_p(int const output, char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] <= 127 && str[i] > 32 || str[i] == '\0')
            write(output, &str[i], 1);
        if (str[i] >= 127) {
            my_putchar(output, '\\');
            my_putoctal(output, str[i]);
        }
        if (str[i] <= 32) {
            my_putchar(output, '\\');
            my_putchar(output, '0');
            my_putoctal(output, str[i]);
        }
        else if (str[i] <= 7) {
            my_putchar(output, '\\');
            my_putchar(output, '0');
            my_putchar(output, '0');
            my_putoctal(output, str[i]);
        }
    }
}
