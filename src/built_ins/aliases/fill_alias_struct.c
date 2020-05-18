/*
** EPITECH PROJECT, 2020
** PSU_42sh
** File description:
** fill_alias_struct.c
*/

#include "my.h"

#include "built_in.h"

alias_t **fill_aliases_from_file(char **raw_aliases, size_t nb_aliases)
{
    alias_t **aliases = NULL;
    char **each_alias = NULL;

    aliases = malloc(sizeof(alias_t *) * (nb_aliases + 1));
    if (!aliases)
        return NULL;
    for (size_t a = 0; a < nb_aliases && raw_aliases[a]; a++) {
        each_alias = my_str_to_word_arr(raw_aliases[a]);
        aliases[a] = malloc(sizeof(alias_t));
        if (!aliases[a])
            break;
        aliases[a]->alias = my_strcpy(each_alias[1]);
        // aliases[a]->substitute = my_str_cpy_quotation(each_alias[2], 1, 1, 0);
        free_double_char_arr(each_alias);
    }
    aliases[nb_aliases] = NULL;
    return aliases;
}

bool is_alias_correct(char * const alias, char * const substitute)
{
    if (!alias || !substitute)
        return false;
    return true;
}