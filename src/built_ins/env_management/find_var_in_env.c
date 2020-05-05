/*
** EPITECH PROJECT, 2020
** PSU_minishell2
** File description:
** find_var_in_env.c
*/

#include "my.h"
#include "file.h"

char *find_var_in_env(char * const var, char **env)
{
    char *var_str = NULL;
    size_t len_var = my_strlen(var);
    ssize_t pos = get_index_word_begin_in_arr(var, env);

    if (pos == -1)
        return NULL;
    var_str = my_strcpy(env[pos] + len_var);
    return var_str;
}