/*
** EPITECH PROJECT, 2020
** PSU_42sh
** File description:
** manage_history.c
*/

#include "my.h"

#include "minishell.h"
#include "parsing_command_line.h"
#include "built_in.h"

static ssize_t check_len_history(memory_t *env_mem)
{
    ssize_t len_history = my_arrlen(env_mem->history);

    len_history--;
    if (len_history >= MAX_LEN_HISTORY) {
        env_mem->history = remove_str_to_arr(env_mem->history, 0, true);
    }
    return len_history;
}

char *check_fill_history(char *line, memory_t *env_mem)
{
    ssize_t len_history = check_len_history(env_mem);

    env_mem->history = add_str_to_arr(env_mem->history, line, true, false);
    if (len_history == -1)
        return line;
    line = check_two_marks(line, env_mem->history, len_history);
    line = check_one_mark(line, env_mem->history, len_history);
    return line;
}