/*
** EPITECH PROJECT, 2020
** PSU_42sh
** File description:
** launch_command_parser.c
*/

#include "my.h"

#include "minishell.h"
#include "parsing_command_line.h"
#include "built_in.h"

void launch_command_parser(char *line, memory_t *env_mem)
{
    command_t *command = my_command_parser(line);

    if (!command)
        return;
    // substitute_backtics(command, env_mem);
    command_exec(command, env_mem);
}