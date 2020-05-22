/*
** EPITECH PROJECT, 2020
** command_quotes.c
** File description:
** yolo
*/

#include "my.h"
#include "print.h"

int command_access_double_quote(char *line)
{
    int pair_or_impair = 0;
    int count = 0;

    for (int i = 0; line[i] != '\0'; i++)
        if (line[i] == '"')
            count++;
    pair_or_impair = count % 2;
    if (pair_or_impair == 0)
        return count;
    else if (count > 0)
        return -1;
    else
        return 0;
}

int command_access_simple_quote(char *line)
{
    int pair_or_impair = 2;
    int count = 0;

    for (int i = 0; line[i] != '\0'; i++)
        if (line[i] == '\'')
            count++;
    pair_or_impair = count % 2;
    if (pair_or_impair == 0)
        return count;
    else if (count > 0)
        return -1;
    else
        return 0;
}