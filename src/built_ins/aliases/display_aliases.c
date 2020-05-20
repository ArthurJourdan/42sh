/*
** EPITECH PROJECT, 2020
** PSU_42sh
** File description:
** display_aliases.c
*/

#include "print.h"

#include "built_in.h"

void display_aliases(alias_t **aliases)
{
    if (!aliases)
        return;
    for (size_t a = 0; aliases[a]; a++) {
        my_dprintf(1, "%s", aliases[a]->alias);
        my_dprintf(1, "\t%s\n", aliases[a]->substitute);
    }
}