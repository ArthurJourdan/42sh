/*
** EPITECH PROJECT, 2020
** PSU_42SH
** File description:
** add command from backtick.c
*/

#include "my.h"
#include "file.h"

#include "parsing_command_line.h"
#include "minishell.h"
#include "built_in.h"

static command_t *get_new_command(command_t *cmd, char *buff)
{
    if (cmd->prev) {
        if (cmd->prev->type == COMMAND || cmd->prev->type == BUILT_IN) {
            cmd = cmd->prev;
            free_one_command(cmd->next);
            cmd->instruction = my_strcat(cmd->instruction, buff, false, false);
            return cmd;
        }
    }
    cmd->type = COMMAND;
    cmd->instruction = my_strcpy(buff);
    return cmd;
}

static command_t *get_type_new(command_t *command, char *buff)
{
    enum types_e type_new = assign_type(command->prev, buff);

    if (type_new == MY_FILE) {
        command->type = type_new;
        command->instruction = my_strcpy(buff);
        return command;
    }
    if (type_new == COMMAND) {
        command = get_new_command(command, buff);
    }
    return command;
}

command_t *add_cmd_from_backtick(command_t *command, int fd)
{
    char *buff = get_entire_fd(fd);

    command = remove_cmd_backtick(command);
    command = get_type_new(command, buff);
    if (command->next) {
        command = command->next;
    }
    return command;
}
