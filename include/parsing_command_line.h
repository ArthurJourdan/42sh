/*
** EPITECH PROJECT, 2020
** PSU_minishell
** File description:
** parsing_command_line.h
*/

#ifndef PARSING_COMMAND_LINE_H
#define PARSING_COMMAND_LINE_H

#include "my.h"

enum types_e {
    COMMAND,
    MY_FILE,
    BUILT_IN,
    SEMICOLON,
    DOUBLE_E,
    DOUBLE_I,
    SIMPLE_I,
    S_REDIRECT,
    S_REDIRECT_IN,
    D_REDIRECT,
    D_REDIRECT_IN,
    W_REDIRECT_IN,
    BACKTIC,
    NONE_TY = (-1)
};

typedef struct command {
    enum types_e type;
    char *instruction;
    struct command *prev;
    struct command *next;
} command_t;

typedef struct separator {
    char *sep;
    enum types_e type;
    ssize_t pos;
} separator_t;

// READ COMMAND
void print_prompt(void);
char *command_read(void);
// !READ COMMAND

command_t *my_command_parser(char * const line);

// FILL COMMAND PART
command_t *fill_cmd_part(char * const line, separator_t next_sep,
command_t *prev_part);

enum types_e assign_type(command_t *prev_part, char * const instruction);
// !FILL COMMAND PART


// ERROR HANDLING
char *quote_error(char *line);

bool parsing_error(command_t *command);
bool parsing_error_msg(int error_nb);
bool is_separator(command_t *tmp);
bool pipe_with_file(command_t *tmp);
bool missing_file(command_t *tmp);

command_t *rm_useless_cmds(command_t *command);
// !ERROR HANDLING

// FREE
void free_command(command_t *command);
void free_one_command(command_t *command);
// !FREE

#endif /* !PARSING_COMMAND_LINE_H */
