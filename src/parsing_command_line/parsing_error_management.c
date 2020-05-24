/*
** EPITECH PROJECT, 2020
** PSU_42sh
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

static bool separator_error(command_t *tmp)
{
    if (is_separator(tmp)) {
        if (is_separator_beg_end(tmp) && is_separator_beg_end(tmp->next))
            return false;
        if (is_separator(tmp) && is_separator_beg_end(tmp->next)) {
            if (tmp->type != BACKTICK) {
                return false;
            }
        }
        if (is_separator_beg_end(tmp) && is_separator(tmp->next)) {
            if (tmp->next->type != BACKTICK) {
                return false;
            }
        }
    }
    if (is_separator(tmp) && my_str_is_nothing(tmp->next->instruction)) {
        return false;
    }
    return true;
}

static bool backtick_nb_error(command_t *command)
{
    command_t *tmp = command;
    size_t nb_backtick = 0;

    while (tmp) {
        if (tmp->type == BACKTICK)
            nb_backtick++;
        tmp = tmp->next;
    }
    if (nb_backtick % 2 == 1) {
        my_dprintf(STDERR_FILENO, "Unmatched '`'.\n");
        return true;
    }
    return false;
}

bool parsing_error(command_t *command)
{
    command_t *tmp = command;

    if (is_separator_beg_end(tmp))
        return parsing_error_msg(0);
    if (backtick_nb_error(command))
        return true;
    while (tmp->next) {
        if (!missing_file(tmp))
            return parsing_error_msg(2);
        if (!ambiguous_redirect(tmp))
            return true;
        if (!separator_error(tmp))
            return parsing_error_msg(0);
        if (!pipe_with_file(tmp)) {
            return parsing_error_msg(1);
        }
        tmp = tmp->next;
    }
    if (is_separator_beg_end(tmp))
        return parsing_error_msg(0);
    return false;
}
