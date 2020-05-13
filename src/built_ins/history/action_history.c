/*
** EPITECH PROJECT, 2020
** PSU_42sh
** File description:
** action_history.c
*/

#include "my.h"

#include "minishell.h"
#include "parsing_command_line.h"
#include "built_in.h"

static char *compare_history(char * const command, char **history,
size_t len_history)
{
    size_t len = my_strlen(command);

    for (ssize_t a = len_history; a >= 0; a--) {
        if (my_str_n_cmp(command, history[a], len)) {
            return my_strcpy(history[a]);
        }
    }
    return NULL;
}

char *check_one_mark(char *line, char **history, size_t len_history)
{
    char **tmp_cmd = my_str_to_word_arr(line);
    char *replace = NULL;

    if (tmp_cmd[0][0] == '!' && tmp_cmd[0][1] && tmp_cmd[0][1] != '!') {
        replace = compare_history(tmp_cmd[0] + 1, history, len_history);
        if (replace) {
            free(tmp_cmd[0]);
            tmp_cmd[0] = replace;
            free(line);
            line = my_word_arr_to_str(tmp_cmd);
            free_double_char_arr(tmp_cmd);
            my_dprintf(1, "%s", line);
        }
    }
    return line;
}

char *check_two_marks(char *line, char **history, size_t len_history)
{
    char **tmp_cmd = my_str_to_word_arr(line);

    if (my_str_n_cmp(tmp_cmd[0], "!!", 2)) {
        free(tmp_cmd[0]);
        tmp_cmd[0] = my_strcpy(history[len_history]);
        free(line);
        line = my_word_arr_to_str(tmp_cmd);
    }
    free_double_char_arr(tmp_cmd);
    return line;
}