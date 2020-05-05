/*
** EPITECH PROJECT, 2020
** my_lib
** File description:
** my_sep_parser.c
*/

#include "my.h"
#include "file.h"

#include "minishell.h"

static char * const PATH = "PATH=";

char **path_to_path_arr(env_memory_t *env_mem)
{
    char *env_path = NULL;
    char **paths = NULL;

    env_path = find_var_in_env(PATH, env_mem->env_memory);
    if (!env_path)
        return NULL;
    paths = my_sep_parser(env_path, ":");
    if (!paths)
        return NULL;
    replace_char_in_arr(paths, ':', '\0');
    return paths;
}