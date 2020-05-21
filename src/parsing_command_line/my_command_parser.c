/*
** EPITECH PROJECT, 2020
** PSU_mishell2
** File description:
** my_command_parser.c
*/

#include "my.h"
#include "file.h"
#include "print.h"

#include "minishell.h"
#include "parsing_command_line.h"

static separator_t separators[] = {
    {">>", D_REDIRECT, 0},
    {"<<", D_REDIRECT_IN, 0},
    {">", S_REDIRECT, 0},
    {"<", S_REDIRECT_IN, 0},
    {";", SEMICOLON, 0},
    {"||", DOUBLE_I ,0},
    {"|", SIMPLE_I ,0},
    {"&&", DOUBLE_E ,0}
};

static separator_t get_pos_separator(char * const line)
{
    ssize_t pos = -1;
    separator_t infos = {NULL, -1, -1};

    for (size_t a = 0; a < ARRAY_SIZE(separators); a++) {
        pos = get_pos_word_in_str(separators[a].sep, line);
        if (pos != -1 && (pos < infos.pos || infos.pos == (-1))) {
            infos.pos = pos;
            infos.type = separators[a].type;
            if (infos.sep)
                infos.sep = free_char_to_null(infos.sep);
            infos.sep = my_strcpy(separators[a].sep);
        }
    }
    return infos;
}

static command_t *get_command_line(char * const line)
{
    command_t *command_part = NULL;
    separator_t next_sep = get_pos_separator(line);

    command_part = fill_cmd_part(line, next_sep, NULL);
    for (ssize_t a = 0; a == -1 || line[a]; ) {
        my_dprintf(1, "pos == %i\n", next_sep.pos);
        if (next_sep.pos == 0)
            a += my_strlen(next_sep.sep);
        a += next_sep.pos;
        if (next_sep.pos == -1)
            break;
        next_sep = get_pos_separator(line + a);
        command_part->next = fill_cmd_part(line + a, next_sep, command_part);
        command_part = command_part->next;
    }
    if (my_str_is_nothing(command_part->instruction)) {
        command_part = command_part->prev;
        free(command_part->next);
        command_part->next = NULL;
    }
    return command_part;
}

command_t *my_command_parser(char * const line)
{
    command_t *parsed_command = NULL;

    if (my_str_is_nothing(line))
        return NULL;
    parsed_command = get_command_line(line);
    while (parsed_command->prev) {
        parsed_command = parsed_command->prev;
    }
    if (parsing_error(parsed_command)) {
        free_command(parsed_command);
        return NULL;
    }
    return parsed_command;
}