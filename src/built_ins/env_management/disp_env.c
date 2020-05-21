/*
** EPITECH PROJECT, 2020
** PSU_minishll1
** File description:
** disp_env.c
*/

#include "my.h"
#include "print.h"

#include "built_in.h"

bool disp_env(char **av, memory_t *env_m)
{
    if (my_arrlen(av) > 1) {
        my_dprintf(2, "env: \'%s\': No such file or directory", av[1]);
        return true;
    }
    if (env_m->env) {
        my_dprintf(STDOUT_FILENO, "%A\n", env_m->env);
        return true;
    }
    return false;
}
