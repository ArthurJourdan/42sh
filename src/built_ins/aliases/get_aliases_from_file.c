/*
** EPITECH PROJECT, 2020
** PSU_42sh
** File description:
** get_aliases.c
*/

#include "my.h"
#include "file.h"

#include "built_in.h"

static char **sort_aliases_from_rest(char **shrc_file)
{
    char **aliases = NULL;
    char **raw_alias = NULL;

    for (size_t a = 0; shrc_file[a]; a++) {
        raw_alias = my_str_to_word_arr(shrc_file[a]);
        if (is_alias_correct(raw_alias)) {
            aliases = add_str_to_arr(aliases, shrc_file[a], true, false);
        }
        free_double_char_arr(raw_alias);
    }
    return aliases;
}

alias_t **get_aliases_from_file(char **shrc_file)
{
    char **raw_aliases = NULL;
    size_t nb_aliases = 0;
    alias_t **aliases = NULL;

    raw_aliases = sort_aliases_from_rest(shrc_file);
    nb_aliases = my_arrlen(raw_aliases);
    if (!nb_aliases)
        return NULL;
    aliases = fill_aliases_from_file(raw_aliases, nb_aliases);
    free_double_char_arr(raw_aliases);
    return aliases;
}