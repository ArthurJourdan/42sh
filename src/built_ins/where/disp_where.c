/*
** EPITECH PROJECT, 2020
** PSU_42sj
** File description:
** disp_where.c
*/

#include "my.h"
#include "print.h"

#include "minishell.h"

static void disp_each_path(char **paths, char *cmd)
{
    char *command = NULL;

    for (size_t a = 0; paths[a]; a++) {
        command = command_match_one_path(paths[a], cmd);
        if (!command)
            continue;
        my_dprintf(STDOUT_FILENO, "%s\n", command);
    }
}

bool disp_where(char **av, memory_t *env_m)
{
    char **paths = path_to_path_arr(env_m);

    for (size_t a = 1; av[a]; a++) {
        disp_each_path(paths, av[a]);
    }
    return true;
}