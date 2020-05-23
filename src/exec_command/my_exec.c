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
    char *command = NULL;

    command = get_command_path(instructions, env_mem);
    if (!command) {
        exec_error_msg(instructions[0]);
        return false;
    }
    if (!my_exec(command, instructions, env_mem->env))
        return false;
    return true;
}

static bool type_cmd(command_t *command, memory_t *env_mem, char **instruc)
{
    if (exec_built_ins(command->instruction, env_mem)) {
        exit(EXIT_SUCCESS);
    } else if (!access(instruc[0], X_OK) && my_str_has_char(instruc[0], '/')) {
        my_exec(instruc[0], instruc, env_mem->env);
        return true;
    } else  {
        return exec_stantard_command(instruc, env_mem);
    }
    return false;
}

bool check_command(command_t *cmd, memory_t *env_mem)
{
    char **instruct = NULL;
    bool return_type = false;

    instruct = my_str_to_word_arr(cmd->instruction);
    if (!instruct || !instruct[0])
        return false;
    return_type = type_cmd(cmd, env_mem, instruct);
    free_double_char_arr(instruct);
    return return_type;
}
