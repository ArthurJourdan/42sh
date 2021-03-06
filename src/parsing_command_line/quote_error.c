/*
** EPITECH PROJECT, 2020
** quote_error.c
** File description:
** yolo
*/

#include "my.h"
#include "file.h"
#include "print.h"

#include "parsing_command_line.h"

int if_echo(char *line)
{
    if (get_pos_word_in_str("echo", line) != -1) {
            return 0;
    }
    return 1;
}

char *quote_error(char *line)
{
    int simple = command_access_quote(line, '\'');
    int doubles = command_access_quote(line, '\"');
    int magic = command_access_quote(line, '`');

    if (simple == 0 && doubles == 0 && magic == 0)
        return line;
    if (magic < 0) {
        my_putstr(1, "Unmatched \'`\'.\n");
        return NULL;
    }
    if (command_access_quote_error(line) == 1)
        return NULL;
    if (if_echo(line) == 0) {
        line = pars_line_supp_quotes_echo(line, doubles, simple);
        return line;
    }
    line = pars_line_supp_quotes(line);
    return line;
}