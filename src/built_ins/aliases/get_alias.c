/*
** EPITECH PROJECT, 2020
** PSU_42sh
** File description:
** get_alias.c
*/

#include "my.h"

#include "built_in.h"

static size_t count_old_aliases(alias_t **old_aliases)
{
    size_t len = 0;

    if (!old_aliases)
        return 0;
    while (old_aliases[len])
        len++;
    return len;
}

static alias_t *cpy_one_alias(alias_t *alias)
{
    alias_t *cpy = malloc(sizeof(alias_t));

    if (!cpy)
        return NULL;
    cpy->alias = my_strcpy(alias->alias);
    cpy->substitute = my_strcpy(alias->substitute);
    return cpy;
}

static alias_t **cpy_aliases(alias_t **aliases, size_t nb_aliases)
{
    alias_t **cpy = malloc(sizeof(alias_t *) * (nb_aliases + 2));

    if (!cpy)
        return NULL;
    for (size_t a = 0; a < nb_aliases; a++) {
        cpy[a] = cpy_one_alias(aliases[a]);
    }
    cpy[nb_aliases] = NULL;
    cpy[nb_aliases + 1] = NULL;
    return cpy;
}

static void register_alias(char **av, memory_t *env_m)
{
    alias_t **new_aliases = NULL;
    size_t nb_aliases = 0;

    nb_aliases = count_old_aliases(env_m->aliases);
    new_aliases = cpy_aliases(env_m->aliases, nb_aliases);
    new_aliases[nb_aliases] = fill_one_alias(av);
    free_aliases(env_m->aliases);
    env_m->aliases = new_aliases;
}

bool get_alias(char **av, memory_t *env_m)
{
    size_t ac = 0;

    if (!av)
        return false;
    ac = my_arrlen(av);
    if (ac == 1)
        display_aliases(env_m->aliases);
    if (ac == 2)
        return false;
    if (ac >= 3) {
        register_alias(av, env_m);
    }
    return false;
}