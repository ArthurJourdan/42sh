/*
** EPITECH PROJECT, 2020
** PSU_minishell2
** File description:
** set_pipes.c
*/

#include "my.h"
#include "file.h"

#include "minishell.h"
#include "parsing_command_line.h"

static void check_prev_pipes(command_t *tmp, int pipefd[2])
{
    if (tmp->prev && tmp->prev->type == SIMPLE_I) {
        if (tmp->prev->prev && (tmp->prev->prev->type != BUILT_IN ||
        is_built_in(tmp->prev->prev->instruction) == ENV)) {
            dup2(pipefd[0], STDIN_FILENO);
            close(pipefd[0]);
        }
    }
}

static void check_next_pipes(command_t *tmp, int pipefd[2])
{
    if (tmp->next && tmp->next->type == SIMPLE_I) {
        if (tmp->next->next && tmp->next->next->type != BUILT_IN) {
            dup2(pipefd[1], STDOUT_FILENO);
            close(pipefd[1]);
        }
    }
}

void set_pipes(int pipefd[2][2], command_t *command, int fst_or_sec)
{
    command_t *tmp = command;

    check_prev_pipes(tmp, pipefd[invert_int(fst_or_sec)]);
    check_next_pipes(tmp, pipefd[fst_or_sec]);
}