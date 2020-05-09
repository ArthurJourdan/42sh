/*
** EPITECH PROJECT, 2020
** PSU_42sh
** File description:
** assign_types.c
*/

#include "parsing_command_line.h"
#include "minishell.h"

enum types_e assign_type(command_t *prev_part, char * const instruction)
{
    enum types_e type = COMMAND;

    if (prev_part) {
        if (prev_part->type == S_REDIRECT_IN)
            type = MY_FILE;
        if (prev_part->type == D_REDIRECT_IN)
            type = MY_FILE;
        if (prev_part->type == S_REDIRECT)
            type = MY_FILE;
        if (prev_part->type == D_REDIRECT)
            type = MY_FILE;
    }
    if (is_built_in(instruction) != -1)
        type = BUILT_IN;
    return type;
}
