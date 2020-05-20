/*
** EPITECH PROJECT, 2020
** PSU_42sh
** File description:
** fill_alias_struct.c
*/

#include "my.h"
#include "file.h"

#include "built_in.h"

static char *get_substitute(char *raww_alias)
{
    char *substitute = NULL;

    substitute = my_strcat(substitute, each_alias[b + 1]);
}

static char *get_alias(char *raw_alias)
{
    char *alias = NULL;
    char **quote_chars = NULL;
    char **sorted_quotes = NULL;


}

alias_t *fill_one_alias(char *raw_alias)
{
    alias_t *alias = NULL;

    if (!is_alias_correct(raw_alias))
        return NULL;
    if (!(alias = malloc(sizeof(alias_t))))
        return NULL;
    alias->substitute = get_substitute(raw_alias);
    alias->alias = get_nth_word_in_str(raw_alias, 1);
    // rm_char_in_str(alias->substitute, '\"');
    // rm_char_in_str(alias->substitute, '\'');
    return alias;
}

alias_t **fill_aliases_from_file(char **raw_aliases, size_t nb_aliases)
{
    alias_t **aliases = NULL;
    size_t after_alias_word = 0;

    aliases = malloc(sizeof(alias_t *) * (nb_aliases + 1));
    if (!aliases)
        return NULL;
    for (size_t a = 0; a < nb_aliases && raw_aliases[a]; a++) {
        after_alias_word = get_pos_word_end_in_str("alias", raw_aliases[a]);
        while(raw_aliases[a][after_alias_word++] <= ' ');
        aliases[a] = fill_one_alias(raw_aliases[a] + after_alias_word);
    }
    aliases[nb_aliases] = NULL;
    return aliases;
}