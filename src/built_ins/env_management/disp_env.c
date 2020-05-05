/*
** EPITECH PROJECT, 2020
** PSU_minishll1
** File description:
** disp_env.c
*/

#include "my.h"
#include "print.h"

#include "minishell.h"

bool disp_env(char **av, env_memory_t *env_m)
{
    if (my_arrlen(av) > 1)
        my_dprintf(2, "env: \'%s\': No such file or directory", av[1]);
    if (env_m->env) {
        my_dprintf(STDOUT_FILENO, "%A\n", env_m->env);
        exit(0);
        return true;
    }
    exit(0);
    return false;
}