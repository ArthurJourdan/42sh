/*
** EPITECH PROJECT, 2020
** quote_error.c
** File description:
** yolo
*/

#include "my.h"
#include "print.h"

char *quote_error(char *line)
{
    int count = 0;
    int count2 = 0;

    for (int i = 0; line[i] != '\0' ; i++) {
        if (line[i] == '"')
            count++;
        if (line[i] == '\'')
            count2++;
        if ((count2 == 2 && count == 0) || (count == 2 && count2 == 0)) {
            count2 = 0;
            count = 0;
        }
        if (count == 1 && count2 == 1) {
            my_dprintf(STDOUT_FILENO, "Unmatched \'%c\'.\n", line[i]);
            free_char_to_null(line);
            return NULL;
        }
    }
    return line;
}