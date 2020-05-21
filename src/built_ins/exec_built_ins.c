/*
** EPITECH PROJECT, 2020
** PSU_minishell2
** File description:
** exec_built_ins.c
*/

#include "my.h"
#include "print.h"

#include "minishell.h"
#include "parsing_command_line.h"
#include "built_in.h"

static const built_ins_t built_ins[] = {
    {"cd", change_location, CD},
    {"env", disp_env, ENV},
    {"setenv", set_env, SETENV},
    {"unsetenv", unset_env, UNSETENV},
    {"history", display_history, HISTORY},
    {"alias", get_alias, ALIAS},
    {"which", disp_which, WHICH},
    // {"where", disp_where, WHERE},
    {"exit", my_exit, EXIT}
};

int is_built_in(char *instructions)
{
    char **command = my_str_to_word_arr(instructions);

    if (!command || !command[0])
        return -1;
    for (size_t a = 0; a < ARRAY_SIZE(built_ins); a++) {
        if (my_strcmp(command[0], built_ins[a].name)) {
            free_double_char_arr(command);
            return a;
        }
    }
    free_double_char_arr(command);
    return -1;
}

bool exec_built_ins(char *instructions, memory_t *env_mem)
{
    int type = is_built_in(instructions);
    char **command = NULL;

    if (type != -1) {
        command = my_str_to_word_arr(instructions);
        built_ins[type].fct(command, env_mem);
        free_double_char_arr(command);
        return true;
    }
    return false;
}
