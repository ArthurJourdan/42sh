/*
** EPITECH PROJECT, 2019
** my_put_linked_list.c
** File description:
** display linked list
*/

#include "linked_list.h"
#include "print.h"

void my_put_linked_list(node_t *head)
{
    for (int i = 0; i < 9; i++) {
        my_dprintf(1, "%i, ", head->nb);
        head = head->next;
    }
    my_dprintf(1, "\n");
}
