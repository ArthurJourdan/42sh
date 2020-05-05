/*
** EPITECH PROJECT, 2020
** PSU_minishell2
** File description:
** check_exceptions.c
*/

#include "my.h"

bool check_exit(char *line)
{
    if (my_strcmp("exit\n", line)) {
            line = free_char_to_null(line);
        return true;
    }
    return false;
}

bool check_is_nothing(char *line)
{
    if (my_str_is_nothing(line)) {
        if (line)
            line = free_char_to_null(line);
        return true;
    }
    return false;
}