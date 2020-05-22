/*
** EPITECH PROJECT, 2020
** PSU_42sh
** File description:
** built_in_error_handling.c
*/

#include "my.h"
#include "print.h"

bool built_in_error_handling(char **av)
{
    if (!av)
        return true;
    if (my_arrlen(av) <= 1) {
        my_dprintf(STDERR_FILENO, "%s: Too few arguments.\n", av[0]);
        return true;
    }
    return false;
}