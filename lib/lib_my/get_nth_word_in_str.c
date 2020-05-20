/*
** EPITECH PROJECT, 2020
** my_lib
** File description:
** get_nth_word_in_str.c
*/

#include "my.h"
#include "print.h"

/* have to check the number of quotes: if odd: bug */

static bool advance_pos(char * const str, size_t *pos)
{
    char tmp_quote = '\0';

    if (str[*(pos)] == '\"' || str[*(pos)] == '\'') {
        tmp_quote = str[*(pos)];
        *(pos) += 1;
        while (str[*(pos)] && str[*(pos)] != tmp_quote) {
            *(pos) += 1;
        }
        *(pos) += 1;
        return true;
    }
    if (str[*(pos)] <= ' ') {
        while (str[*(pos)] && str[*(pos)] <= ' ') {
            *(pos) += 1;
        }
        return true;
    }
    return false;
}

static size_t get_pos_nth_word(char * const str, size_t n)
{
    size_t pos = 0;
    size_t word = 1;

    while(str[pos] <= ' ')
        pos++;
    while (str[pos]) {
        if (word == n)
          return pos;
        if (advance_pos(str, &pos)) {
            word++;
        } else {
            pos++;
        }
    }
    return pos;
}

static size_t get_lenght_word(char * const str, size_t pos)
{
    size_t lenght_word = 0;
    char begining = '\0';

    if (pos > 0 && str[pos - 1] > ' ')
        begining = str[pos - 1];
    while (str[pos]) {
        if (!begining && str[pos] <= ' ') {
            return lenght_word;
        }
        if (str[pos] == begining)
            return lenght_word;
        pos++;
        lenght_word++;
    }
    return lenght_word;
}

char *get_nth_word_in_str(char * const str, size_t n)
{
    char *nth_word = NULL;
    size_t pos = get_pos_nth_word(str, n);
    size_t len = get_lenght_word(str, pos);

    nth_word = my_str_n_cpy(str + pos, len);
    return nth_word;
}