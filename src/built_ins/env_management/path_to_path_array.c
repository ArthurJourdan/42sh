/*
** EPITECH PROJECT, 2020
** PSU_42sh
** File description:
** path_to_path_arr.c
*/

#include "my.h"
#include "file.h"

#include "built_in.h"

static char * const PATH = "PATH=";
static char * SECURE_PATH[] = {
    "/usr/local/sbin:",
    "/usr/local/bin:",
    "/usr/sbin:",
    "/usr/bin:",
    "/sbin:",
    "/bin:",
    "/snap/bin",
    NULL
};

static char *init_secure_path(void)
{
    char *secure_path = NULL;

    for (size_t a = 0; SECURE_PATH[a]; a++) {
        secure_path = my_strcat(secure_path, SECURE_PATH[a], true, false);
    }
    return secure_path;
}

static char *init_env_path(char **env_memory)
{
    char *env_path = NULL;

    env_path = find_var_in_env(PATH, env_memory);
    if (!env_path) {
        env_path = init_secure_path();
        if (!env_path) {
            return NULL;
        }
    }
    return env_path;
}

char **path_to_path_arr(memory_t *env_mem)
{
    char *env_path = NULL;
    char **paths = NULL;

    env_path = init_env_path(env_mem->env_memory);
    if (!env_path) {
        return NULL;
    }
    paths = my_sep_parser(env_path, ":");
    if (!paths) {
        free_char_to_null(env_path);
        return NULL;
    }
    replace_char_in_arr(paths, ':', '\0');
    free_char_to_null(env_path);
    return paths;
}
