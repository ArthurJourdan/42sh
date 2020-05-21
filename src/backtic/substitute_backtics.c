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

/* {
    fork
    pipefd
    if (child) {
        dup2(STDOUT, pipefd[1]);
        close
        recursion {
            command_exec()//que ce qu'il y a dans les backtic
            exit();
        }
    } else if (dad)
        line = inclut_pipfd_dans_line(line, pipefd[0]);// ls `ls` == ls Makefile 42sh lib
} */

static void parent_process(command_t *command, pid_t my_pid, int pipefd[2])
{
    close(pipefd[1]);
    command = remove_cmd_backtick(command);
    waitpid(my_pid, NULL, 0);
    // use pipefd[0] to update new command;
}

static void child_process(command_t *command, memory_t *env_mem, int pipefd[2])
{
    dup2(STDOUT_FILENO, pipefd[1]);
    close(pipefd[1]);
    close(pipefd[0]);
    command = get_cmd_backtick(command);
    command_exec(command, env_mem);
    exit(EXIT_SUCCESS);
}

static void fork_backtics(command_t *command, memory_t *env_mem, int pipefd[2])
{
    pid_t my_pid = -1;

    my_pid = fork();
    if (my_pid == -1) {
        return;
    } else if (my_pid == 0) {
        child_process(command, env_mem, pipefd);
    } else {
        parent_process(command, my_pid, pipefd);
    }
}

static void pipe_backtics(command_t *command, memory_t *env_mem)
{
    int pipefd[2];

    if (pipe(pipefd) == -1) {
        close(pipefd[0]);
        close(pipefd[1]);
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    fork_backtics(command, env_mem, pipefd);
}

void substitute_backtics(command_t *command, memory_t *env_mem)
{
    command_t *tmp = command;

    while (tmp) {
        if (tmp->type == BACKTIC && tmp->next && tmp->next->type <= BUILT_IN) {
            pipe_backtics(tmp, env_mem);
        }
        tmp = tmp->next;
    }
}