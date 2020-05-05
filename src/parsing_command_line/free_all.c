/*
** EPITECH PROJECT, 2020
** PSU_minishell2
** File description:
** free_all.c
*/

#include "parsing_command_line.h"
#include "minishell.h"

void free_command(command_t *command)
{
    while (command) {
        free(command->instruction);
        if (command->prev)
            free(command->prev);
        command = command->next;
    }
}

void free_env_mem(env_memory_t *env_mem)
{
    free_double_char_arr(env_mem->env_memory);
    free_double_char_arr(env_mem->env);
    free(env_mem);
}