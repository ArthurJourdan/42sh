/*
** EPITECH PROJECT, 2020
** PSU_42sh
** File description:
** change_dol_var_env.c
*/

#include "my.h"
#include "file.h"
#include "print.h"

#include "built_in.h"

static char *cpy_var_to_replace(char *line)
{
    char *name_var = NULL;
    size_t len_var = 0;

    while (line[len_var] && line[len_var] > ' ') {
        if (line[len_var] == '\"' || line[len_var] == '\'')
            break;
        len_var++;
    }
    if (!len_var)
        return NULL;
    name_var = my_str_n_cpy(line, len_var);
    return name_var;
}

static char *get_var_to_replace(char *line, ssize_t *pos_dol)
{
    char *name_var = NULL;

    *(pos_dol) = get_pos_word_end_in_str("$", line + *(pos_dol));
    if (*(pos_dol) == -1)
        return NULL;
    name_var = cpy_var_to_replace(line + *(pos_dol));
    return name_var;
}

static char *get_substitute_for_replace(char *name_var, char **env)
{
    char *var = find_var_in_env(name_var, env);

    if (!var) {
        free_char_to_null(name_var);
        my_dprintf(STDERR_FILENO, "%s: Undefined variable.\n", name_var);
        return NULL;
    }
    return var;
}

static char *mv_dol_var(char *line, char *substitute, char *name, size_t pos)
{
    char *tmp_end = NULL;
    char *tmp_beg = NULL;
    size_t len_name = my_strlen(name);
    short remove_equal = 0;

    tmp_end = my_strcpy(line + pos + len_name);
    tmp_beg = my_str_n_cpy(line, pos - 1);
    line = free_char_to_null(line);
    if (substitute[0] == '=')
        remove_equal++;
    line = my_strcat_tot(3, tmp_beg, substitute + remove_equal, tmp_end);
    return line;
}

char *change_dol_var_env(char *line, char **env)
{
    ssize_t pos_dol = 0;
    char *name_var = NULL;
    char *var = NULL;

    do {
        name_var = get_var_to_replace(line, &pos_dol);
        if (!name_var)
            return line;
        var = get_substitute_for_replace(name_var, env);
        if (!var) {
            free(line);
            return NULL;
        }
        line = mv_dol_var(line, var, name_var, pos_dol);
        name_var = free_char_to_null(name_var);
        var = free_char_to_null(var);
    } while (pos_dol != -1);
    return line;
}