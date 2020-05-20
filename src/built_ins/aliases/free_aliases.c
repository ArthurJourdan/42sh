/*
** EPITECH PROJECT, 2020
** PSU_42sh
** File description:
** free_aliases.c
*/

#include "my.h"

#include "built_in.h"

static void free_one_alias(alias_t *alias)
{
    free_char_to_null(alias->alias);
    free_char_to_null(alias->substitute);
    free(alias);
}

void free_aliases(alias_t **aliases)
{
    for (size_t a = 0; aliases[a]; a++) {
        free_one_alias(aliases[a]);
    }
    free(aliases);
}