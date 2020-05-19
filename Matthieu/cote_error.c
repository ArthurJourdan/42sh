/*
** EPITECH PROJECT, 2020
** cote_error.c
** File description:
** yolo
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

static char *get_one_line(void)
{
    char *line = NULL;
    size_t zero = 0;

    if (getline(&line, &zero, stdin) == -1)
        return NULL;
    return line;
}

char *cote_error(char *line)
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
            my_putstr("Unmatched ");
            my_putchar(line[i]);
            my_putchar('\n');
            return NULL;
        }
    }
    return line;
}

int main(int ac, char **av)
{
    char *line;
    line = get_one_line();
    line = cote_error(line);
    if (line == NULL)
        printf("MERDE\n");
    else
        printf("YES\n");
}