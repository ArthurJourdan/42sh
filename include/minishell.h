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

typedef struct {
    char **env;
    char **env_memory;
} env_memory_t;

typedef struct built_ins {
    char * const name;
    bool (*fct)(char **, env_memory_t *);
} built_ins_t;

enum built_in_index {
    NONE_BI = -1,
    CD,
    ENV,
    SETENV,
    UNSETENV
};

bool minishell_manager(char **env);

// BUILT INS
bool exec_built_ins(char *instructions, env_memory_t *env_mem, command_t *next);
int is_built_in(char *instructions);

// ENV
env_memory_t *init_env_memory(char **env);
void free_env_mem(env_memory_t *env_mem);

char **path_to_path_arr(env_memory_t *env_mem);

char *find_var_in_env(char * const var, char **env);

bool set_env(char **av, env_memory_t *env_m);
bool unset_env(char **av, env_memory_t *env_m);
bool disp_env(UNUSED char **av, env_memory_t *env_m);
// !ENV

// CD
bool change_location(char **av, env_memory_t *env_m);
// !CD

// EXIT
bool my_exit(UNUSED char **av, env_memory_t *env_m);
// !EXIT

// !BUILT INS

// COMMAND
char *command_match(char **path_arr, char * const is_command);

bool check_direct_exec(char *command);

void set_pipes(int pipefd[2][2], command_t *command, int fst_or_sec);
void set_redirections(command_t *command);

bool command_exec(char *line, env_memory_t *env_mem);

bool check_command(command_t *pre_command, env_memory_t *env_mem);

bool exec_error_msg(char *comd);
bool after_exec_error_msg(char *comd);
bool understand_status(int status);

// !COMMAND

#endif /* !MINISHELL_H */
