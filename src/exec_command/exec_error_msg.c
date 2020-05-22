/*
** EPITECH PROJECT, 2020
** PSU_minishell2
** File description:
** exec_error_message.c
*/

#include "my.h"
#include "print.h"
#include "file.h"

#include "minishell.h"

bool understand_status(int status)
{
    if (WIFSIGNALED(status) && !WIFEXITED(status)) {
        if (status == 8) {
            my_dprintf(STDERR_FILENO, "Floating exception\n");
            return true;
        } else if (status) {
            my_dprintf(STDERR_FILENO, "%s", strsignal(WTERMSIG(status)));
            if (WCOREDUMP(status))
                my_dprintf(STDERR_FILENO, " (core dumped)");
            my_dprintf(STDERR_FILENO, "\n");
            return true;
        }
    }
    return false;
}

bool after_exec_error_msg(char * const cmd)
{
    struct stat *info = malloc(sizeof(struct stat));

    stat(cmd, info);
    if (errno == EACCES) {
        my_dprintf(STDERR_FILENO, "%s: Permission denied.\n", cmd);
        if (info)
            free(info);
        return false;
    }
    if (errno == ENOEXEC) {
        my_dprintf(STDERR_FILENO, "%s: Exec format error. ", cmd);
        my_dprintf(STDERR_FILENO, "Wrong Architecture.\n");
    }
    if (info)
        free(info);
    return false;
}

static void display_cmd_not_found(char *cmd)
{
    my_dprintf(STDERR_FILENO, "%s: Command not found.\n", cmd);
}

bool exec_error_msg(char * const cmd)
{
    int return_access = 0;

    return_access = access(cmd, X_OK);
    if (return_access) {
        if (errno == 13) {
            my_dprintf(STDERR_FILENO, "%s: %s.\n", cmd, strerror(errno));
        } else
        display_cmd_not_found(cmd);
    } else
        display_cmd_not_found(cmd);
    return false;
}