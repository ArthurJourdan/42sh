/*
** EPITECH PROJECT, 2020
** quote_error.c
** File description:
** yolo
*/

#include "my.h"
#include "print.h"

int if_echo(char *line)
{
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == 'e' && line[i + 1] == 'c'
        && line[i + 2] == 'h' && line[i + 3] == 'o'
        && (line[i + 4] == ' ' || line[i + 5] == '\0'))
            return 0;
    }
    return 1;
}

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
    int count = 0;
    int h = 0;
    int i = pars_error_line_quotes(line, doubles, simple);

    if (i == -1)
        return NULL;
    count = i;
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
    int simple = command_access_simple_quote(line);
    int doubles = command_access_double_quote(line);

    if (simple == 0 && doubles == 0)
        return line;
    if ((simple > 0 && doubles == 0) || (simple == 0 && doubles > 0))
        line = pars_line_supp_quotes(line);
    if (if_echo(line) == 0) {
        line = pars_line_supp_quotes_echo(line, doubles, simple);
        return line;
    }
    if (doubles < 0) {
        my_putstr(1, "Unmatched \'\"\'.\n");
        return NULL;
    }
    else if (simple < 0) {
        my_putstr(1, "Unmatched \'\'\'.\n");
        return NULL;
    }
    return line;
}