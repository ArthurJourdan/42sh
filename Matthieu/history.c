/*
** EPITECH PROJECT, 2020
** history.c
** File description:
** yolo
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

char *my_str_cpy_until_n_char(char *str, char c, int size)
{
    int h = 0;
    char *result = NULL;
    int count  = my_strlen(str);

    result = malloc(sizeof(char) * (count));
    for (int i = 0; str[i] != '\0'; i++) {
        if (i < size && str[i] == c)
            i++;
        else {
            result[h] = str[i];
            h++;
        }
    }
    result[h] = '\0';
    return result;
}

char *history(char *buff)
{
    char **tab = tab_history(buff);

    if (tab == NULL)
        return buff;
    for (int i = 0; tab[i] != NULL; i++)
        for (int y = 0; tab[i][y] != '\0'; y++) {
            if (tab[i][y] == '!' && tab[i][y + 1] != '!') {
                for (y = 0; tab[i][y] != '\0'; y++)
                    if (tab[i][y] != '!') {
                        my_putstr(tab[i][y]);
                        my_putchar('\n');
                    }
                buff = my_str_cpy_until_n_char(buff, '!', (i + 1));
            }
            else if (tab[i][y] == '!' && tab[i][y] == '!') {
                for (y = 0; tab[i][y] != '\0'; y++)
                    if (tab[i][y] != '!')
                        my_putstr(tab[i][y]);
            }
        }
}