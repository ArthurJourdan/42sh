/*
** EPITECH PROJECT, 2020
** PSU_minishell2
** File description:
** init_env_memory.c
*/

#include "my.h"

#include "minishell.h"

env_memory_t *init_env_memory(char **env)
{
    env_memory_t *env_memory = malloc(sizeof(env_memory_t));

    if (!env_memory)
        return NULL;
    env_memory->env = double_char_arr_cpy(env, false);
    env_memory->env_memory = double_char_arr_cpy(env, false);
    return env_memory;
}