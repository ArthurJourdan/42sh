/*
** EPITECH PROJECT, 2019
** linked_list.h
** File description:
** init and manage linked lists
*/

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

typedef struct node {
    int nb;
    struct node *prev;
    struct node *next;
} node_t;

node_t *init_linked_list(int ac, char **av);

void my_put_linked_list(node_t *head);

void swap_lists(node_t **head, int ac);

void substract_element(node_t **head);
void add_element(node_t **head);

void rotate_first_become_last(node_t **head);
void rotate_last_become_first(node_t **head);

#endif /*LINKED_LIST_H_*/
