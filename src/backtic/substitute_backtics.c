/*
** EPITECH PROJECT, 2020
** PSU_42sh
** File description:
** substitute_backtics.c
*/

#include "my.h"

#include "parsing_command_line.h"
#include "minishell.h"
#include "built_in.h"

static command_t *parent_process(command_t *cmd, pid_t my_pid, int pipefd[2])
{
    close(pipefd[1]);
    waitpid(my_pid, NULL, 0);
    cmd = add_cmd_from_backtic(cmd, pipefd[0]);
    return cmd;
}

static void child_process(command_t *cmd, memory_t *env_m, int pipefd[2])
{
    dup2(pipefd[1], STDOUT_FILENO);
    close(pipefd[1]);
    close(pipefd[0]);
    cmd = get_cmd_backtick(cmd);
    command_exec(cmd, env_m);
    exit(EXIT_SUCCESS);
}

static command_t *fork_backtics(command_t *cmd, memory_t *env_m, int pipefd[2])
{
    pid_t my_pid = -1;

    my_pid = fork();
    if (my_pid == -1) {
        return NULL;
    } else if (my_pid == 0) {
        child_process(cmd, env_m, pipefd);
    } else {
        cmd = parent_process(cmd, my_pid, pipefd);
    }
    return cmd;
}

static command_t *pipe_backtics(command_t *cmd, memory_t *env_mem)
{
    int pipefd[2];

    if (pipe(pipefd) == -1) {
        close(pipefd[0]);
        close(pipefd[1]);
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    cmd = fork_backtics(cmd, env_mem, pipefd);
    return cmd;
}

command_t *substitute_backtics(command_t *cmd, memory_t *env_mem)
{
    command_t *tmp = cmd;

    while (tmp) {
        if (tmp->type == BACKTIC && tmp->next && tmp->next->type <= BUILT_IN) {
            tmp = pipe_backtics(tmp, env_mem);
        }
        if (!tmp)
            return NULL;
        if (tmp->next)
            tmp = tmp->next;
        else
            break;
    }
    while (tmp->prev)
        tmp = tmp->prev;
    return tmp;
}
