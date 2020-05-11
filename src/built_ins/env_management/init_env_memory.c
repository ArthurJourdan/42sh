/*
** EPITECH PROJECT, 2020
** PSU_minishell2
** File description:
** init_env_memory.c
*/

#include "my.h"

#include "built_in.h"

memory_t *init_env_memory(char **env)
{
    memory_t *memory = malloc(sizeof(memory_t));

    if (!memory)
        return NULL;
    memory->env = double_char_arr_cpy(env, false);
    memory->env_memory = double_char_arr_cpy(env, false);
    // memory->aliases = get_aliases();
    return memory;
}
