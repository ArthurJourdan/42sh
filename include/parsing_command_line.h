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
    SIMPLE_E,
    SIMPLE_I,
    S_REDIRECT,
    S_REDIRECT_IN,
    D_REDIRECT,
    D_REDIRECT_IN,
    W_REDIRECT_IN,
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

void print_prompt(void);
char *command_read(void);

bool check_exit(char *line);
bool check_is_nothing(char *line);

command_t *my_command_parser(char * const line);

bool parsing_error(command_t *command);
bool parsing_error_msg(int error_nb);
bool is_separator(command_t *tmp);
bool pipe_with_file(command_t *tmp);
bool missing_file(command_t *tmp);

void free_command(command_t *command);

#endif /* !PARSING_COMMAND_LINE_H */
