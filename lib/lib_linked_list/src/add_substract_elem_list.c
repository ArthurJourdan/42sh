/*
** EPITECH PROJECT, 2019
** add_substract_elem_list.c
** File description:
** put or retire an element in a list
*/

#include "my.h"
#include "linked_list.h"

void substract_element(node_t **head)
{
    node_t *next_list = (*head)->next;

    *head = (*head)->prev;
    (*head)->next = next_list;
    next_list->prev = *head;
}

void add_element(node_t **head)
{
    node_t *next = (*head)->next;
    node_t *new = malloc(sizeof(node_t));

    new->nb = 0;
    new->next = (*head)->next;
    new->prev = *head;
    (*head)->next = new;
    next->prev = new;
}
