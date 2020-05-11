/*
** EPITECH PROJECT, 2020
** PSU_42sh
** File description:
** get_aliases.c
*/

#include "my.h"
#include "file.h"

static char * const SHRC = ".42shrc";
static char * const ALIAS_NAME = "alias";

static bool check_if_alias(char * const line, char **tmp_line)
{
    if (!my_strcmp(ALIAS_NAME, tmp_line[0]))
        return false;
    if (!are_quotes_filled(line))
        return false;
}

static bool check_one_line(char * const line)
{
    char **tmp_line = my_str_to_word_arr(line);
    bool return_type = check_if_alias(line, tmp_line);

    free_double_char_arr(tmp_line);
    return return_type;
}

static char **sort_aliases_from_rest(char **shrc_file)
{
    char **aliases = NULL;

    for (size_t a = 0; shrc_file[a]; a++) {
        if (check_one_line(shrc_file[a]))
            aliases = add_str_to_arr(aliases, shrc_file[a], true, false);
    }
    return aliases;
}

static char **get_aliases_in_file()
{
    char **shrc_file = get_entire_file_double_arr(SHRC);
    char **aliases = NULL;

    if (!shrc_file)
        return NULL;
    aliases = sort_aliases_from_rest(shrc_file);
    free_double_char_arr(shrc_file);
    return shrc_file;
}
char **get_aliases(void)
{
    char **aliases = NULL;


    return aliases;
}