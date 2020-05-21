/*
** EPITECH PROJECT, 2020
** PSU_42sj
** File description:
** disp_where.c
*/

#include "my.h"
#include "print.h"

#include "minishell.h"

static bool disp_each_path(char **paths, char *cmd)
{
    char *command = NULL;
    size_t not_displayed = 0;

    for (size_t a = 0; paths[a]; a++) {
        command = command_match_one_path(paths[a], cmd);
        if (!command) {
            not_displayed++;
            continue;
        }
        my_dprintf(STDOUT_FILENO, "%s\n", command);
    }
    if (not_displayed == my_arrlen(paths)) {
        return true;
    }
    return false;
}

bool disp_where(char **av, memory_t *env_m)
{
    char **paths = path_to_path_arr(env_m);
    bool return_type = false;

    for (size_t a = 1; av[a]; a++) {
        if (disp_each_path(paths, av[a]))
            return_type = true;
    }
    return return_type;
}