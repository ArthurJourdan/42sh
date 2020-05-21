/*
** EPITECH PROJECT, 2020
** PSU_42sh
** File description:
** my_echo.c
*/

#include "my.h"
#include "print.h"

#include "minishell.h"

bool disp_echo(char **av, N_U memory_t *env_m)
{
    size_t ac = my_arrlen(av);

    if (ac) {
        for (size_t a = 1; a < ac; a++) {
            my_dprintf(STDOUT_FILENO, "%s", av[a]);
            if (a != ac - 1)
                my_dprintf(STDOUT_FILENO, " ");
        }
    }
    my_dprintf(STDOUT_FILENO, "\n");
    return false;
}
