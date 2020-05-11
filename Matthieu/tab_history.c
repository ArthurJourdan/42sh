/*
** EPITECH PROJECT, 2020
** tab_history.c
** File description:
** yolo
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

int if_history(char *buff)
{
    int count = 0;
    int stock = 0;

    while (buff[stock] != '\0') {
        if (buff[stock] == '!')
            count++;
        if (buff[stock] == '!' && buff[stock + 1] == '!')
            count--;
        stock++;
    }
    return count;
}

char **malloc_history(char *buff, int count, char **tab)
{
    int i;
    int y = 0;

    tab = malloc(sizeof(char *) * (count + 1));
    tab[count] = NULL;
    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == '!') {
            for (count = 0 ; buff[i] != '\0' && buff[i] != ' '; i++)
                count++;
            tab[y] = malloc(sizeof(char) * (count + 1));
            tab[y][count] = '\0';
            y++;
        }
        if (buff[i] == '\0')
            return tab;
    }
    return tab;
}

char **remp_tab_history(char **tab, char *buff)
{
    int y = 0;
    int h = 0;

    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == '!') {
            for (h = 0; buff[i] != '\0' && buff[i] != ' '; h++) {
                tab[y][h] = buff[i];
                i++;
            }
            tab[y][h] = '\0';
            y++;
        }
        if (buff[i] == '\0')
            return tab;
    }
    return tab;
}

char **tab_history(char *buff)
{
    char **tab = NULL;
    int count = 0;
    int stock = 0;

    count = if_history(buff);
    if (count != 0) {
        tab = malloc_history(buff, count, tab);
        tab = remp_tab_history(tab, buff);
        return tab;
    }
    else
        return NULL;
    return tab;
}