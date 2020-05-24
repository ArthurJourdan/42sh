/*
** EPITECH PROJECT, 2020
** pars_line_supp_quote.c
** File description:
** yolo
*/

#include "my.h"
#include "print.h"

#include "parsing_command_line.h"

int pars_error_line_quotes(char *line, int doubles, int simple)
{
    int i;

    for (i = 0; line[i] != '"' && line[i] != '\''; i++);
    if (line[i] == '"' && doubles < 0) {
        my_putstr(1, "Unmatched \'\"\'.\n");
        return -1;
    }
    if (line[i] == '\'' && simple < 0) {
        my_putstr(1, "Unmatched \'\'\'.\n");
        return -1;
    }
    return i;
}

char *pars_line_supp_quotes_echo(char *line, int doubles, int simple)
{
    char *str = NULL;
    int i = 0;
    int h = 0;
    int count = pars_error_line_quotes(line, doubles, simple);

    if (i == -1)
        return NULL;
    str = malloc(sizeof(char) * (my_strlen(line) - 1));
    for (i = 0; line[i] != '\0'; i++) {
        if (line[i] != line[count]) {
            str[h] = line[i];
            h++;
        }
    }
    str[h] = '\0';
    return str;
}

char *pars_line_supp_quotes(char *line)
{
    char *str = NULL;
    char dest;
    int i;
    int h = 0;

    for (i = 0; line[i] != '\'' && line[i] != '\"' && line[i] != '`'; i++);
    dest = line[i];
    str = malloc(sizeof(char) * ((my_strlen(line) - 1)));
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] != dest) {
            str[h] = line[i];
            h++;
        }
    }
    str[h] = '\0';
    return str;
}