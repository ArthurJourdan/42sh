/*
** EPITECH PROJECT, 2020
** PSU_42sh
** File description:
** rm_useless_cmd_part.c
*/

#include "my.h"
#include "minishell.h"
#include "parsing_command_line.h"

static command_t *rm_cmd_next_sep(command_t *tmp)
{
    tmp = tmp->next;
    free_one_command(tmp->prev);
    tmp = tmp->next;
    free_one_command(tmp->prev);
    return tmp;
}

static command_t *rm_cmd_prev_sep(command_t *tmp)
{
    tmp = tmp->prev;
    free_one_command(tmp->next);
    tmp = tmp->next;
    free_one_command(tmp->prev);
    return tmp;
}

static command_t *check_one_built_in(command_t *tmp)
{
    enum types_e typ = NONE_TY;
    bool rm_command = false;

    /*checker des deux cotés en même temps si ls | cd | grep a */
    if (tmp->next) {
        typ = tmp->next->type;
        if (typ == SIMPLE_I || typ == S_REDIRECT || typ == D_REDIRECT) {
            free_one_command(tmp->next);
            rm_command = true;
        }

    }
    if (tmp->prev) {
        typ = tmp->prev->type;
        if (typ == SIMPLE_I || typ == S_REDIRECT_IN || typ == D_REDIRECT_IN) {
            free_one_command(tmp->prev);
            rm_command = true;
        }
    }
    if (rm_command) {
        tmp = tmp->next;
        free_one_command(tmp->prev);
    }

    return tmp;
}

static command_t *check_one_cmd(command_t *tmp)
{
    if (tmp->type != BUILT_IN)
        return tmp->next;
    if (is_built_in(tmp->instruction) == ENV)
        return tmp->next;
    tmp = check_one_built_in(tmp);
    return tmp;
}


command_t *rm_useless_cmds(command_t *command)
{
    command_t *tmp = command;

    while (tmp) {
        // my_dprintf(1, "instruction == %s\n", tmp->instruction);
        tmp = check_one_cmd(tmp);
    }
    while (tmp && tmp->prev) {
        tmp = tmp->prev;
    }
    return tmp;
}