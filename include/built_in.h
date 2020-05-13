/*
** EPITECH PROJECT, 2020
** PSU_42sh
** File description:
** built_in.h
*/

#ifndef BUILT_IN_H
#define BUILT_IN_H

#include "my.h"

#include "parsing_command_line.h"

#define MAX_LEN_HISTORY (1000)

typedef struct {
    char **env;
    char **env_memory;
    char **aliases;
    char **history;
} memory_t;

typedef struct built_ins {
    char * const name;
    bool (*fct)(char **, memory_t *);
} built_ins_t;

enum built_in_index {
    NONE_BI = -1,
    CD,
    ENV,
    SETENV,
    UNSETENV
};

bool exec_built_ins(char *instructions, memory_t *env_mem, command_t *next);
int is_built_in(char *instructions);

// ENV
memory_t *init_env_memory(char **env);
void free_env_mem(memory_t *env_mem);

char **path_to_path_arr(memory_t *env_mem);

char *find_var_in_env(char * const var, char **env);

bool set_env(char **av, memory_t *env_m);
bool unset_env(char **av, memory_t *env_m);
bool disp_env(UNUSED char **av, memory_t *env_m);
// !ENV

// HISTORY
char *check_fill_history(char *line, memory_t *env_mem);

char *check_one_mark(char *line, char **history, size_t len_history);
char *check_two_marks(char *line, char **history, size_t len_history);
// ! HISTORY

// CD
bool change_location(char **av, memory_t *env_m);
// !CD

// ALIASES
char **get_aliases(void);
// ! ALIASES

// EXIT
bool my_exit(UNUSED char **av, memory_t *env_m);
// !EXIT

#endif /* !BUILT_IN_H */
