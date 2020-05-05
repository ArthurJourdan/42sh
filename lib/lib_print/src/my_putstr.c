/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** first displayed string
*/

#include "my.h"
#include "print.h"

void my_putstr(int const output, char const *str)
{
    int len = my_strlen(str);

    if (!str)
        return;
    write(output, str, len);
}
