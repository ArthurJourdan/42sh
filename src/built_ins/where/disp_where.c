/*
** EPITECH PROJECT, 2020
** PSU_42sj
** File description:
** disp_where.c
*/

#include "my.h"
#include "print.h"

#include "built_in.h"
#include "minishell.h"

static char * const ERR_BUILTIN = " is a shell built-in\n";
static char * const ERR_ALIAS = " is aliased to ";

static bool is_where_built_in(char *command)
{
    if (is_built_in(command) != -1) {
        my_dprintf(STDERR_FILENO, "%s%s", command, ERR_BUILTIN);
        return true;
    }
    return false;
}

static bool is_where_alias(char *command, alias_t **aliases)
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
    char **paths = NULL;
    bool return_type = false;

    if (built_in_error_handling(av))
        return true;
    paths = path_to_path_arr(env_m);
    for (size_t a = 1; av[a]; a++) {
        if (is_where_alias(av[a], env_m->aliases))
            continue;
        is_where_built_in(av[a]);
        if (disp_each_path(paths, av[a]))
            return_type = true;
    }
    return return_type;
}