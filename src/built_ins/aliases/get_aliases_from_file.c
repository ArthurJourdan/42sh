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

    for (size_t a = 0; shrc_file[a]; a++) {
        if (alias_is_correct(shrc_file[a])) {
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
    my_dprintf(1, "%i\n\n", nb_aliases);
    aliases = fill_aliases_from_file(raw_aliases, nb_aliases);
    for (size_t a = 0; aliases[a]; a++) {
        my_dprintf(1, "alias %s\n", aliases[a]->alias);
        my_dprintf(1, "substitute %s\n\n", aliases[a]->substitute);
    }
    free_double_char_arr(raw_aliases);
    return aliases;
}