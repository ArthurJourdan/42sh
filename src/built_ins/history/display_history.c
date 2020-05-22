/*
** EPITECH PROJECT, 2020
** PSU_42sh
** File description:
** display_history.c
*/

#include "my.h"
#include "print.h"

#include "built_in.h"

static void disp_history_end(char **history, int end, bool count)
{
    ssize_t len_history = my_arrlen(history);
    ssize_t beg = my_arrlen(history) - end;

    if (beg < 0 || end == -1) {
        beg = 0;
    }
    for (; history[beg] && beg < len_history; beg++) {
        if (count) {
            my_dprintf(STDOUT_FILENO, "\t%i\t", beg + 1);
        }
        my_dprintf(STDOUT_FILENO, "%s\n", history[beg]);
    }
}

static void setup_options_history(char **av, memory_t *env_mem)
{
    size_t ac = my_arrlen(av);
    bool count = true;
    int end = -1;
    size_t pos_end = 1;

    if (ac == 1) {
        disp_history_end(env_mem->history, end, count);
        return;
    }
    if (my_strcmp("-h", av[1])) {
        count = false;
        pos_end++;
    }
    if (my_str_is_num(av[pos_end]))
        end = atoi(av[pos_end]);
    disp_history_end(env_mem->history, end, count);
}

bool display_history(char **av, memory_t *env_mem)
{
    if (error_handling_history(av, env_mem))
        return true;
    setup_options_history(av, env_mem);
    return false;
}