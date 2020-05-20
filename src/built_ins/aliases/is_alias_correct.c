/*
** EPITECH PROJECT, 2020
** PSU_42sh
** File description:
** is_alias_correct.c
*/

#include "my.h"

static char * const ALIAS_NAME = "alias";

static bool check_inside_alias(char **tmp_line)
{
    if (tmp_line[0] && !my_strcmp(ALIAS_NAME, tmp_line[0])) {
        return false;
    }
    if (!tmp_line[1] || !tmp_line[2]) {
        return false;
    }
    if (my_arrlen(tmp_line) < 2) {
        return false;
    }
    return true;
}

bool is_alias_correct(char * const line)
{
    char **tmp_line = my_str_to_word_arr(line);
    bool return_type = true;

    if (!tmp_line)
        return false;
    return_type = check_inside_alias(tmp_line);
    free_double_char_arr(tmp_line);
    return return_type;
}