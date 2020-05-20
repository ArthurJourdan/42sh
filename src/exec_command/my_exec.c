/*
** EPITECH PROJECT, 2020
** PSU_minishell2
** File description:
** my_exec.c
*/

#include "my.h"

#include "minishell.h"
#include "parsing_command_line.h"

static bool my_exec(char * const command, char **options, char **env)
{
    int ret_exec = 0;

    ret_exec = execve(command, options, env);
    if (ret_exec == (-1)) {
        after_exec_error_msg(command);
        exit(0);
    }
    return true;
}

static bool exec_stantard_command(char **instructions,  memory_t *env_mem)
{
    char **path_arr = path_to_path_arr(env_mem);
    char *command = NULL;

    if (!path_arr)
        return false;
    command = command_match(path_arr, instructions[0]);
    free_double_char_arr(path_arr);
    if (!command) {
        exec_error_msg(instructions[0]);
        return false;
    }
    if (!my_exec(command, instructions, env_mem->env))
        return false;
    return true;
}

bool check_command(command_t *pre_command, memory_t *env_mem)
{
    char **instructions = my_str_to_word_arr(pre_command->instruction);
    bool return_type = false;

    if (!instructions || !instructions[0])
        return false;
    if (exec_built_ins(pre_command->instruction, env_mem)) {
        exit(EXIT_SUCCESS);
    } else if (!access(instructions[0], X_OK)) {
        my_exec(instructions[0], instructions, env_mem->env);
        return_type = true;
    } else  {
        return_type = exec_stantard_command(instructions, env_mem);
    }
    free_double_char_arr(instructions);
    return return_type;
}