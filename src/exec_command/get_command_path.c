/*
** EPITECH PROJECT, 2020
** PSU_42sh
** File description:
** get_command_path.c
*/

#include "my.h"
#include "print.h"

#include "built_in.h"
#include "minishell.h"

char *get_command_path(char **instructions, memory_t *env_mem)
{
    char **path_arr = path_to_path_arr(env_mem);
    char *command = NULL;

    if (!path_arr)
        return NULL;
    command = command_match(path_arr, instructions[0]);
    free_double_char_arr(path_arr);
    if (!command) {
        exec_error_msg(instructions[0]);
        return NULL;
    }
    return command;
}
