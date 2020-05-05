/*
** EPITECH PROJECT, 2020
** PSU_minishell2
** File description:
** minishell_manager.c
*/

#include "my.h"
#include "print.h"

#include "minishell.h"
#include "parsing_command_line.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static bool prompt_loop(env_memory_t *env_mem)
{
    char *line = NULL;

    while (1) {
        print_prompt();
        line = command_read();
        if (check_is_nothing(line))
            continue;
        if (check_exit(line))
            break;
        command_exec(line, env_mem);
        if (line)
            free(line);
    }
    return true;
}

bool minishell_manager(char **env)
{
    env_memory_t *env_mem = init_env_memory(env);

    signal(SIGINT, SIG_IGN);
    if (!env_mem)
        return false;
    prompt_loop(env_mem);
    free_env_mem(env_mem);
    signal(SIGINT, SIG_IGN);
    return true;
}