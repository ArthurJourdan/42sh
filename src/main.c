/*
** EPITECH PROJECT, 2020
** my_lib
** File description:
** main.c
*/

#include "my.h"
#include "file.h"
#include "print.h"

#include "minishell.h"
#include "parsing_command_line.h"

int main(USELESS int ac, USELESS char **av, char **env)
{
    if (ac != 1)
        return EXIT_FAILURE;
    if (!minishell_manager(env))
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}