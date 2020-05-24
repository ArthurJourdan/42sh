/*
** EPITECH PROJECT, 2020
** PSU_42sh
** File description:
** concatenate_neighboor.c
*/

#include "my.h"
#include "file.h"

#include "parsing_command_line.h"
#include "minishell.h"
#include "built_in.h"

static command_t *cat_all(command_t *cmd, char *buff, bool *changed)
{
    char *tmp = NULL;

    cmd = cmd->prev;
    free_one_command(cmd->next);
    tmp = my_strcat(cmd->instruction, buff, false, false);
    tmp = my_strcat(tmp, cmd->next->instruction, false, false);
    free_char_to_null(cmd->instruction);
    cmd->instruction = tmp;
    free_one_command(cmd->next);
    *(changed) = true;
    return cmd;
}

static command_t *cat_prev(command_t *cmd, char *buff, bool *changed)
{
    if (cmd->prev) {
        if (cmd->prev->type == COMMAND || cmd->prev->type == BUILT_IN) {
            cmd = cmd->prev;
            free_one_command(cmd->next);
            cmd->instruction = my_strcat(cmd->instruction, buff, false, false);
            *(changed) = true;
        }
    }
    return cmd;
}

static command_t *cat_next(command_t *cmd, char *buff, bool *changed)
{
    if (cmd->next) {
        if (cmd->next->type == COMMAND || cmd->next->type == BUILT_IN) {
            cmd = cmd->next;
            free_one_command(cmd->prev);
            cmd->instruction = my_strcat(cmd->instruction, buff, false, false);
            *(changed) = true;
        }
    }
    return cmd;
}

static command_t *check_cat(command_t *cmd, char *buff, bool *changed)
{
    if (cmd->prev && cmd->next) {
        if (cmd->prev->type == COMMAND && cmd->next->type == COMMAND) {
            cmd = cat_all(cmd, buff, changed);
            return cmd;
        }
    }
    cat_prev(cmd, buff, changed);
    if (*(changed))
        return cmd;
    cat_next(cmd, buff, changed);
    return cmd;
}

command_t *concatenate_neighboor(command_t *cmd, char *buff, bool *changed)
{
    if (!cmd || (!cmd->prev && !cmd->next))
        return cmd;
    cmd = check_cat(cmd, buff, changed);
    return cmd;
}