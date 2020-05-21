/*
** EPITECH PROJECT, 2020
** PSU_42sh
** File description:
** disp_which.c
*/

#include "my.h"
#include "print.h"

#include "built_in.h"
#include "minishell.h"

bool disp_which(char **av, memory_t *env_m)
{
    char *command = NULL;

    for (size_t a = 1; av[a]; a++) {
        command = get_command_path(av + a, env_m);
        if (!command)
            continue;
        my_dprintf(1, "%s\n", command);
        free(command);
    }
    return true;
}