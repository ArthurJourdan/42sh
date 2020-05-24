/*
** EPITECH PROJECT, 2020
** command_quotes.c
** File description:
** yolo
*/

#include "my.h"
#include "print.h"

int error_print_quote(char *stock, char *line, int i)
{
    if (stock[0] == ' ' && line[i] == stock[1] && stock[1] != ' ') {
        my_putstr(1, "Unmatched \'");
        my_putchar(1, stock[1]);
        my_putstr(1, "\'\n");
        return 1;
    }
    return 0;
}

char *multi_quotes_remp(char *line, char *stock , int i)
{
    if (line[i] == stock[0])
        stock[0] = ' ';
    else if (line[i] == stock[1])
        stock[1] = ' ';
    return stock;
}

int command_access_quote_error(char *line)
{
    int h = 0;
    char *stock = malloc(sizeof(char) * 4);

    stock = memset(stock, '\0', 4);
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == '"' || line[i] == '\'' || line[i] == '`') {
            if (error_print_quote(stock, line, i) == 1)
                return 1;
            stock = multi_quotes_remp(line, stock, i);
            if (stock[0] == ' ' || stock[1] == ' ') {
                h = 0;
                continue;
                if (stock[1] == ' ')
                    h++;
            }
            stock[h] = line[i];
            h++;
        }
    }
    return 0;
}

int command_access_quote(char *line, char c)
{
    int pair_or_impair = 0;
    int count = 0;

    for (int i = 0; line[i] != '\0'; i++)
        if (line[i] == c)
            count++;
    pair_or_impair = count % 2;
    if (pair_or_impair == 0)
        return count;
    else if (count > 0)
        return -1;
    else
        return 0;
}