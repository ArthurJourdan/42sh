/*
** EPITECH PROJECT, 2020
** PSU_42sh
** File description:
** check_fill_aliases.c
*/

#include "my.h"
#include "file.h"

#include "built_in.h"

static char *replace_with_substitute(char *line, char *word, alias_t *alias)
{
    char *new = NULL;
    ssize_t after_word = get_pos_word_end_in_str(word, line);

    if (after_word == -1)
        return line;
    new = my_strcat(alias->substitute, line + after_word, false, false);
    free_char_to_null(line);
    return new;
}

static char *check_for_alias(char *line, alias_t *alias)
{
    char **tmp_line = tmp_line = my_str_to_word_arr(line);

    if (!tmp_line)
        return line;
    if (my_strcmp(tmp_line[0], alias->alias)) {
        line = replace_with_substitute(line, tmp_line[0], alias);
    }
    free_double_char_arr(tmp_line);
    return line;
}

char *check_fill_aliases(char *line, alias_t **aliases)
{
    if (!line || !aliases)
        return line;
    for (size_t a = 0; aliases[a]; a++) {
        line = check_for_alias(line, aliases[a]);
    }
    return line;
}