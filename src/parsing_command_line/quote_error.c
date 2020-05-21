/*
** EPITECH PROJECT, 2020
** quote_error.c
** File description:
** yolo
*/

#include "my.h"
#include "print.h"

bool command_access_double_quote(char *line)
{
    int pair_or_impair = 0;
    int count = 0;

    for (int i = 0; line[i] != '\0'; i++)
        if (line[i] == '"')
            count++;
    pair_or_impair = count % 2;
    if (pair_or_impair == 0)
        return true;
    else
        return false;
}

bool command_access_simple_quote(char *line)
{
    int pair_or_impair = 0;
    int count = 0;

    for (int i = 0; line[i] != '\0'; i++)
        if (line[i] == '\'')
            count++;
    pair_or_impair = count % 2;
    if (pair_or_impair == 0)
        return true;
    else
        return false;
}

int if_echo(char *line)
{
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == 'e' && line[i + 1] == 'c' \
        && line[i + 2] == 'c' && line[i + 3] == 'h' \
        && (line[i + 4] == ' ' || line[i + 5] == '\0'))
            return 0;
    }
    return 1;
}

char *pars_line_supp_quotes(char *line)
{
    char *str = NULL;
    int count = 0;
    int h = 0;

    for (int i = 0; line[i] != '\0'; i++)
        if (line[i] == '"' || line[i] == '\'')
            count++;
    str = malloc(sizeof(char) * ((my_strlen(line) - count) + 1));
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] != '"' && line[i] != '\'') {
            str[h] = line[i];
            h++;
        }
    }
    str[h] = '\0';
    return str;
}

char *quote_error(char *line)
{
    if ((command_access_simple_quote(line)
    && command_access_double_quote(line)) || if_echo(line) == 1) {
        line = pars_line_supp_quotes(line);
    }
    return line;
}