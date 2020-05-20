/*
** EPITECH PROJECT, 2020
** PSU_minishell2
** File description:
** init_env_memory.c
*/

#include "my.h"
#include "file.h"

#include "built_in.h"

static char * const SHRC = ".42shrc";

static void init_with_rc_file(memory_t *memory)
{
    char **shrc_file = get_entire_file_double_arr(SHRC);

    if (!shrc_file)
        return;
    memory->aliases = get_aliases_from_file(shrc_file);
    free_double_char_arr(shrc_file);
}

memory_t *init_env_memory(char **env)
{
    memory_t *memory = malloc(sizeof(memory_t));

    if (!memory)
        return NULL;
    memory->env = double_char_arr_cpy(env, false);
    memory->env_memory = double_char_arr_cpy(env, false);
    memory->history = NULL;
    memory->aliases = NULL;
    init_with_rc_file(memory);
    return memory;
}
