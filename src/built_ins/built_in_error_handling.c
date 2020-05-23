/*
** EPITECH PROJECT, 2020
** PSU_42sh
** File description:
** built_in_error_handling.c
*/

#include "my.h"
#include "print.h"

static char * const TOO_FEW_ARGS = ": Too few arguments.\n";

bool built_in_error_handling(char **av)
{
    if (!av)
        return true;
    if (my_arrlen(av) <= 1) {
        my_dprintf(STDERR_FILENO, "%s%s", av[0], TOO_FEW_ARGS);
        return true;
    }
    return false;
}