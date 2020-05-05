/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** print every type of variables
*/

#include "my.h"
#include "print.h"

static const functions_t arr[13] = {
    {'c', &my_putchar},
    {'s', &my_putstr},
    {'i', &my_putnbr},
    {'u', &my_putnbr},
    {'x', &my_puthexa},
    {'X', &my_puthexa_c},
    {'o', &my_putoctal},
    {'b', &my_putbin},
    {'S', &put_non_p},
    {'d', &my_putnbr},
    {'a', &my_putdouble_arr},
    {'A', &my_putdouble_arr_newline},
    {'@', &my_putdouble_arr_one_newline}
};

static int print_str(int const output, char *str)
{
    int e = 0;

    while (str[e] != '%' && str[e] != '\0')
        e++;
    write(output, str, e);
    return e;
}

static void check_arr(int const output, char i, void *type)
{
    int e = 0;

    for (; e < ARRAY_SIZE(arr); e++)
        if (arr[e].c == i) {
            arr[e].ptr(output, type);
            break;
        }
    if (e == ARRAY_SIZE(arr)) {
        my_putchar(output, '%');
        my_putchar(output, i);
    }
}

void my_dprintf(int const output, char *str, ...)
{
    va_list ap;

    va_start(ap, str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '%') {
            i += print_str(output, str + i) - 1;
        }
        else if (str[i] == '%' && str[i + 1] != '%') {
            i++;
            check_arr(output, str[i], va_arg(ap, void *));
        } else {
            i++;
            my_putchar(output, '%');
        }
    }
    va_end(ap);
}
