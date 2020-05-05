/*
** EPITECH PROJECT, 2019
** display error message
** File description:
** check if first arg is -h or inexistant
*/

#include "my.h"
#include "print.h"

bool error_msg(int ac, char **av)
{
    if (ac == 1) {
        my_dprintf(2, "type -h for help\n");
        return false;
    }
    if (ac = 2)
        if (my_strcmp("-h", av[1])) {
            my_dprintf(2, "USAGE\n");

            my_dprintf(2, "DESCRIPTION\n");

            return false;
        }
    return true;
}
