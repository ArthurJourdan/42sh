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
#include <unistd.h>
#include <fcntl.h>

static void check_prev_pipes(command_t *tmp, int pipefd[2])
{
    if (!tmp->prev || tmp->prev->type != SIMPLE_I)
        return;
    if (!tmp->prev->prev)
        return;
    if (dup2(pipefd[0], STDIN_FILENO) == -1)
        exit(EXIT_FAILURE);
    close(pipefd[0]);
}

static void check_next_pipes(command_t *tmp, int pipefd[2])
{
    if (!tmp->next || tmp->next->type != SIMPLE_I)
        return;
    if (!tmp->next->next)
        return;
    if (dup2(pipefd[1], STDOUT_FILENO) == -1){
        exit(EXIT_FAILURE);
    }
    close(pipefd[1]);
}

void set_pipes(int pipefd[2][2], command_t *command, int fst_or_sec)
{
    command_t *tmp = command;

    check_prev_pipes(tmp, pipefd[invert_int(fst_or_sec)]);
    check_next_pipes(tmp, pipefd[fst_or_sec]);
}
