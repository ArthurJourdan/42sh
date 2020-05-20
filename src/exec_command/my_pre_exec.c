/*
** EPITECH PROJECT, 2020
** PSU_minishell2
** File description:
** my_pre_exec.c
*/

#include "my.h"
#include "print.h"
#include "file.h"

#include "minishell.h"
#include "parsing_command_line.h"
#include "built_in.h"

static void separate_separators(command_t *command, memory_t *env_mem,
int pipefd[2][2], int fst_or_sec)
{
    int which_built_in = is_built_in(command->instruction);

    if (which_built_in == ENV || command->type != BUILT_IN) {
        set_pipes(pipefd, command, fst_or_sec);
        set_redirections(command);
    }
    if (!check_command(command, env_mem)) {
        exit(0);
    }
}

static void forking_pipes(command_t *tmp, memory_t *env_mem, \
int pipefd[2][2], int fst_or_sec)
{
    int status = 0;
    pid_t my_pid = -1;
    int built_in = is_built_in(tmp->instruction);

    if (tmp->type != BUILT_IN || built_in == ENV)
        my_pid = fork();
    if (my_pid == -1 && tmp->type != BUILT_IN) {
        return;
    } else if (my_pid == 0 || (tmp->type == BUILT_IN && built_in != ENV)) {
        separate_separators(tmp, env_mem, pipefd, fst_or_sec);
    } else {
        if (tmp->next && tmp->next->type == SIMPLE_I)
            close(pipefd[fst_or_sec][1]);
        if (tmp->prev && tmp->prev->type == SIMPLE_I)
            close(pipefd[invert_int(fst_or_sec)][0]);
        waitpid(my_pid, &status, 0);
        understand_status(status);
    }
}

static bool init_pipes(command_t *tmp, memory_t *env_mem)
{
    static int pipefd[2][2] = {{-1, -1}, {-1, -1}};
    static int fst_or_sec = 0;

    if (pipe(pipefd[fst_or_sec]) == -1) {
        close(pipefd[fst_or_sec][0]);
        close(pipefd[fst_or_sec][1]);
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    forking_pipes(tmp, env_mem, pipefd, fst_or_sec);
    fst_or_sec = invert_int(fst_or_sec);
    return true;
}

static void launch_separators(command_t *command, memory_t *env_mem)
{
    command_t *tmp = command;

    while (tmp && tmp->type != SEMICOLON) {
        if (tmp->type == BUILT_IN && tmp->next && tmp->next->type == SIMPLE_I
        && is_built_in(tmp->instruction) != ENV) {
            tmp = tmp->next;
            continue;
        }
        if (tmp->type == COMMAND || tmp->type == BUILT_IN) {
            if (!init_pipes(tmp, env_mem))
                return;
        }
        tmp = tmp->next;
    }
}

bool command_exec(char *line, memory_t *env_mem)
{
    command_t *command = my_command_parser(line);

    if (!command)
        return false;
    while (command) {
        launch_separators(command, env_mem);
        while (command) {
            command = command->next;
            if (command && command->prev && command->prev->type == SEMICOLON)
                break;
        }
    }
    free_command(command);
    return true;
}