/*
** EPITECH PROJECT, 2020
** 42SH Check wildcard
** File description:
** 
*/

#include "my.h"
#include "minishell.h"

int *compare_char(char *newcmd, int *ret, int i)
{
    for (int j = 0; newcmd[j] != '\0'; j++) {
        if (newcmd[j] == '*' || newcmd[j] == '?'|| newcmd[j] == '[') {
            ret[0] = 0;
            ret[1] = i;
            return ret;
        }
    }
    return ret;
}

int *check_wildcard(char **newcmd)
{
    int *ret = malloc(sizeof(int) * 2);

    ret[0] = 1;
    ret[1] = 0;
    for (int i = 0; newcmd[i] != NULL; i++)
        ret = compare_char(newcmd[i], ret, i);
    return ret;
}
