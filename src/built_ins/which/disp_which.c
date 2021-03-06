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

static const char *ALL = "-a";
static char * const ERR_BUILTIN = ": shell built-in command.\n";
static char * const ERR_ALIAS = ":\taliased to ";
static char * const NOT_EXIST = ": Command not found.\n";

static bool is_which_built_in(char *command)
{
    if (is_built_in(command) != -1) {
        my_dprintf(STDERR_FILENO, "%s%s", command, ERR_BUILTIN);
        return true;
    }
    return false;
}

static bool is_which_alias(char *command, alias_t **aliases)
{
    if (!aliases)
        return false;
    for (size_t a = 0; aliases[a]; a++) {
        if (my_strcmp(aliases[a]->alias, command)) {
            my_dprintf(STDOUT_FILENO, "%s%s", aliases[a]->alias, ERR_ALIAS);
            my_dprintf(STDOUT_FILENO, "%s\n", aliases[a]->substitute);
            return true;
        }
    }
    return false;
}

static bool display_one_which(char **av, memory_t *env_mem)
{
    char *command = NULL;

    command = get_command_path(av, env_mem);
    if (!command) {
        my_dprintf(STDERR_FILENO, "%s%s", av[0], NOT_EXIST);
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
    if (my_strcmp(av[1], ALL)) {
        return disp_where(av, env_mem);
    }
    for (size_t a = 1; av[a]; a++) {
        if (is_which_alias(av[a], env_mem->aliases)) {
            continue;
        }
        if (is_which_built_in(av[a])) {
            continue;
        }
        if (display_one_which(av + a, env_mem)) {
            return_value = true;
        }
    }
    return return_value;
}