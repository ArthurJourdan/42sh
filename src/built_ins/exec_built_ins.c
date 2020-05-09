/*
** EPITECH PROJECT, 2020
** PSU_minishell2
** File description:
** exec_built_ins.c
*/

#include "my.h"

#include "minishell.h"
#include "parsing_command_line.h"

static const built_ins_t built_ins[] = {
    {"cd", change_location},
    {"env", disp_env},
    {"setenv", set_env},
    {"unsetenv", unset_env},
    {"exit", my_exit}
};

int is_built_in(char *instructions)
{
    char **command = my_str_to_word_arr(instructions);

    if (!command || !command[0])
        return -1;
    for (size_t a = 0; a < ARRAY_SIZE(built_ins); a++) {
        if (my_strcmp(command[0], built_ins[a].name)) {
            if (a == 2 && !command[1])
                return 1;
            free_double_char_arr(command);
            return a;
        }
    }
    free_double_char_arr(command);
    return -1;
}

static bool check_next_cmd(int type, command_t *next)
{
    if (!next)
        return false;
    if (type == ENV)
        return false;
    if (next->type == SEMICOLON) {
        return false;
    }
    return true;
}

bool exec_built_ins(char *instructions, env_memory_t *env_mem, command_t *next)
{
    int type = is_built_in(instructions);
    char **command = NULL;

    if (type != -1) {
        if (check_next_cmd(type, next)) {
            my_dprintf(1, "\n");
        } else {
            command = my_str_to_word_arr(instructions);
            built_ins[type].fct(command, env_mem);
            free_double_char_arr(command);
        }
        return true;
    }
    return false;
}
