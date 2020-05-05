/*
** EPITECH PROJECT, 2019
** init_linked_list.c
** File description:
** trials
*/

#include "my.h"
#include "linked_list.h"

static void link_first_to_last(node_t **head, int ac)
{
    node_t *final = *head;

    for (int i = 1; i < ac; i++) {
        *head = (*head)->prev;
    }
    (*head)->prev = final;
    final->next = *head;
}

static void filling(node_t **head, int ac, char **av)
{
    node_t *futur;

    for (int i = 1; i < ac; i++) {
        futur = malloc(sizeof(node_t));
        futur->nb = my_getnbr(av[i]);
        futur->prev = *head;
        (*head)->next = futur;
        *head = futur;
    }
    (*head)->next = NULL;
}

static void add_element_list(node_t **head, int nbr)
{
    node_t *prev = (*head)->prev;
    node_t *new = malloc(sizeof(node_t));

    new->nb = nbr;
    new->prev = (*head)->prev;
    new->next = *head;
    (*head)->prev = new;
    prev->next = new;
}

node_t *init_linked_list(int ac, char **av)
{
    node_t *head = malloc(sizeof(node_t));

    head->nb = my_getnbr(av[0]);
    head->prev = head;
    head->next = head;
    for (int i = 1; i < ac; i++) {
        add_element_list(&head, my_getnbr(av[i]));
    }
    return head;
}
