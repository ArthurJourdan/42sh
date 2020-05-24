/*
** EPITECH PROJECT, 2020
** PSU_42sh
** File description:
** check_fill_aliases.c
*/

#include "my.h"
#include "file.h"

#include "built_in.h"

static char *replace_with_substitute(char *line, alias_t *alias, ssize_t pos)
{
    char *tmp_end = NULL;
    char *tmp_beg = NULL;
    size_t len_alias = my_strlen(alias->alias);

    tmp_end = my_strcpy(line + pos + len_alias);
    tmp_beg = my_str_n_cpy(line, pos);
    line = my_strcat_tot(3, tmp_beg, alias->substitute, tmp_end);
    free(tmp_end);
    free(tmp_beg);
    return line;
}

static char *check_for_alias(char *line, alias_t *alias)
{
    ssize_t pos = get_pos_word_in_str(alias->alias, line);

    while (pos != -1) {
        line = replace_with_substitute(line, alias, pos);
        pos += my_strlen(alias->alias);
        if (get_pos_word_in_str(alias->alias, line + pos) == -1)
            break;
        pos += get_pos_word_in_str(alias->alias, line + pos);
    }
    return line;
}

char *check_fill_aliases(char *line, alias_t **aliases)
{
    ssize_t pos_alias_word = 0;
    bool alias_of_alias = false;

    if (!line || !aliases)
        return line;
    pos_alias_word = get_pos_word_in_str("alias", line);
    if (pos_alias_word == 0) {
        alias_of_alias = true;
        line += 5;
    }
    for (size_t a = 0; aliases[a]; a++) {
        line = check_for_alias(line, aliases[a]);
    }
    if (alias_of_alias)
    line = my_strcat("alias ", line, false, false);
    return line;
}