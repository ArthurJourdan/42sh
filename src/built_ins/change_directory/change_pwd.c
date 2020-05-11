/*
** EPITECH PROJECT, 2020
** PSU_minishell2
** File description:
** change_pwd.c
*/

#include "my.h"
#include "print.h"
#include "file.h"

#include "minishell.h"
#include "built_in.h"

static void apply_oldpwd_on_memory(char **env)
{
    int line_old_pwd = get_index_word_begin_in_arr("OLDPWD=", env);
    char *buff = NULL;
    int arr_len = my_arrlen(env);

    if (line_old_pwd != -1) {
        *(env + line_old_pwd) = my_strcat_path("OLDPWD=", getcwd(buff, 0));
    } else {
        *(env + arr_len) = my_strcat_path("OLDPWD=", getcwd(buff, 0));
        *(env + arr_len + 1) = NULL;
    }
    free(buff);
}

static void apply_pwd_on_memory(char **env)
{
    int line_pwd = get_index_word_begin_in_arr("PWD=", env);
    char *buff = NULL;
    int arr_len = my_arrlen(env);

    if (line_pwd != -1) {
        *(env + line_pwd) = my_strcat_path("PWD=", getcwd(buff, 0));
    } else {
        *(env + arr_len) = my_strcat_path("OLDPWD=", getcwd(buff, 0));
        *(env + arr_len + 1) = NULL;
    }
    free(buff);
}

static int apply_change(char *location, memory_t *env_m)
{
    int line_pwd = get_index_word_begin_in_arr("PWD=", env_m->env);
    int line_old_pwd = get_index_word_begin_in_arr("OLDPWD=", env_m->env);
    char *buff = NULL;
    int ret_chdir = 0;

    if (line_old_pwd != -1) {
        env_m->env[line_old_pwd] = my_strcat_path("OLDPWD=", getcwd(buff, 0));
        buff = NULL;
    }
    apply_oldpwd_on_memory(env_m->env_memory);
    ret_chdir = chdir(location);
    if (line_pwd != -1) {
        *(env_m->env + line_pwd) = my_strcat_path("PWD=", getcwd(buff, 0));
        free(buff);
    }
    apply_pwd_on_memory(env_m->env_memory);
    if (ret_chdir)
        return errno;
    return 0;
}

static bool special_locations(char **av, memory_t *env_m)
{
    size_t command_len = my_arrlen(av);
    char *location = NULL;

    if (command_len == 1 || (command_len == 2 && my_strcmp(av[1], "~"))) {
        if (get_index_word_begin_in_arr("HOME=", env_m->env_memory) != -1)
            apply_change(find_var_in_env("HOME=", env_m->env_memory), env_m);
        else
            my_dprintf(1, "cd: No home directory.\n");
        return true;
    }
    if (command_len == 2)
        if (my_strcmp("-", *(av + 1))) {
            location = find_var_in_env("OLDPWD=", env_m->env_memory);
            apply_change(location, env_m);
            return true;
        }
    if (command_len > 2) {
        my_dprintf(2, "cd: Too many arguments.\n");
        return true;
    }
    return false;
}

bool change_location(char **av, memory_t *env_m)
{
    char *buff = NULL;
    char *pwd = getcwd(buff, 0);
    int ret_chdir = 0;

    if (special_locations(av, env_m))
        return true;
    else {
        if (pwd) {
            ret_chdir = apply_change(*(av + 1), env_m);
        }
        if (ret_chdir) {
            my_dprintf(2, "%s: %s.\n", *(av + 1), strerror(ret_chdir));
            free(buff);
            return true;
        }
    }
    free(buff);
    return false;
}
