/*
** EPITECH PROJECT, 2020
** 42SH
** File description:
** Get/remove command between backticks
*/

#include "my.h"

#include "parsing_command_line.h"

command_t *get_cmd_backtick(command_t *command)
{
    command_t *tmp = command;

    tmp = tmp->next;
    if (!tmp)
        return tmp;
    while (tmp->prev)
        free_one_command(tmp->prev);
    while (tmp->next && tmp->next->type != BACKTIC)
        tmp = tmp->next;
    while (tmp->next)
        free_one_command(tmp->next);
    while (tmp)
        tmp = tmp->prev;
    return tmp;
}

command_t *remove_cmd_backtick(command_t *command)
{
    command_t *tmp = command;

    while (tmp->next) {
        free_one_command(tmp->next);
        if (tmp->next->type == BACKTIC){
            free_one_command(tmp->next);
            break;
        }
    }
    return tmp;
}
