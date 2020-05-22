/*
** EPITECH PROJECT, 2020
** PSU_42sh
** File description:
** error_handling_history.c
*/

#include "my.h"
#include "print.h"

#include "built_in.h"

static const char *ERR_NB = ": Badly formed number.\n";
static const char *ERR_AC = ": Too many arguments.\n";
static const char *HELP = "--help";
static const char *OFF_COUNT = "-h";

static void display_help_history(void)
{
    char *help = "Usage: hisory [-chrSLMT] [# number of events].\n";

    my_dprintf(STDERR_FILENO, "%s", help);
}

static bool hist_exists(char **av, memory_t *env_mem)
{
    if (!env_mem->history)
        return true;
    if (!av)
        return true;
    return false;
}

static bool hist_args(char **av)
{
    size_t ac = my_arrlen(av);

    if (my_strcmp(OFF_COUNT, av[1]))
        return false;
    if (ac == 2) {
        if (!my_str_is_num(av[1])) {
            my_dprintf(STDERR_FILENO, "%s%s", av[0], ERR_NB);
            return true;
        } else if (atoi(av[1]) < 0) {
            display_help_history();
            return true;
        }
    }
    if (ac > 3) {
        my_dprintf(STDERR_FILENO, "%s%s", av[0], ERR_AC);
        return true;
    }
    if (my_strcmp(HELP, av[1]))
        display_help_history();
    return false;
}

bool error_handling_history(char **av, memory_t *env_mem)
{
    if (hist_exists(av, env_mem))
        return true;
    if (hist_args(av))
        return true;
    return false;
}
