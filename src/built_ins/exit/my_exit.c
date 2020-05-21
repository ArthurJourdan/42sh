/*
** EPITECH PROJECT, 2020
** PSU_minishell2
** File description:
** my_exit.c
*/

#include "my.h"
#include "print.h"

#include "minishell.h"

static void exit_error_msg(void)
{
    my_dprintf(STDERR_FILENO, "exit: Expression Syntax.\n");
}

bool my_exit(char **av, memory_t *env_m)
{
    size_t ac = my_arrlen(av);

    if (ac > 2) {
        exit_error_msg();
        return false;
    }
    if (ac == 2) {
        if (!my_str_is_num(av[1])) {
            exit_error_msg();
            return false;
        }
        signal(SIGINT, SIG_IGN);
        free_env_mem(env_m);
        exit(my_getnbr(av[1]));
    }
    signal(SIGINT, SIG_IGN);
    free_env_mem(env_m);
    exit(0);
}