/*
** EPITECH PROJECT, 2020
** PSU_42sh
** File description:
** is_alias_correct.c
*/

#include "my.h"

static char * const ALIAS_NAME = "alias";

static bool check_inside_alias(char **raw_alias)
{
    if (raw_alias[0] && !my_strcmp(ALIAS_NAME, raw_alias[0])) {
        return false;
    }
    if (!raw_alias[1] || !raw_alias[2]) {
        return false;
    }
    if (my_arrlen(raw_alias) < 2) {
        return false;
    }
    return true;
}

bool is_alias_correct(char **raw_alias)
{
    bool return_type = true;

    if (!raw_alias)
        return false;
    return_type = check_inside_alias(raw_alias);
    return return_type;
}