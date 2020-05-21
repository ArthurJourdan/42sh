/*
** EPITECH PROJECT, 2020
** PSU_42sh
** File description:
** short_circuit_operators.c
*/

#include "my.h"

#include "built_in.h"

bool short_circuit_operators(int *status, command_t *tmp)
{
    if (tmp && tmp->type == DOUBLE_E) {
        if (*(status) != 0) {
            *(status) = 0;
            return false;
        }
    }
    if (tmp && tmp->type == DOUBLE_I) {
        if (!*(status)) {
            *(status) = 0;
            return false;
        }
    }
    return true;
}