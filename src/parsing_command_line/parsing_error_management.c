/*
** EPITECH PROJECT, 2020
** PSU_minishell2
** File description:
** parsing_error_management.c
*/

#include "my.h"
#include "print.h"

#include "minishell.h"
#include "parsing_command_line.h"

bool parsing_error_msg(int error_nb)
{
    if (error_nb == 0)
        my_dprintf(STDERR_FILENO, "Invalid null command.\n");
    if (error_nb == 1)
        my_dprintf(STDERR_FILENO, "Ambiguous output redirect.\n");
    if (error_nb == 2)
        my_dprintf(STDERR_FILENO, "Missing name for redirect.\n");
    return true;
}

bool parsing_error(command_t *command)
{
    command_t *tmp = command;


    if (is_separator(tmp))
        return parsing_error_msg(0);
    while (tmp->next) {
    my_dprintf(1, " == %i\n", tmp->type);
        if (!missing_file(tmp))
            return parsing_error_msg(2);
        if (is_separator(tmp) && is_separator(tmp->next)) {
            return parsing_error_msg(0);
        if (is_separator(tmp) && my_str_is_nothing(tmp->next->instruction))
            return parsing_error_msg(0);
        }
        if (!pipe_with_file(tmp)) {
            return parsing_error_msg(1);
        }
        tmp = tmp->next;
    }
    if (is_separator(tmp))
        return parsing_error_msg(0);
    return false;
}