/*
** EPITECH PROJECT, 2020
** PSU_42sh
** File description:
** fill_alias_struct.c
*/

#include "my.h"
#include "file.h"

#include "built_in.h"

static char *fill_substitute(char **raw_alias)
{
    char *substitute = NULL;
    char *tmp_substitute = NULL;
    char *sec_tmp_substitute = NULL;

    for (size_t a = 0; raw_alias[a]; a++) {
        tmp_substitute = my_strcat(tmp_substitute, raw_alias[a], true, false);
        tmp_substitute = my_strcat(tmp_substitute, " ", true, false);
    }
    if (tmp_substitute[0] == '\"' || tmp_substitute[0] == '\'') {
        substitute = my_str_cpy_quotation(tmp_substitute, true, true, false);
    } else {
        substitute = my_strcpy(tmp_substitute);
    }
    return substitute;
}

static char *fill_alias(char **raw_alias)
{
    char *alias = NULL;

    alias = my_strcpy(raw_alias[0]);
    return alias;
}

alias_t *fill_one_alias(char **raw_alias)
{
    alias_t *alias = NULL;

    if (!is_alias_correct(raw_alias))
        return NULL;
    if (!(alias = malloc(sizeof(alias_t))))
        return NULL;
    alias->alias = fill_alias(raw_alias + 1);
    alias->substitute = fill_substitute(raw_alias + 2);
    return alias;
}

alias_t **fill_aliases_from_file(char **raw_aliases, size_t nb_aliases)
{
    alias_t **aliases = NULL;
    char **raw_tmp = NULL;

    aliases = malloc(sizeof(alias_t *) * (nb_aliases + 1));
    if (!aliases)
        return NULL;
    for (size_t a = 0; a < nb_aliases; a++) {
        raw_tmp = my_str_to_word_arr(raw_aliases[a]);
        aliases[a] = fill_one_alias(raw_tmp);
        free_double_char_arr(raw_tmp);
    }
    aliases[nb_aliases] = NULL;
    return aliases;
}