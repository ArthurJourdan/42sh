/*
** EPITECH PROJECT, 2020
** PSU_42sh
** File description:
** get_aliases.c
*/

#include "my.h"
#include "file.h"

#include "built_in.h"

static char * const ALIAS_NAME = "alias";

static bool check_if_alias(char * const line)
{
    char **tmp_line = my_str_to_word_arr(line);
    bool return_type = true;

    if (!tmp_line || !tmp_line[0])
        return false;
    if (!my_strcmp(ALIAS_NAME, tmp_line[0])) {
        return_type = false;
    }
    if (!are_quotes_filled(line)) {
        return_type = false;
    }
    if (!tmp_line[1] || !tmp_line[2]) {
        return_type = false;
    } else if (!is_alias_correct(tmp_line[1], tmp_line[2])) {
        return_type = false;
    }
    free_double_char_arr(tmp_line);
    return return_type;
}

static char **sort_aliases_from_rest(char **shrc_file)
{
    char **aliases = NULL;

    for (size_t a = 0; shrc_file[a]; a++) {
        if (check_if_alias(shrc_file[a])) {
            aliases = add_str_to_arr(aliases, shrc_file[a], true, false);
        }
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
    // my_dprintf(1, "%i\n\n", nb_aliases);
    aliases = fill_aliases_from_file(raw_aliases, nb_aliases);
    /* for (size_t a = 0; aliases[a]; a++) {
        my_dprintf(1, "alias %s\n", aliases[a]->alias);
        my_dprintf(1, "substitute %s\n\n", aliases[a]->substitute);
    } */
    return aliases;
}