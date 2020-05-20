/*
** EPITECH PROJECT, 2020
** PSU_minishell2
** File description:
** set_redirections.c
*/

#include "my.h"
#include "file.h"

#include "minishell.h"
#include "parsing_command_line.h"

static void set_redirection_to(command_t *tmp)
{
    int fd = -1;
    char **fp = NULL;

    if (!tmp->next)
        return;
    if (tmp->next->type == S_REDIRECT && tmp->next->next
    && tmp->next->next->type == MY_FILE) {
        fp = my_str_to_word_arr(tmp->next->next->instruction);
        if (fp) {
            fd = open(fp[0], O_CREAT | O_RDWR,
            S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
            free_double_char_arr(fp);
        }
        if (fd != -1) {
            if (dup2(fd, STDOUT_FILENO) == -1)
                exit(EXIT_FAILURE);
            close(fd);
        }
    }
}

static void set_redirection_from(command_t *tmp)
{
    int fd = -1;
    char **fp = NULL;

    if (!tmp->next)
        return;
    if (tmp->next->type == S_REDIRECT_IN && tmp->next->next
    && tmp->next->next->type == MY_FILE) {
        fp = my_str_to_word_arr(tmp->next->next->instruction);
        if (fp) {
            fd = open(fp[0], O_RDONLY);
            free_double_char_arr(fp);
        }
        if (fd != -1) {
            if(dup2(fd, STDIN_FILENO) == -1)
                exit(EXIT_FAILURE);
            close(fd);
        }
    }
}

static void set_double_redirection_to(command_t *tmp)
{
    int fd = -1;
    char **fp = NULL;

    if (!tmp->next)
        return;
    if (tmp->next->type == S_REDIRECT && tmp->next->next
    && tmp->next->next->type == MY_FILE) {
        fp = my_str_to_word_arr(tmp->next->next->instruction);
        if (fp) {
            fd = open(fp[0], O_CREAT | O_APPEND | O_RDWR, \
S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
            free_double_char_arr(fp);
        }
        if (fd != -1) {
            if (dup2(fd, STDOUT_FILENO) == -1)
                exit(EXIT_FAILURE);
            close(fd);
        }
    }
}

void set_redirections(command_t *command)
{
    command_t *tmp = command;

    set_redirection_to(tmp);
    set_redirection_from(tmp);
    set_double_redirection_to(tmp);
}