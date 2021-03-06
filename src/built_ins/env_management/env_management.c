/*
** EPITECH PROJECT, 2020
** PSUp_minishell1
** File description:
** env_management.c
*/

#include "my.h"
#include "file.h"
#include "print.h"

#include "built_in.h"

static const char *ERR1 = ": Too many arguments.\n";
static const char *ERR2 = ": Variable name must begin with a letter.\n";
static const char *ERR3 = ": Variable name must contain ";
static const char *ERR35 = "alphanumeric characters.\n";

static char **unset_env_var_and_val(char **av, char **env)
{
    size_t ac = my_arrlen(av);
    ssize_t line_var = 0;

    for (size_t a = 1; a <= ac; a++) {
        line_var = get_index_word_begin_in_arr(*(av + a), env);
        if (line_var != -1) {
            env = remove_str_to_arr(env, line_var, true);
        }
    }
    return env;
}

bool unset_env(char **av, memory_t *env_m)
{
    if (built_in_error_handling(av)) {
        return true;
    }
    env_m->env = unset_env_var_and_val(av, env_m->env);
    return false;
}

static bool set_env_error(size_t ac, char **av)
{
    if (ac > 3) {
        my_dprintf(STDERR_FILENO, "%s%s", av[0], ERR1);
        return true;
    }
    if (ac >= 2) {
        if (!my_char_is_alpha_num(*(*(av + 1)), true, false, true)) {
            my_dprintf(STDERR_FILENO, "%s%s", av[0], ERR2);
            return true;
        }
        if (!my_str_is_alphanum(*(av + 1))) {
            my_dprintf(STDERR_FILENO, "%s%s%s", av[0], ERR3, ERR35);
            my_dprintf(STDERR_FILENO, "");
            return true;
        }
    }
    return false;
}

static char **set_var_and_value_env(size_t ac, char **av, char **env)
{
    char *new_var = NULL;

    if (ac >= 2) {
        new_var = my_strcat(*(av + 1), "=", false, false);
        if (ac == 3)
            new_var = my_strcat(new_var, *(av + 2), true, false);
    }
    env = add_str_to_arr(env, new_var, true, true);
    return env;
}

bool set_env(char **av, memory_t *env_m)
{
    size_t ac = my_arrlen(av);

    if (ac == 1) {
        disp_env(NULL, env_m);
        return false;
    }
    if (set_env_error(ac, av))
        return true;
    if (get_index_word_begin_in_arr(*(av + 1), env_m->env) != - 1) {
        env_m->env = unset_env_var_and_val(av, env_m->env);
        env_m->env_memory = unset_env_var_and_val(av, env_m->env_memory);
    }
    env_m->env = set_var_and_value_env(ac, av, env_m->env);
    env_m->env_memory = set_var_and_value_env(ac, av, env_m->env_memory);
    return false;
}
