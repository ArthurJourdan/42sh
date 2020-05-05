/*
** EPITECH PROJECT, 2019
** register numbers
** File description:
** register numbers in strings of char
*/

#include <stdlib.h>

static int get_int_len(long number)
{
    int length = 1;

    if (number < 0)
        number *= -1;
    while (number > 9) {
        length++;
        number /= 10;
    }
    return length;
}

static char *if_neg(int nb,  int length)
{
    int modulo = 10;
    char *str = malloc(sizeof(char) * length + 2);

    str[0] = '-';
    nb *= - 1;
    for (int i = length ; i > 0; i--) {
        str[i] = (nb % modulo) / (modulo / 10) + 48;
        modulo = modulo * 10;
    }
    str[length + 1] = '\0';
    return str;
}

char *my_reg_nbr(int nb)
{
    int length = get_int_len(nb);
    char *str = malloc(sizeof(char) * length + 1);
    int modulo = 10;

    if (nb < 0)
        return (if_neg(nb, length));
    for (int i = length - 1; i >= 0; i--) {
        str[i] = (nb % modulo) / (modulo / 10) + 48;
        modulo = modulo * 10;
    }
    str[length] = '\0';
    return (str);
}
