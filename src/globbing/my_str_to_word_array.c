/*
** EPITECH PROJECT, 2020
** MINISHELL
** File description:
** str_to _word_array.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "minishell.h"

void *my_memset(void *ptr, int x, size_t n)
{
    char *p = (char *)ptr;
    while (n--)
        *p++= x;
    return ptr;
}

void *my_calloc(int num, size_t size)
{
    size_t count = num * size;
    void *ptr = malloc(count);
    if (!ptr)
        return NULL;
    return (my_memset(ptr, 0, count));
}

char *re_alloc(char *word, int size)
{
    char *temp = (char *)my_calloc((size + 1), sizeof(char));
    my_strncpy(temp, word, size);
    free(word);
    word = (char *)my_calloc((size + 2), sizeof(char));
    my_strncpy(word, temp, size);
    free(temp);
    return word;
}

word_t countwords(char *str)
{
    int state = OUT;
    int wc = 0;
    int i = 0;
    word_t count;

    while (str[i] != '\0') {
        if (IS_WHITESPACE(str[i]) || str[i] == ':') {
            str[i] = ':';
            state = OUT;
        }
        else if (state == OUT) {
            state = IN;
            ++wc;
        }
        i++;
    }
    count.wc = wc;
    count.str = str;
    return count;
}

char **my_str_to_word_array(char *str)
{
    word_t count = countwords(str);
    char **dest = malloc(sizeof(char *) * (count.wc + 1));
    int size = 2;
    int j = 0;
    int i = 0;
    int t = 0;
    int check = 0;
    dest[count.wc] = NULL;
    for (; t < count.wc; t++)
        dest[t] = (char *)my_calloc(size, sizeof(char));
    for (t = 0; count.str[i] != '\0'; i++) {
        if (count.str[i] != ':') {
            check += 1;
            dest[j][t++] = count.str[i];
            dest[j] = re_alloc(dest[j], t);
        } if (count.str[i] == ':' && count.str[i + 1] != ':')
            (check == 0) ? j = 0, t = 0 : j++, t = 0;
        else if (count.str[i] == ':' && count.str[i + 1] == ':')
            t = 0;
    } return dest;
}
