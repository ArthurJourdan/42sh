/*
** EPITECH PROJECT, 2020
** PSU_minishell2
** File description:
** free_all.c
*/

#include "my.h"

#include "parsing_command_line.h"
#include "minishell.h"
#include "built_in.h"

void free_one_command(command_t *command)
{
    command_t *tmp_prev = NULL;
    command_t *tmp_next = NULL;

    if (!command)
        return;
    if (command->instruction)
        free(command->instruction);
    if (command->prev) {
        tmp_prev = command->prev;
        tmp_prev->next = command->next;
    }
    if (command->next) {
        tmp_next = command->next;
        tmp_next->prev = command->prev;
    }
    free(command);
}

void free_command(command_t *command)
{
    while (command) {
        if (command->instruction)
        free(command->instruction);
        if (command->prev)
            free(command->prev);
        command = command->next;
    }
}

void free_env_mem(memory_t *env_mem)
{
    free_double_char_arr(env_mem->env_memory);
    free_double_char_arr(env_mem->env);
    free_double_char_arr(env_mem->history);
    free_aliases(env_mem->aliases);
    free(env_mem);
}