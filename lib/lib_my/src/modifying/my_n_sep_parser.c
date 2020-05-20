/*
** EPITECH PROJECT, 2020
** my_lib
** File description:
** my_n_sep_paser.c
*/

#include "my.h"
#include "file.h"

static int count_occurrences_seps(char *str, char **seps)
{
    size_t nb_words = 0;

    nb_words = count_occurences_n_words_in_str(seps, str);
    nb_words++;
    return nb_words;
}

static size_t get_next_sep(char * const str, char **seps, size_t pos_in_str)
{
    size_t nearest_sep = 0;
    ssize_t nearest_dist_sep = -1;
    ssize_t act_dist_sep = -1;

    for (size_t a = 0; seps[a]; a++) {
        act_dist_sep = get_pos_word_in_str(seps[a], str + pos_in_str);
        if (act_dist_sep < nearest_dist_sep && act_dist_sep != -1) {
            nearest_sep = a;
            nearest_dist_sep = act_dist_sep;
        } else if (act_dist_sep != -1 && nearest_dist_sep == -1) {
            nearest_sep = a;
            nearest_dist_sep = act_dist_sep;
        }
    }
    return nearest_sep;
}

static char *fill_word_arr(char * const str, char **seps, size_t *pos_in_str)
{
    char *act_word = NULL;
    ssize_t nearest_sep = get_next_sep(str, seps, *(pos_in_str));

    if (nearest_sep == -1) {
        act_word = my_strcpy(str + *(pos_in_str));
    } else {
        act_word = my_str_cpy_until_str(str + *(pos_in_str), seps[nearest_sep]);
    }
    *(pos_in_str) += my_strlen(act_word) + my_strlen(seps[nearest_sep]);
    return act_word;
}

static char **my_seps_parser(char * const str, char **seps, size_t nb_words)
{
    size_t pos_in_str = 0;
    char **word_arr = NULL;
    char *act_word = NULL;

    for (size_t which_arr = 0; which_arr < nb_words; which_arr++) {
        act_word = fill_word_arr(str, seps, &pos_in_str);
        word_arr = add_str_to_arr(word_arr, act_word, true, true);
    }
    return word_arr;
}

char **my_n_sep_parser(char * const str, char **seps)
{
    char **word_arr = NULL;
    size_t nb_words = 0;

    if (!str || !seps)
        return NULL;
    nb_words = count_occurrences_seps(str, seps);
    // if (!nb_words)
        // return NULL;
    word_arr = my_seps_parser(str, seps, nb_words);
    return word_arr;
}