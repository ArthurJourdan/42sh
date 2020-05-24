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

#define BONUS (false)

#define OUT 0
#define IN 1
#define IS_WHITESPACE(x) (x == ' ' || x == '\t' || x == '\n')

typedef struct wors_to_array
{
    int wc;
    char *str;
}word_t;

bool minishell_manager(char **env);

// COMMAND
char *command_match_one_path(char *path, char * const is_command);
char *command_match(char **path_arr, char * const is_command);

bool check_direct_exec(char *command);

// SEPARATORS
bool short_circuit_operators(int *status, command_t *tmp);
void set_pipes(int pipefd[2][2], command_t *command, int fst_or_sec);
void set_redirections(command_t *command);
void create_fd_redirect(char *line, char **fp);
// !SEPARATORS

void launch_command_parser(char *line, memory_t *env_mem);

// BACKTICKS
command_t *substitute_backticks(command_t *command, memory_t *env_mem);

command_t *add_cmd_from_backtick(command_t *command, int fd);

command_t *get_cmd_backtick(command_t *command);
command_t *remove_cmd_backtick(command_t *command);

// !BACKTICKS

bool command_exec(command_t *command, memory_t *env_mem);

char *get_command_path(char **instructions, memory_t *env_mem);

bool check_command(command_t *pre_command, memory_t *env_mem);

bool exec_error_msg(char * const cmd);
bool after_exec_error_msg(char *cmd);
bool understand_status(int status);
// !COMMAND

//GLOBBING
char *my_strdup(char const *src);
char *my_strcpy1(char *dest , char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char **my_str_to_word_array(char *str);
word_t countwords(char *str);
char *is_wildcard(char *cmd);
int *check_wildcard(char **newcmd);
//!GLOBBING

#endif /* !MINISHELL_H */
