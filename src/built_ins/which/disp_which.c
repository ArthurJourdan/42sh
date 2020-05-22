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

static bool display_one_which(char **av, memory_t *env_mem)
{
    char *command = NULL;

    command = get_command_path(av, env_mem);
    if (!command) {
        return true;
        }
    my_dprintf(STDOUT_FILENO, "%s\n", command);
    free(command);
    return false;
}

bool disp_which(char **av, memory_t *env_mem)
{
    bool return_value = false;

    if (built_in_error_handling(av))
        return true;
    for (size_t a = 1; av[a]; a++) {
        if (display_one_which(av + a, env_mem)) {
            return_value = true;
        }
    }
    return return_value;
}