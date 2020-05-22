/*
** EPITECH PROJECT, 2020
** 42SH
** File description:
** add command from backtick
*/

#include "my.h"

#include "parsing_command_line.h"
#include "minishell.h"
#include "built_in.h"

command_t *add_cmd_from_backtic(command_t *command, int fd)
{
    command = remove_cmd_backtick(command);
    if (command->prev && command->prev->type != COMMAND)
}
