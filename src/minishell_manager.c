/*
** EPITECH PROJECT, 2020
** PSU_minishell2
** File description:
** minishell_manager.c
*/

#include "my.h"
#include "file.h"
#include "print.h"

#include "minishell.h"
#include "parsing_command_line.h"
#include "built_in.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static char *assign_new_commands(char *line, memory_t *env_mem)
{
    line = rm_char_in_str(line, '\n');
    line = is_wildcard(line);
    line = check_fill_history(line, env_mem);
    // line = check_fill_aliases(line, env_mem->aliases);
    return line;
}

static bool prompt_loop(memory_t *env_mem)
{
    char *line = NULL;

    while (1) {
        print_prompt();
        line = command_read();
        if (!line)
            continue;
        line = assign_new_commands(line, env_mem);
        command_exec(line, env_mem);
        if (line)
            free(line);
    }
    return true;
}

bool minishell_manager(char **env)
{
    memory_t *env_mem = init_env_memory(env);

    // signal(SIGINT, SIG_IGN);
    if (!env_mem)
        return false;
    prompt_loop(env_mem);
    free_env_mem(env_mem);
    // signal(SIGINT, SIG_IGN);
    return true;
}
