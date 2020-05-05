/*
** EPITECH PROJECT, 2019
** swap_two_elements.c
** File description:
** swap positions in a list
*/

#include "linked_list.h"
#include "my.h"

void swap_lists(node_t **head, int ac)
{
    node_t *second = (*head)->next;
    int inter = 0;

    inter = (*head)->nb;
    (*head)->nb = second->nb;
    second->nb = inter;
}

void rotate_first_become_last(node_t **head)
{
    *head = (*head)->next;
}

void rotate_last_become_first(node_t **head)
{
    *head = (*head)->prev;
}
