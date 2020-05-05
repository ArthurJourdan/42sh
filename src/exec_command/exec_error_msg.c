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
            my_dprintf(2, "Floating exception\n");
            return true;
        } else if (status) {
            my_dprintf(2, "%s", strsignal(WTERMSIG(status)));
            if (WCOREDUMP(status))
                my_dprintf(2, " (core dumped)");
            my_dprintf(2, "\n");
            return true;
        }
    }
    return false;
}

bool after_exec_error_msg(char *comd)
{
    struct stat *info = malloc(sizeof(struct stat));

    stat(comd, info);
    if (errno == EACCES) {
        my_dprintf(2, "%s: Permission denied.\n", comd);
        if (info)
            free(info);
        return false;
    }
    if (errno == ENOEXEC)
        my_dprintf(2, "%s: Exec format error. Wrong Architecture.\n", comd);
    if (info)
        free(info);
    return false;
}

bool exec_error_msg(char *comd)
{
    int return_access = 0;

    return_access = access(comd, X_OK);
    if (return_access) {
        if (errno == 13) {
            my_dprintf(2, "%s: %s.\n", comd, strerror(errno));
        } else
            my_dprintf(2, "%s: Command not found.\n", comd);
    }
    return false;
}