/*
** EPITECH PROJECT, 2020
** PSU_42sh
** File description:
** fill_alias_struct.c
*/

#include "my.h"
#include "file.h"

#include "built_in.h"

static char *fill_substitute(char *raw_alias, char *alias)
{
    size_t pos = get_pos_word_end_in_str(alias, raw_alias);
    char *substitute = NULL;

    while (raw_alias[pos] && raw_alias[pos] <= ' ')
        pos++;
    if (raw_alias[pos] == '\"' || raw_alias[pos] == '\'') {
        substitute = my_str_cpy_quotation(raw_alias + pos, true, true, false);
    } else {
        substitute = my_strcpy(raw_alias + pos);
    }
    return substitute;
}

static char *fill_alias(char *raw_alias)
{
    char **alias_and_substitute = my_str_to_word_arr(raw_alias);
    char *alias = NULL;

    if (alias_and_substitute) {
        alias = my_strcpy(alias_and_substitute[0]);
        free_double_char_arr(alias_and_substitute);
    }
    return alias;
}

alias_t *fill_one_alias(char *raw_alias)
{
    alias_t *alias = NULL;
    size_t alias_word = 0;

    if (!is_alias_correct(raw_alias))
        return NULL;
    if (!(alias = malloc(sizeof(alias_t))))
        return NULL;
    alias_word = get_pos_word_end_in_str("alias", raw_alias);
    while(raw_alias[alias_word] <= ' ')
        alias_word++;
    alias->alias = fill_alias(raw_alias + alias_word);
    alias->substitute = fill_substitute(raw_alias + alias_word, alias->alias);
    return alias;
}

alias_t **fill_aliases_from_file(char **raw_aliases, size_t nb_aliases)
{
    alias_t **aliases = NULL;

    aliases = malloc(sizeof(alias_t *) * (nb_aliases + 1));
    if (!aliases)
        return NULL;
    for (size_t a = 0; a < nb_aliases; a++) {
        aliases[a] = fill_one_alias(raw_aliases[a]);
    }
    aliases[nb_aliases] = NULL;
    return aliases;
}