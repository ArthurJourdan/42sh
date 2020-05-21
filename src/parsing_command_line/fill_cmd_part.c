/*
** EPITECH PROJECT, 2020
** PSU_42sh
** File description:
** fill_cmd_part.c
*/

#include "my.h"
#include "parsing_command_line.h"

static command_t *init_node(command_t *prev_part)
{
    command_t *next_part = malloc(sizeof(command_t));

    if (!next_part)
        return NULL;
    next_part->type = NONE_TY;
    next_part->instruction = NULL;
    next_part->next = NULL;
    next_part->prev = prev_part;
    return next_part;
}

static void fill_no_next_sep(command_t *next_part,
char * const line, command_t *prev_part)
{
    next_part->instruction = my_strcpy(line);
    next_part->type = assign_type(prev_part, next_part->instruction);
}

static void fill_sep(command_t *next_part, separator_t next_sep)
{
    next_part->instruction = my_strcpy(next_sep.sep);
    next_part->type = next_sep.type;

}

static void fill_if_sep(command_t *next_part, char *str_until_sep,
command_t *prev_part)
{
    next_part->instruction = my_strcpy(str_until_sep);
    next_part->type = assign_type(prev_part, next_part->instruction);
}

command_t *fill_cmd_part(char * const line, separator_t next_sep,
command_t *prev_part)
{
    char *str_until_sep = NULL;
    command_t *next_part = init_node(prev_part);

    if (!next_part)
        return NULL;
    if (next_sep.pos == (-1)) {
        fill_no_next_sep(next_part, line, prev_part);
        return next_part;
    }
    str_until_sep = my_str_cpy_until_str(line, next_sep.sep);
    if (next_sep.pos == 0) {
        fill_sep(next_part, next_sep);
    } else {
        fill_if_sep(next_part, str_until_sep, prev_part);
    }
    free_char_to_null(str_until_sep);
    return next_part;
}