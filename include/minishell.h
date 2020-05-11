/*
** EPITECH PROJECT, 2020
** PSU_minishell2
** File description:
** minishell.h
*/

#ifndef MINISHELL_H
#define MINISHELL_H

#include "my.h"

#include "parsing_command_line.h"
#include "built_in.h"

bool minishell_manager(char **env);

// COMMAND
char *command_match(char **path_arr, char * const is_command);

bool check_direct_exec(char *command);

void set_pipes(int pipefd[2][2], command_t *command, int fst_or_sec);
void set_redirections(command_t *command);

bool command_exec(char *line, memory_t *env_mem);

bool check_command(command_t *pre_command, memory_t *env_mem);

bool exec_error_msg(char *comd);
bool after_exec_error_msg(char *comd);
bool understand_status(int status);

// !COMMAND

#endif /* !MINISHELL_H */
